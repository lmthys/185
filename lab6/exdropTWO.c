/* Larisa Andrews, Section T, 9/1/2015 */
/* Lab 5 Wrapper Program */

#include <stdio.h>
#include <math.h>

#define TRUE 1
#define TIME 100


int Close_To(double tolerance, double point, double value);
double mag(double x, double y, double z);
double seconds(double time);
double Distance(double time);
int PercentLess(double actual, double theory); 

int main(void) {
	int t;
	double ax, ay, az; 	
    int time;
	int time2; 
	int time3; 
	int timeSec = 0; 
    int t2;
	int t3;
	double t4;
	int oldT3 = 0; 
	int newT = 0; 
	double x0 = 0.0; 
	double xPosition = 0.0; 
	double oldV = 0.0; 
	double newV = 0.0; 
	double oldX = 0.0; 
    double second = 0.0; 
	int dataRec = 0; 
          scanf("%d, %lf, %lf, %lf", &t, &ax, &ay, &az);
	      printf("Ok, I'm now receiving data.\n"); 
		  fflush(stdout); 
		
		 
			
			printf("I'm Waiting");
			fflush(stdout); 
            
		    
           while(Close_To(.25,1,mag(ax,ay,az))== 1){ 
                scanf("%d, %lf, %lf, %lf", &t, &ax, &ay, &az);
                time2 = t;
 				
				if((timeSec) ==1){
					if(time3 < time2){
						printf("."); 
						fflush(stdout);
						timeSec = 0; 
					}
				}
				else {
					time2 = t; 
					time3 = t + TIME; 
					timeSec = 1; 
				}
				
		   }
			printf("\n\n");
            fflush(stdout);	
            t2 = t;	
           			
            while(Close_To(.25,1,mag(ax,ay,az))== 0){
				scanf("%d, %lf, %lf, %lf", &t, &ax, &ay, &az);
				newT = t;
				if(dataRec != 1){
					printf("         Help Me! I'm falling");
					fflush(stdout);
					oldT3 = t; 
					dataRec = 1; 
				}
			    time2 = t;
              	if((timeSec) ==1){
					if(time3 < time2){
						printf("!"); 
						fflush(stdout);
						timeSec = 0; 
					}
				}
				else {
					time2 = t; 
					time3 = t + TIME; 
					timeSec = 1; 
				}
				second = (newT - oldT3)/1000.0; 
				//printf("%d\n", newT); 
				//printf("%lf\n", mag(ax,ay,az));
				//printf("%lf\n", oldV);
				newV = oldV + ((1 - mag(ax, ay, az))  * (9.8) * (second));
				fflush(stdout);
			    xPosition  = oldX + ((newV) * (second));
				fflush(stdout);
			    oldT3 = t;
			    oldV = newV; 
		        oldX = xPosition;
				
				
				
            }
			scanf("%d, %lf, %lf, %lf", &t, &ax, &ay, &az);
			t3 = t;
			printf("\n\n");
			//printf("%d",t3); 
			fflush(stdout);
			t4 = t3 - t2; 
		    
			printf("                Ouch! I fell %lf meters in %lf seconds.\n", Distance(seconds(t4)), seconds(t4)); 
            			
				
			printf("                Compensating for air resistance, the fall was %lf meters.\n", xPosition); 
			
		    printf("                This is %d%% less than computed before.\n", PercentLess(xPosition, Distance(seconds(t4)))); 
	        
   
    
    return 0;	
}

	

int Close_To(double tolerance, double point, double value){
	if(((point - tolerance) <= value)&&((point + tolerance) >= value)){
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
double seconds(double time) {
	double sec = 0; 
	sec = time/1000;	
	return sec; 
}
double Distance(double time){
	double distance = 0.0;
    distance = 0 + (0 * time) + 4.9 * (time * time); 
	return distance; 
}
int PercentLess(double actual, double theory){
	double percent;
	int percentRound = 0; 
	percent = (actual/theory) * 100; 
	percentRound = 100 - percent; 
	return percentRound; 
}
 

/* Put your lab 4 functions here, as well as your new function close_to */
// Test 1 : .38 m
// Test 2 : .29 m
// Test 3 : .41 m 
// Test 4 : .43 m

// Test 5 : .34 m    
// Sample Code Height : 9.81 m 


