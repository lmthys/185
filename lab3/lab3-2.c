/* Larisa Andrews, Section T, 9/10/2015 */


#include <stdio.h>


int main() {

int integerVar = 0; 
double doubleVar = 0.0;

integerVar = 6427 + 1725; 
printf("The value of 6427 + 1725 is %d\n", integerVar); 

integerVar = (6971 * 3925)-95;
printf("The value of 6971 times 3925 minus 95 is %d\n", integerVar); 

doubleVar = 79 + 12/5; 
printf("The value of 79 plus 12 divided by five is %.2lf\n", doubleVar); 

doubleVar = 3640.0 / 107.9; 
printf("The value of 3640.0 divided by 107.9 is %.2lf\n", doubleVar); 

integerVar = (22/3) * 3; 
printf("The value of 22 divided by 3 times 3 is %d\n", integerVar); 

integerVar = 22 / (3 * 3); 
printf("The value of 22 divided by 3 times 3 is %d\n", integerVar); 

doubleVar = 22 / (3 * 3); 
printf("The value of 22 divided by 3 times 3 is %.2lf\n", doubleVar); 

doubleVar = 22 / 3 * 3; 
printf("The value of 22 divided by 3 times 3 is %.2lf\n", doubleVar); 

doubleVar = (22.0 / 3) * 3; 
printf("The value of 22.0 divided by 3 times 3 is %.2lf\n", doubleVar); 

integerVar = 22.0 / (3 * 3.0); 
printf("The value of 22.0 divided by 3 times 3.0 is %d\n", integerVar); 

doubleVar = 22.0 / 3.0 * 3.0; 
printf("The value of 22.0 divided by 3.0 times 3.0 is %.2lf\n", doubleVar); 

// My equations 
doubleVar = (3.14159) * (7.501609); 
printf("The circumference of a circle that has a radius of 7.5012 is %.3lf\n", doubleVar); 
 
doubleVar = (14) * (.3048);
printf("14 feet is %.4lf meters\n", doubleVar); 

doubleVar = ((76 - 32)/1.8); 
printf("76 degrees Fahrenheit is %.2lf degrees centigrade\n", doubleVar); 


return 0; 


}