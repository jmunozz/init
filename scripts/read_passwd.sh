#!/bin/bash
file=/etc/passwd
IFS=:
grep -v '^#' $file | while read -r username password uid gid infos path shell
do 
	echo "$uid $username $path"
done
