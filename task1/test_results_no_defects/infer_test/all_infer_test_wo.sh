#!/bin/bash
:<<!
modify 1_infer_test_w.sh to specify arguments for infer command
then run *_infer_test_w.sh to overwrite the older version
check results in report.txt
!

project_files=$(cd `dirname $0`; cd ../../02.wo_Defects ;ls *.c)
project_path=$(cd `dirname $0`; cd ../../02.wo_Defects; pwd)


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
  if [ -d $header ];then
    rm -rf $header
  fi
  if [ "$header" != "main" ];then
    infer run --bufferoverrun --enable-issue-type DIVIDE_BY_ZERO -o $header -- clang -c $project_path/$header.c
  fi
done

for file in $project_files
do
  header=${file%.*}
  if [ -f "$header.o" ];then
    rm -f "$header.o"
  fi
done
