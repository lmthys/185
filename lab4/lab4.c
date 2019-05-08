/* Lab 4 Wrapper Program */

#include <stdio.h>
#include <math.h>

#define TRUE 1

double mag(double x, double y, double z);/* Put your function prototypes here */
int minutes(int time); 
int seconds(int time);
int millis(int time); 

int main(void) {
	int t;
	double  ax, ay, az; 	


	while (TRUE) {
		scanf("%d,%lf,%lf,%lf", &t, &ax, &ay, &az);	

/* CODE SECTION 0 */
		printf("Echoing output: %8.3lf, %7.4lf, %7.4lf, %7.4lf\n", (double)t, ax, ay, az);

 	/*CODE SECTION 1 */
		printf("At %d ms, the acceleration's magnitude was: %lf\n", 
			t, mag(ax, ay, az)); 
 	/* CODE SECTION 2*/
		printf("At %d minutes, %d seconds, and %d milliseconds it was: %lf\n", 
		minutes(t), seconds(t), millis(t), mag(ax,ay,az)); 

	}

return 0;
}

double mag(double x, double y, double z) {
	double magnitude = 0.0; 
	magnitude = sqrt(x*x+y*y+z*z); 
	return magnitude; 
}
int minutes(int time) {
	int min = 0; 
	min = time/60000; 
	return min; 
}
int seconds(int time) {
	int sec = 0; 
	sec = time %60000;
    sec = sec/1000;	
	return sec; 
}
int millis(int time) {
	int mini = 0; 
	mini = time %1000;
	return mini; 
}/* Put your functions here */


