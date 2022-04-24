#!/bin/bash
project_path=$(cd `dirname $0`; cd ../../01.w_Defects; pwd)

file_name="underrun_st"
if [ -d $file_name ];then
  rm -rf $file_name
fi
# specify one c file, run infer
# infer run --biabduction --bufferoverrun --linters --liveness --pulse --racerd --siof --self-in-block --starvation --loop-hoisting --topl --uninit --enable-issue-type ARRAY_OUT_OF_BOUNDS_L1 --enable-issue-type ARRAY_OUT_OF_BOUNDS_L2 --enable-issue-type ARRAY_OUT_OF_BOUNDS_L3 --enable-issue-type AUTORELEASEPOOL_SIZE_UNREACHABLE_AT_EXIT --enable-issue-type BIABDUCTION_ANALYSIS_STOPS --enable-issue-type BIABDUCTION_MEMORY_LEAK --enable-issue-type BUFFER_OVERRUN_L4 --enable-issue-type BUFFER_OVERRUN_L5 --enable-issue-type BUFFER_OVERRUN_U5 --enable-issue-type CLASS_CAST_EXCEPTION --enable-issue-type CONDITION_ALWAYS_FALSE --enable-issue-type CONDITION_ALWAYS_TRUE --enable-issue-type CONFIG_CHECKS_BETWEEN_MARKERS --enable-issue-type CONFIG_IMPACT --enable-issue-type CONSTANT_ADDRESS_DEREFERENCE --enable-issue-type DANGLING_POINTER_DEREFERENCE --enable-issue-type DANGLING_POINTER_DEREFERENCE_MAYBE --enable-issue-type DIVIDE_BY_ZERO --enable-issue-type ERADICATE_META_CLASS_CAN_BE_NULLSAFE --enable-issue-type ERADICATE_META_CLASS_IS_NULLSAFE --enable-issue-type ERADICATE_META_CLASS_NEEDS_IMPROVEMENT --enable-issue-type EXECUTION_TIME_UNREACHABLE_AT_EXIT  --enable-issue-type EXPENSIVE_AUTORELEASEPOOL_SIZE --enable-issue-type EXPENSIVE_EXECUTION_TIME --enable-issue-type GLOBAL_VARIABLE_INITIALIZED_WITH_FUNCTION_OR_METHOD_CALL --enable-issue-type INFINITE_AUTORELEASEPOOL_SIZE  --enable-issue-type INFINITE_EXECUTION_TIME --enable-issue-type INTEGER_OVERFLOW_L5 --enable-issue-type INTEGER_OVERFLOW_U5 --enable-issue-type INVARIANT_CALL --enable-issue-type Leak_unknown_origin --enable-issue-type NIL_MESSAGING_TO_NON_POD --enable-issue-type PULSE_UNINITIALIZED_VALUE --enable-issue-type SKIP_FUNCTION --enable-issue-type UNTRUSTED_BUFFER_ACCESS --enable-issue-type UNTRUSTED_HEAP_ALLOCATION --disable-issue-type DEAD_STORE --disable-issue-type UNINITIALIZED_VALUE --disable-issue-type NULL_DEREFERENCE -o $file_name -- clang -c $project_path/$file_name.c
infer run --bufferoverrun --enable-issue-type BUFFER_OVERRUN_L5 --disable-issue-type DEAD_STORE --disable-issue-type UNINITIALIZED_VALUE -o $file_name -- clang -c $project_path/$file_name.c

if [ -f "$file_name.o" ];then
  rm -f "$file_name.o"
fi
:<<!
  
!
