#!/bin/bash
:<<!
run command: "./count_sloc.sh > sloc.txt"
!

project_files=$(cd `dirname $0`; cd 01.w_Defects ;ls *.c)
project_path=$(cd `dirname $0`; cd 01.w_Defects; pwd)

:<<!
!
for file in $project_files
do
  header=${file%.*}
  if [ "$header" != "main" -a "$header" != "stubs" -a "$header" != "invalid_extern_1" ];then
     echo "$file $( grep -o ";" $project_path/$header.c | wc -l)"
  fi
done

