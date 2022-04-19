#!/bin/bash
:<<!
modify 1_infer_test_w.sh to specify arguments for infer command
then run *_infer_test_w.sh to overwrite the older version
check results in report.txt
!

project_files=$(cd `dirname $0`; cd ../../01.w_Defects ;ls *.c)
project_path=$(cd `dirname $0`; cd ../../01.w_Defects; pwd)


for file in $project_files
do
  header=${file%.*}
  if [ -d $header ];then
    rm -rf $header
  fi
done

:<<!
!
for file in $project_files
do
  header=${file%.*}
  if [ "$header" != "main" -a "$header" != "stubs" -a "$header" != "invalid_extern_1" ];then
    mkdir $header
    clang --analyze $project_path/$header.c > $header/report.txt 2>&1
  fi
done

for file in $project_files
do
  header=${file%.*}
  if [ -f "$header.plist" ];then
    rm -f "$header.plist"
  fi
done
