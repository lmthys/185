/* Larisa Andrews, Section T, 9/1/2015 */
/* Lab 5 Wrapper Program */

#include <stdio.h>
#include <math.h>

#define TRUE 1

int TopBottom (double value);
int FrontBack (double value);
int RightLeft (double value);
int Close_To(double tolerance, double point, double value);
double mag(double x, double y, double z);

int main(void) {
	int t, b1, b2, b3, b4, b5, s;
	double ax, ay, az; 	
    int prints = 0; 

	while (TRUE) {
		scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d", &t, &ax, &ay, &az, &b1, &b2, &b3, &b4, &b5, &s );	

/* CODE SECTION 0 */
		//printf("Echoing output: %d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d\n", t, ax, ay, az, b1, b2, b3, b4, b5, s);

/* 	CODE SECTION 1 */
		//printf("At %d ms, the acceleration's magnitude was: %f\n", t, mag(ax, ay, az));  
		
		fflush(stdout); 
		if((TopBottom(az) == 1)&&(prints != 1)){
			
			printf("TOP\n\n");
			prints = 1;
        }
		else if((TopBottom(az) == 0)&&(prints != 2)){
			
			printf("BOTTOM\n\n");
			prints = 2; 
		}
		else if((FrontBack(ay) == 1)&&(prints != 3)){
			printf("FRONT\n\n");
			prints = 3;
		}
		else if((FrontBack(ay) == 0)&&(prints != 4)){
			printf("BACK\n\n");
			prints = 4;
		}
		else if((RightLeft(ax) == 1)&&(prints != 5)){
			printf("RIGHT\n\n");
			prints = 5; 
		}
		else if((RightLeft(ax) == 0)&&(prints != 6)){
			printf("LEFT\n\n");
			prints = 6; 
		}
		else if(b2 == 1){
			break; 
		}
		
	}
		

		
		
	


    return 0;
}
int TopBottom(double value){
	while(TRUE){
		if((value >= .9)&&(value <= 1.1)){
			 
			return 1;
		}
		else if((value <= -.9)&&(value >= -1.1))
		{
			
			 return 0; 
		}
		else 
		{
			return -1; 
		}
	}
}
int FrontBack(double value){
	while(TRUE){
		if((value >= .92) && (value <= 1.1)){
			return 1;
		}
		else if((value <= -.92)&&(value >= -1.1))
		{
			return 0; 
		}
		else 
		{
			return -1; 
		}
	}
}
int RightLeft(double value){
	while(TRUE){
		if((value >= .9) && (value <= 1.1)){
			
			return 1;
		}
		else if((value <= -.9)&&(value >= -1.1))
		{
			
			 return 0; 
		}
		else 
		{
			return -1; 
		}
	}
	
}
int Close_To(double tolerance, double point, double value){
	if(((point - tolerance) >= value)&&((point + tolerance) <= value)){
		return 1; 
	}
	else {
		return 0; 
    }
}
double mag(double x, double y, double z) {
	double magnitude = 0.0; 
	magnitude = sqrt(x*x+y*y+z*z); 
	return magnitude; 
}

/* Put your lab 4 functions here, as well as your new function close_to */



