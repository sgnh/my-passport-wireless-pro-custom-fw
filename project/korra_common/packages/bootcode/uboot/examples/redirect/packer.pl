#!/usr/bin/perl -w

$argc = $#ARGV+1;
if ($argc == 0) {
    printf("Usage: perl packer.pl [app_name]\n");
    printf("[app_name] this is the file name of your image\n");
    exit 0;
}

$in_file = $ARGV[0] . ".bin";
$out_file = $ARGV[0] . "_packed.bin";
open FILE, ">$out_file";

if (!(-e $in_file)) {
	print "Can't find " . $in_file . "\n";
	exit 0;
}
  
# read the data from in_file to output file 
open FILE1, $in_file;
my $filesize = -s $in_file;
print FILE pack('N',$filesize);  #unsigned int 4byte in big endian format
while (<FILE1>) {
   	print FILE "$_";
}

# if not 4-byte aligned, calculate the padding bytes
if ($filesize%4) {
	$padding = 4-($filesize%4);
}
else {
	$padding = 0;
}

# do the padding with 0xFF
for (; $padding > 0; $padding--) {
	print FILE pack('U', 255);
}

print FILE pack('N',$filesize);  #unsigned int 4byte in big endian format
print FILE pack('L',0xcccccccc);  #unsigned int 4byte, need be same with the one romcode checks

close FILE1;
close FILE;
