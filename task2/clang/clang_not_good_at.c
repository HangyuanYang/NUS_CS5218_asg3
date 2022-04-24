/*
* File Name: Clang_not_good_at.c
* Defect Classification
* ---------------------
* Defect Type1: Inappropriate code
* Defect Sub-type1: Contradict conditions

* Defect Type2: Numerical defects
* Defect Sub-type2: Data overflow

* Defect Type3: Numerical defects
* Defect Sub-type3: Data underflow

* Defect Type4: Inappropriate code
* Defect Sub-type4: Improper termination of block

* Defect Type5: Misc defects
* Defect Sub-type5: Unintentional end less loop

* Description: Defect Code to identify defects of above five types
*/
#include "HeaderFile.h"
int rand (void);
void mixed_error ()
{
	int c=2;
	int x = rand();
	int b=0x7fffffff;
	int d=0x80000001;
	int a=0;
	int i;
	if ((x > 0) && (x < 0))/*Tool should detect this line as error*/ /*ERROR:contradict condition*/
	{
		c=3;
	}
	for (i = 0; ; i ++)
	{
		a ++; /*Tool should detect this line as error*/ /*ERROR:Unintentional end less loop*/
	}
	int ret = b+c;/*Tool should detect this line as error*/ /*ERROR:Data Overflow*/
        int sink = d-c;/*Tool should detect this line as error*/ /*ERROR:Data Underflow*/
	while(c<10);/*Tool should detect this line as error*/ /*ERROR:Improper termination of block*/
	sink=ret;
}
/*
 * main function
 */
void mixed_error_main ()
{
	mixed_error ();
}
