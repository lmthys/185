/* Larisa Andrews, Section T, 9/10/2015 */


#include <stdio.h>


int main() {
// CprE 185: Lab 3
// Problem 1: Mysterious Output


	int integerResult;
	double decimalResult;
	
	integerResult = 77 / 5;
	printf("The value of 77/5 is %lf\n", integerResult); // if it is an integer its needs a %d and not %lf 

	integerResult = 2 + 3;
	printf("The value of 2+3 is %d\n"); // needs a comma and another variable defined and then put in the printf statement 

	decimalResult = 1.0 / 22.0;
	printf("The value 1.0/22.0 is %d\n", decimalResult); // it needs to be %lf not %d 
	
	return 0;
}




