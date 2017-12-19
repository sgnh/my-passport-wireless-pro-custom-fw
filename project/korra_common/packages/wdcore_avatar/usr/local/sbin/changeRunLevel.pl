#!/usr/bin/perl

# 
# This perl script is responsible for changing the run-level.
#
# To invoke this script execute the following:
# >>    changeRunLevel.pl --help
#
# Copyright (c) [2012] Western Digital Technologies, Inc. All rights reserved.
#
# Version - 1.2
#
# History:
# 1.2 - Renamed "vft" run level 5 to "minimal" 
#       
# 1.1 - Removed transition from INIT -> VFT runlevel while VFT runlevel 
#       support is temporarily disabled
#
# 1.0 - Initial version
#

#
# --- Design Notes:

# This script shall invoke the following command to change run-level
# 
# telinit <runlevel>
# 

our $VERSION = '1.2';

# --- Common Includes
use strict;
use warnings;

# CPAN Library Includes

# --- WDPerlLib Includes 
use WDPerlLib::Common::WDStdLib;
use WDPerlLib::Common::WDStatus;
use WDPerlLib::Common::WDStdDefs;
use WDPerlLib::Logger::WDLogger;
use WDPerlLib::Property::PropertyContainerFactory;

# --- Global Constants

my $SYSTEM_CONF      = "/etc/system.conf"   ;
my $PACKAGE_NAME_VAR = "master_package_name";
my $RUNLEVELS_SUPPORTED_VAR = "runlevels_supported";
my $PACKAGE_APNC     = "\"apnc\""           ; ## note the quotes ("")
my $PACKAGE_AP2NC    = "\"ap2nc\""          ; ## note the quotes ("")
my $DELAY            = 2                    ; ## 2 seconds

## Input Arguments Names
my $VERSION_OPT = "--version";
my $HELP_OPT    = "--help"   ;
my $LEVEL_OPT   = "--level" ;

## Input Arguments Default Values
## NB: used if not provided on command line
my $VERSION_DFLT = $NO_VALUE;
my $HELP_DFLT    = $NO_VALUE;
my $LEVEL_DFLT   = $MANDATORY_VALUE;

## Input Arguments Variables (Properties)
my %prop = ( version => $VERSION_DFLT,
             help    => $HELP_DFLT   ,
             level   => $LEVEL_DFLT  ,
           );
                
# --- Instance Variables

my $stdlib;
my $logger;
my $runlevels_supported;

## run-levels supported
my %LEVELS_SUPPORTED = ( "init"      => 1,
                         "app"       => 2, 
                         "admin"     => 3,
                         "emergency" => 4,
                         "minimal"   => 5,
                       );

# run-levels transitions allowed
my %TRANSITIONS = ( "init"      => [ "app", "admin", "emergency", "minimal" ],
                    "app"       => [ "admin", "emergency" ],
                    "emergency" => [ "app" ],
                  );

# --- Main script
{
    ## local variables
    my %array ;
    my %status;
    my $key   ;
    my $str   ;

    ## get instance of logger
    $logger = WDPerlLib::Logger::WDLogger->GetInstance() || die();

    ## get instance of WDStdLib
    $stdlib = WDPerlLib::Common::WDStdLib->GetInstance() || die();

    ## handle only single --help argument
    if( ( @ARGV == 1 ) )
    {
        if( $ARGV[0] eq $HELP_OPT ) 
        {
            hHelpGen();
            exit( 0 );
        }

        if( $ARGV[0] eq $VERSION_OPT ) 
        {
            hVersion();
            exit( 0 );
        }
    }

    ## init the input options --name=value associative array
    foreach $key( keys( %prop ) )
    {
        $array{"\-\-$key"} = \$prop{$key};
    }

    ## load the input arguments into corresponding properties
    %status = $stdlib->LoadCommandArgs( \@ARGV, \%array );
    goto cleanup if( $status{code} != $WDST_OK );

    ## valchk mandatory arguments
    %status = mValchkArgs();
    goto cleanup if( $status{code} != $WDST_OK );

    ## init global variables
    %status = mInitVars();
    goto cleanup if( $status{code} != $WDST_OK );

    ## exit if run-levels are not supported
    if( $runlevels_supported == $FALSE ) 
    {
        $status{code} = $WDST_NOTSUPPORTED;
        $status{desc} = "NAS Run-levels are not supported";
        $logger->Error( $status{desc} );
        goto cleanup;
    }

    ## check if run-level change is allowed
    %status = mCheckPermission();
    goto cleanup if( $status{code} != $WDST_OK );

    ## change the run-level
    %status = mChangeRunLevel();
    goto cleanup if( $status{code} != $WDST_OK );

    ## exit with success
    exit( 0 );

cleanup:

    ## report failure
    hPrintFailure( %status );

    ## exit with failure
    exit( $status{code} );
} # --- End of Main


# --- Sub routines (Methods)


