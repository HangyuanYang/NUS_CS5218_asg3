/*
* File Name: Clang_good.c
* Defect Classification
* ---------------------
* Defect Type1: Numerical defects
* Defect Sub-type1: Bit shift bigger than integral type or negative

* Defect Type2: Misc defects
* Defect Sub-type2: Uninitialized variable

* Defect Type3: Pointer related defects
* Defect Sub-type3: Uninitialized pointer

* Defect Type4: Numerical defects
* Defect Sub-type4: Division by zero

* Defect Type5: Resource management defects
* Defect Sub-type: Invalid memory access to already freed area

* Description: Defect Code to identify defects of five types with 10 test cases
*/

#include "HeaderFile.h"

// Type of defects1: Bit Shift
// Complexity: int	right shift with negative Constant
void bit_shift_01(){
	int a = 1;
	int ret;
	ret = a >> -1; /*Clang can detect this line as error*/ /*ERROR:Bit shift error*/
	sink = ret;
}

// Complexity: int Beyond the size of the left shift -Nonlinear equation
void bit_shift_02(){
	int a = 1;
	int shift = 6;
	int ret;
	ret = a << ((shift * shift) - 4); /*Clang can detect this line as error*/ /*ERROR:Bit shift error*/
    sink = ret;
}

// Complexity: int Beyond the size of the left shift -An array of element values
void bit_shift_03 ()
{
	int a = 1;
	int shifts[5] = {2, 4, 8, 16, 32};
	int ret;
	ret = a << shifts[4]; /*Clang can detect this line as error*/ /*ERROR:Bit shift error*/
    sink = ret;
}



// Type of defects2: uninitialized variable
// Complexity: basic types	int	Variable	Loading
void uninit_var_01 ()
{
	int a ;
	int ret;
	ret = a; /*Clang can detect this line as error*/ /*ERROR:Uninitialized Variable*/
	sink = ret;
}


// Complexity: 2-dimensional array	int	Variable	Loading
void uninit_var_02 ()
{
	int buf[6][6];
	int ret;
	ret = buf[1][2]; /*Clang can detect this line as error*/  /*ERROR:Uninitialized Variable*/
	sink = ret;
}



// Type of defects3: Uninitialized pointer
// Complexity: When using a single pointer int	Variable - Loading
void uninit_pointer_01 ()
{
	int *p ;  
	int ret;
	ret = *p; /*Clang can detect this line as error*/ /*ERROR:Uninitialized pointer*/
	sink = ret;
}

// Complexity: 1 single pointer	int	Variable	Write
void uninit_pointer_02 ()
{
	int a;
	int *p ;
	*p = 1; /*Clang can detect this line as error*//*ERROR:Uninitialized pointer*/
	sink = *p;
}



// Type of defects4: Division by zero
// Complexity: divide (/)	Basic type	int	Constant
void zero_division_01 ()
{
	int dividend = 100;
	int ret;
	ret = dividend / 0; /*Clang can detect this line as error*//* ERROR:division by zero */
	sink = ret;
}

// Complexity: divide (/)	1-Dimensional array	int	An array of element values
void zero_division_02 ()
{
	int dividend = 100;
	int divisors[4] = {2, 0, 1, 3};
	int ret;
	ret = dividend / divisors[1];/*Clang can detect this line as error*/ /* ERROR:division by zero */
	sink = ret;
}


// Type of defects5: Invalid memory access to already freed area
// Complexity : Memory is allocated and accessed after free -  when using pointer to int and conditional operator

void invalid_memory_access_01 ()
{
	int *ptr, a;
	int flag=10;
	ptr= (int*) malloc(10*sizeof(int));

    if(flag == 10)
    {
    	free(ptr);
    }
    if(flag == 10)
    	a = *(ptr+1); /*Clang can detect this line as error*/ /*ERROR:Invalid memory access to already freed area*/
	sink = a;
}


