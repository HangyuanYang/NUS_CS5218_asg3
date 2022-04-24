#!/bin/bash
:<<!
modify 1_infer_test_w.sh to specify arguments for infer command
then run *_infer_test_w.sh to overwrite the older version
check results in report.txt
!

project_files=$(cd `dirname $0`; cd 01.w_Defects ;ls *.c)
project_path=$(cd `dirname $0`; cd 01.w_Defects; pwd)


:<<!
!
for file in $project_files
do
  header=${file%.*}
  if [ "$header" != "main" -a "$header" != "stubs" -a "$header" != "invalid_extern_1" ];then
    echo "$header.c $(cat $project_path/$header.c | grep -o detect | wc -l)"
  fi
done

