#include <stdio.h>


#define MAXPOINTS 10000

// compute the average of the first num_items of buffer
double avg(double buffer[], int num_items);

//update the max and min of the first num_items of array
void maxmin(double array[], int num_items, double* max, double* min);

//shift length-1 elements of the buffer to the left and put the 
//new_item on the right.
void updatebuffer(double buffer[], int length, double new_item);



int main(int argc, char* argv[]) {
	
	/* DO NOT CHANGE THIS PART OF THE CODE */

	double x[MAXPOINTS], y[MAXPOINTS], z[MAXPOINTS];
	int lengthofavg = 0;
	int time;
	int leftB,upB,downB,rightB;
	int joy; 
	int s; 
	int i; 
    double max, min; 
    double ax, ay ,az; 	
	if (argc>1) {
		sscanf(argv[1], "%d", &lengthofavg );
		printf("You entered a buffer length of %d\n", lengthofavg);
	}
	else {
		printf("Enter a length on the command line\n");
		return -1;
	}
	if (lengthofavg <1 || lengthofavg >MAXPOINTS) {
		printf("Invalid length\n");
		return -1;
	}
    while(leftB==0){
		scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d", &time, &ax, &ay, &az, &upB, &downB, &leftB, &rightB, &joy, &s);
		
			updatebuffer(x,lengthofavg,ax);
			updatebuffer(y,lengthofavg,ay);
			updatebuffer(z,lengthofavg,az);
		
		    printf("%lf,",ax);
			printf("%lf,",ay);
			printf("%lf,",az);
			
			printf("%lf,",avg(x,lengthofavg));
			printf("%lf,",avg(y,lengthofavg));
			printf("%lf,",avg(z,lengthofavg));
			
			maxmin(x,lengthofavg,&max,&min);
			printf("%lf,%lf,",max,min);
			maxmin(y,lengthofavg,&max,&min);
			printf("%lf,%lf,",max,min);
			maxmin(z,lengthofavg,&max,&min);
			printf("%lf,%lf\n",max,min);
	}
	
	
	/* PUT YOUR CODE HERE */


}
double avg(double buffer[], int num_items){
	int i;
    double avg;
   	
	for(i = 0; i < num_items; i++){
	avg = buffer[i] + avg;
	}
	avg = avg/num_items; 
	return avg; 
}
void maxmin(double array[], int num_items, double* max, double* min){
	int i=0;
	*max = 0; 
	*min = 0;
    for(i =0; i<num_items; i++){
		if(array[i]> *max){
			*max = array[i]; 
		}
		else if(array[i]< *min){
			*min = array[i]; 
		}
	}	
	return; 
}
void updatebuffer(double buffer[], int length, double new_item){
	int i; 
	for(i = 1; i<length; i++){
		
		
		                             
		buffer[i-1] = buffer[i];
        		
 		
	}
	buffer[length-1] = new_item; 
}


