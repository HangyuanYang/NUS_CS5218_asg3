#!/bin/bash
project_path=$(cd `dirname $0`; cd ../../01.w_Defects; pwd)
# echo $project_path
file_name="data_lost"
if [ -d $file_name ];then
  rm -rf $file_name
fi
# specify one c file, run infer
infer run --bufferoverrun -o $file_name -- clang -c $project_path/$file_name.c

if [ -f "$file_name.o" ];then
  rm -f "$file_name.o"
fi
:<<!
  
!
