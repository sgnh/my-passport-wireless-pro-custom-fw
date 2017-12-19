#!/bin/bash
#
# � 2010 Western Digital Technologies, Inc. All rights reserved.
#
# shareFunc - share functions
#

modUserTrustees()
{
	awk -v orig_user=$1 -v new_user=$2 '
	BEGIN {
		RS = "\n" ; FS = ":";
	}
	{
		if ( (substr($0,1,1) == "#") ) {
			print $0;
		}
		else if (length($0) > 0  ) {
			printf("%s", $1);
			# search for user, if no match, change
			for (i=2; i <= NF; i=i+2) {
				if ( $i == orig_user ) {
					printf(":%s:%s", new_user, $(i+1));
				}
				else {
					printf(":%s:%s", $i, $(i+1));
				}
			}
			printf ("\n");
		}
	}
	' $trustees > $trustees-new
} 

modUserSamba()
{
	awk -v orig_user=$1 -v new_user=$2 '
	BEGIN {
		RS = "\n" ; FS = " ";
	}
	function change_user_and_print_list(orig, new, list)
	{
		first = 1;
		for ( u in list ) {
			if ( list[u] == orig ) {
				if ( first == 1 )
					printf("%s", new);
				else 
					printf(",%s", new);
				first = 0;
			}
			else {
				if ( first == 1 )
					printf("%s", list[u]);
				else 
					printf(",%s", list[u]);
				first = 0;
			}
		}
		printf("\n");		
	}
	{
		tst_str = " valid users = ";
		idx = match($0, tst_str);
		if (idx == 0) {
			tst_str = " read list = ";
			idx = match($0, tst_str);
		}
		if (idx == 0) {
			tst_str = " write list = ";
			idx = match($0, tst_str);
		}
		if ( idx > 0 ) {
			printf(" %s", tst_str);
			split( substr($0, (idx + RLENGTH)), list, ",");
			change_user_and_print_list(orig_user, new_user, list);
		}
		else {
			print $0;
		}
	}
	' $sambaOverallShare > $sambaOverallShare-new
} 
