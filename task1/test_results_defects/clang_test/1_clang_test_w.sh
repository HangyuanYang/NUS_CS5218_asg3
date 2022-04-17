#!/bin/bash
project_path=$(cd `dirname $0`; cd ../../01.w_Defects; pwd)
# echo $project_path
file_name="unused_var"
if [ -d $file_name ];then
  rm -rf $file_name
fi
# specify one c file, run infer
clang --analyze $project_path/$file_name.c > $file_name/report.txt 2>&1

if [ -f "$file_name.plist" ];then
  rm -f "$file_name.plist"
fi
:<<!
  
!
