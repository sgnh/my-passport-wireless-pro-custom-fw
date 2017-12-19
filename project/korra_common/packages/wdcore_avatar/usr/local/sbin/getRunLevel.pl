#!/usr/bin/perl

# 
# This perl script is responsible for determining the current run-level.
#
# To invoke this script execute the following:
# >>    getRunLevel.pl --help
#
# Copyright (c) [2012] Western Digital Technologies, Inc. All rights reserved.
#
# Version - 1.1.0
#
# History:
# 1.1.0 - Add minimal run level (5)
# 1.0.0 - Initial version
#

#
# --- Design Notes:

# This script shall invoke the following command to get the run-level
# 
# runlevel
# 

our $VERSION = '1.1.0';

# --- Common Includes
use strict;
use warnings;

# CPAN Library Includes

# --- WDPerlLib Includes 
use WDPerlLib::Common::WDStdLib;
use WDPerlLib::Common::WDStatus;
use WDPerlLib::Common::WDStdDefs;
use WDPerlLib::Logger::WDLogger;

# --- Global Constants

## Input Arguments Names
my $VERSION_OPT = "--version";
my $HELP_OPT    = "--help"   ;
my $MODE_OPT    = "--mode"   ;

## Input Arguments Default Values
## NB: used if not provided on command line
my $VERSION_DFLT = $NO_VALUE;
my $HELP_DFLT    = $NO_VALUE;
my $MODE_DFLT    = $MANDATORY_VALUE;

## Input Arguments Variables (Properties)
my %prop = ( version => $VERSION_DFLT,
             help    => $HELP_DFLT   ,
             mode    => $MODE_DFLT,
           );
                
# --- Instance Variables

my $stdlib;
my $logger;
my $runlevels_supported;

## run-levels supported
my %LEVELS_SUPPORTED = ( 1 => "init"     ,
                         2 => "app"      , 
                         3 => "admin"    ,
                         4 => "emergency",
                         5 => "minimal"      ,
                       );

# --- Main script
{
    ## local variables
    my $cmd    ;
    my $curr_rl;
    my %status ;

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

    ## get current run-level
    $cmd = "runlevel | awk \'\{ print \$2 \}\'";
    $curr_rl = $stdlib->RunCommand( $cmd );
    if( ! defined $curr_rl || ! $curr_rl )
    {
        $status{code} = $WDST_FAILED;
        $status{desc} = "Failed to get current run-level";
        $logger->Error( $status{desc} );
        goto cleanup;
    }
    
    ## print level to stdout
    print STDOUT ( $LEVELS_SUPPORTED{$curr_rl} );
    print STDOUT ( "\n" );

    ## exit with success
    exit( 0 );

cleanup:

    ## report failure
    hPrintFailure( %status );

    ## exit with failure
    exit( $status{code} );
} # --- End of Main


# --- Sub routines (Methods)

# --- Sub routines (Helpers)

sub hVersion
{
    print( "\n" );
    print( "WD Get Run-Level:" );
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
    print( "WD Get Run-Level:" );
    print( "\n" );
    print( "\n" );
    print( "Usage:" );
    print( "\n" );
    print( "getRunLevel.pl" );
    print( "\n" );
    print( "\n" );
    print( "Expected Output:" );
    print( "\n" );
    print( "init | app | emergency | admin | minimal" );
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
