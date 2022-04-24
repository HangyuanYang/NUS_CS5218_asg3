/*
* File Name: Infer_good.c
* Defect Classification
* ---------------------
* Defect Type1: Dynamic memory defects
* Defect Sub-type1: Dynamic buffer overrun

* Defect Type2: Pointer related defects
* Defect Sub-type2: Dereferencing a NULL pointer

* Defect Type3: Numerical defects
* Defect Sub-type3: Division by zero

* Defect Type4: Resource management defects
* Defect Sub-type4: Memory allocation failure

* Defect Type5: Static memory defects
* Defect Sub-type: Static buffer underrun

* Description: Defect Code to identify defects of five types with 8 test cases
*/


#include "HeaderFile.h"

/* Type of defects: Buffer Overrun
 * Dynamic buffer overrun
 * When using a pointer to char
*/
void dynamic_buffer_overrun_001 ()
{
	char *buf=(char*) calloc(10,sizeof(char));
	int i;
	if(buf!=NULL)
	{
		for (i=0;i<=10;i++)
	    {
			buf[i]=1; /*Infer should detect this line as error*/ /*ERROR:Buffer overrun*/
	    }
	    free(buf);
	}
}

/* Type of defects: Buffer Overrun
 * Dynamic buffer overrun
 * When using a pointer to short
 */
void dynamic_buffer_overrun_002 ()
{
	short *buf=(short*) calloc(10,sizeof(short));
	if(buf!=NULL)
	{
		*(buf+10)=1;/*Infer should detect this line as error*/ /*ERROR:Buffer overrun*/
		free(buf);
	}
}

/* Type of defects: Nullptr Dereference
 * Defect types : NULL pointer dereference (access)
 * Complexity: Assign a Constant value to NULL single pointer
 */
void null_pointer_001 ()
{
	int *p = NULL;
	*p = 1; /*Infer should detect this line as error*/ /*ERROR:NULL pointer dereference*/
}

/* Type of defects: Nullptr Dereference
 * Defect types : NULL pointer dereference (access)
 * Complexity: Assign a Constant value to NULL double pointer
 */
void null_pointer_002 ()
{
	int *p = NULL;
	int ret;
	ret = *p;/*Infer should detect this line as error*/ /*ERROR:NULL pointer dereference*/
        sink = ret;
}


/*
 * Types of defects: divide by zero
 * Complexity: divide (/)	Basic type	int	Constant
 */
void zero_division_001 ()
{
	int dividend = 1000;
	int ret;
	ret = dividend / 0;/*Infer should detect this line as error*/ /* ERROR:division by zero */
}

/*
 * Types of defects: divide by zero
 * Complexity: divide (/ =)	Basic type	int	Constant
 */
void zero_division_002 ()
{
	int dividend = 1000;
	int ret;
	dividend /= 0;/*Infer should detect this line as error*/ /* ERROR:division by zero */
	ret = dividend;
}


/*
* Type of defect: memory_allocation_failure - Memory could not be allocated / insufficient memory
* Complexity: when using pointers to the type INT
*/
#define MAX_VAL UINT_MAX
void memory_allocation_failure_002 ()
{
	long long int i=0;
	long long int *ptr=(long long*) malloc(MAX_VAL *sizeof(long long));/*Infer should detect this line as error*/ /*ERROR:Memory allocation failure */
	if(ptr !=NULL)
	{
	*(ptr+i) = i;
	free(ptr);
	}
}

/*
 * Types of defects: buffer underrun ( static buffer )
 * Complexity: 1-dimensional array	int	Constant	Loading
 */
void underrun_st_001 ()
{
	int buf[5] = {1, 2, 3, 4, 5};
	int ret;
	ret = buf[-1];/*Infer should detect this line as error*/ /*ERROR:Data Underrun*/
}
