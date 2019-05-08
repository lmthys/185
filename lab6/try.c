/* Larisa Andrews, Section T, 9/1/2015 */
/* Lab 5 Wrapper Program */

#include <stdio.h>
#include <math.h>

#define TRUE 1


int Close_To(double tolerance, double point, double value);
double mag(double x, double y, double z);
int seconds(int time);

int main(void) {
	int t, b1, b2, b3, b4, b5, s;
	double ax, ay, az; 	
    int time;
	int mags; 

	while (TRUE) {
		scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d", &t, &ax, &ay, &az, &b1, &b2, &b3, &b4, &b5, &s );	

/* CODE SECTION 0 */
		printf("Echoing output: %d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d\n", t, ax, ay, az, b1, b2, b3, b4, b5, s);

/* 	CODE SECTION 1 */
		printf("At %d ms, the acceleration's magnitude was: %lf\n", t, mag(ax, ay, az));  
		
		fflush(stdout); 
		
		printf("Time in seconds %d\n", seconds(t)); 
		
	
		if(Close_To(.1,1,az)){
			time = seconds(t); 
			 printf("%d\n",time);
		}
	    printf("%d\n",time); 


   
}

	return 0;
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
int seconds(int time) {
	int sec = 0; 
	sec = time %60000;
    sec = sec/1000;	
	return sec; 
}

/* Put your lab 4 functions here, as well as your new function close_to */