sub mValchkArgs
{
    ## local variables
    my %args  ;
    my %status;

    ## fail if the level is unsupported
    if( ! grep( m/\b$prop{level}\b/, keys( %LEVELS_SUPPORTED ) ) )
    {
        $status{code} = $WDST_NOTSUPPORTED;
        $status{desc} = "Level \'$prop{level}\' is not supported"; 
        $logger->Error( $status{desc} );
        return( %status );
    }

    ## return ok
    $status{code} = $WDST_OK;
    $status{desc} = ""; 
    return( %status );
}

sub mInitVars
{
    ## local variables
    my $system_ctr;
    my $pkg_name  ;
    my $prop_fac  ;
    my %status    ;

    ## get instance of PropertyContainerFactory
    $prop_fac = WDPerlLib::Property::PropertyContainerFactory->GetInstance();

    ## create the property container for the system.conf
    $system_ctr = $prop_fac->GetContainer( file => $SYSTEM_CONF );
    if ( ! defined $system_ctr )
    {
        $status{code} = $WDST_FAILED;
        $status{desc} = "Failed to load $SYSTEM_CONF";
        $logger->Error( $status{desc} );
        goto cleanup;
    }

    ## get the package name
    $pkg_name = $system_ctr->Get( prop_name => $PACKAGE_NAME_VAR );
    $runlevels_supported = $TRUE;

    ## return ok
    $status{code} = $WDST_OK;
    $status{desc} = ""; 
    return ( %status );
cleanup:

    return ( %status );
}

sub mCheckPermission
{
    ## local variables
    my %args        ;
    my $new_level   ;
    my $cmd         ;
    my $curr_level  ;
    my @allowed_rls ;
    my %status      ;

    ## init
    $new_level = $prop{level};

    ## debug
    $logger->Debug( "Checking if system can change to target run-level" );

    ## get current run-level
    $curr_level = 0;
    $cmd = "getRunLevel.pl";
    $curr_level = $stdlib->RunCommand( $cmd );
    if( ! defined $curr_level || ! $curr_level )
    {
        $status{code} = $WDST_FAILED;
        $status{desc} = "Failed to get current run-level";
        $logger->Error( $status{desc} );
        goto cleanup;
    }
    
    ## get the list of allowed transitions
    if( defined $TRANSITIONS{$curr_level} )
    {
        @allowed_rls = @{ $TRANSITIONS{$curr_level} };
    }

    ## fail if current run-level is permanent
    if( ! @allowed_rls )
    {
        $status{code} = $WDST_FAILED;
        $status{desc} = "Current Run-level \"$curr_level\" is permanent";
        $logger->Error( $status{desc} );
        goto cleanup;
    }

    ## fail if transition is not allowed
    if ( ! grep { $_ eq $new_level } @allowed_rls )
    {
        $status{code} = $WDST_FAILED;
        $status{desc} = 
            "Cannot change from run-level \"$curr_level\" -> \"$new_level\"";
        $logger->Error( $status{desc} );
        goto cleanup;
    }

    ## return ok
    $status{code} = $WDST_OK;
    $status{desc} = ""; 
    return( %status );

cleanup:

    return( %status );
}

sub mChangeRunLevel
{
    ## local variables
    my %args    ;
    my $level_no;
    my $level   ;
    my $cmd     ;
    my $ret     ;
    my %status  ;

    ## init
    $level = $prop{level};
    $level_no = $LEVELS_SUPPORTED{$level};

    ## debug
    $logger->Debug( "Changing system run-level to $level" );

    ## init command to change run-level
    $cmd = "telinit $level_no";
    $ret = $stdlib->ExecCommand( $cmd );
    if( $ret != $WDST_OK )
    {
        $status{code} = $WDST_FAILED;
        $status{desc} = "Failed to change the system run-level ".
                        "using command \"$cmd\"";
        $logger->Error( $status{desc} );
        goto cleanup;
    }
    
    ## debug
    $logger->Info( "Successfully changed system run-level to $level" );

    ## return ok
    $status{code} = $WDST_OK;
    $status{desc} = ""; 
    return( %status );

cleanup:

    return( %status );
}

# --- Sub routines (Helpers)

sub hVersion
{
    print( "\n" );
    print( "WD Change Run-Level:" );
    print( "\n" );
    print( "Version: $VERSION" );
    print( "\n" );
    print( "\n" );
}

sub hHelpGen
{
    print( "\n" );
    print( "Description:" );
    print( "\n" );
    print( "WD Change Run-Level:" );
    print( "\n" );
    print( "\n" );
    print( "Usage:" );
    print( "\n" );
    print( "changeRunLevel.pl --level=[app | admin | emergency | minimal]" );
    print( "\n" );
    print( "\n" );
}

sub hPrintFailure
{
    ## local variables
    my %args;
    my $str ;

    ## pass all input arguments
    %args = @_;

    ## print failure status
    $str = "Status(".$args{code}."): ".Stat2Str( $args{code} )."; $args{desc}";
    $stdlib->Error( $str );

    ## print help
    hHelpGen();

    return( $WDST_OK );
}
