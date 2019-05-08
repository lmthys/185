/* Larisa Andrews, Section T, 9/10/2015 */


#include <stdio.h>


int main() {
// CprE 185: Lab 3
// Problem 1: Mysterious Output


	int integerResult;
	double decimalResult;
	
	integerResult = 77 / 5;
	printf("The value of 77/5 is %d\n", integerResult); // This print function had the wrong control character, it was %lf instead of %d. It needed %d because it was identifing an int not a double.

	integerResult = 2 + 3;
	printf("The value of 2+3 is %d\n", integerResult); // This needed a variable to put in for %d control character. Since in was speificing an int, you put in integerResult

	decimalResult = 1.0 / 22.0;
	printf("The value 1.0/22.0 is %lf\n", decimalResult); // This also had the wrong control character. It was calling for a double but had a int control character. So I changed if from %d to %lf to speicify a double. 
	
	return 0;
}




