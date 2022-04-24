#!/bin/bash
project_path=$(cd `dirname $0`; cd ../../02.wo_Defects; pwd)

file_name="zero_division"
if [ -d $file_name ];then
  rm -rf $file_name
fi
# specify one c file, run infer

infer run --enable-issue-type DIVIDE_BY_ZERO --disable-issue-type DEAD_STORE --disable-issue-type NULL_DEREFERENCE -o $file_name -- clang -c $project_path/$file_name.c

if [ -f "$file_name.o" ];then
  rm -f "$file_name.o"
fi
:<<!
  
!
