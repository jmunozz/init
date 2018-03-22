#!/bin/bash

test=`md5 -q /etc/passwd 2>-`
if [ $test ]; then echo $test;
fi
