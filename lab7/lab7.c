// lab7.c
//
// This is the outline for your program
// Please implement the functions given by the prototypes below and
// complete the main function to make the program complete.
// You must implement the functions which are prototyped below exactly
//  as they are requested.

#include <stdio.h>
#include <math.h>
#define PI 3.141592653589

//NO GLOBAL VARIABLES ALLOWED


//PRE: Arguments must point to double variables or int variables as appropriate
//This function scans a line of explore data, and returns
//  True when left button is pressed
//  False Otherwise
//POST: it modifies its arguments to return values read from the input line.
int read_acc(double* a_x, double* a_y, double* a_z, int* time, int* Button_UP, int* Button_DOWN, int* Button_LEFT, int* Button_RIGHT);

// PRE: -1.0 <= x_mag <= 1.0
// This function computes the roll of the esplora in radians
// if x_mag outside of -1 to 1, treat it as if it were 1 or -1
// POST: -PI/2 <= return value <= PI/2
double roll(double x_mag);

// PRE: -1.0 <= y_mag <= 1.0
// This function computes the pitch of the esplora in radians
// if y_mag outside of -1 to 1, treat it as if it were 1 or -1
// POST: -PI/2 <= return value <= PI/2
double pitch(double y_mag);


// PRE: -PI/2 <= rad <= PI/2
// This function scales the roll value to fit on the screen
// POST: -39 <= return value <= 39
int scaleRadsForScreen(double rad);

// PRE: num >= 0
// This function prints the character use to the screen num times
// This function is the ONLY place printf is allowed to be used
// POST: nothing is returned, but use has been printed num times
void print_chars(int num, char use);

//PRE: -39 <= number <=39
// Uses print_chars to graph a number from -39 to 39 on the screen.
// You may assume that the screen is 80 characters wide.
void graph_line(int number);

int main()
{
	double x, y, z;			// magnitude values of x, y, and z accelerations
	int b_Up, b_Down, b_Left, b_Right;	// variables to hold the button statuses
	double roll_rad, pitch_rad;		// value of the roll measured in radians
	int scaled_value; 	// value of the roll adjusted to fit screen display
    int time; 
	int test = 0; 
	int soManyChoices = 0;
	//insert any beginning needed code here
    //read_acc(&x, &y, &z, &time, &b_Up, &b_Down, &b_Left, &b_Right);	
	do
	{
		
		
		 read_acc(&x, &y, &z, &time, &b_Up, &b_Down, &b_Left, &b_Right);	
		
		// Get line of input

		
		
		
		roll_rad = roll(x);// calculate roll and pitch.  Use the buttons to set the condition for roll and pitch
        //printf("\n"); 
		test = b_Down;  // if the button is pressed test = 1
		
		if((test)== 1){ //if test is 1 then it evaluates to true
			if((soManyChoices)== 1){ //if so.. is 1 it sets so.. to 0 
				soManyChoices = 0; 
				
			}
			else if ((soManyChoices != 1)) { // if so.. is not 1 then it is set to one
				soManyChoices = 1; 
			}
			
		}
		
		else if((soManyChoices)== 1){ // if so.. is 1 then we are calc-ing pitch
			
			pitch_rad = pitch(y); 
			scaled_value = scaleRadsForScreen(pitch_rad);
			
		}
		else{ // if we have not pressed any buttons initially we are calc-ing roll
			
			scaled_value = scaleRadsForScreen(roll_rad); 
			
		}
			
		
		graph_line(scaled_value); 
		

		fflush(stdout);
	} while (read_acc(&x, &y, &z, &time, &b_Up, &b_Down, &b_Left, &b_Right));	
		 // Modify to stop when left button is pressed
	
	return 0;
}
int read_acc(double* a_x, double* a_y, double* a_z, int* time, int* Button_UP, int* Button_DOWN, int* Button_LEFT, int* Button_RIGHT){
	int joyStick; 
	int s; 
	scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d", time, a_x, a_y, a_z, Button_DOWN, Button_UP, Button_LEFT, Button_RIGHT, &joyStick,&s); 
	if((*Button_LEFT)==1){
		return 0; 
	}
	else {
		return 1; 
	}
	return; 
}
double roll(double x_mag){
	double roll;
	roll = asin(x_mag); 
	if(roll > 1){
		roll = 1; 
	}
	else if(roll < -1){
		roll = -1; 
	}
	roll = roll * (PI/2); 
	
	return roll; 

}
double pitch(double y_mag){
	double pitch; 
	pitch = asin(y_mag);
	if(pitch > 1){
		pitch = 1; 
	}
	else if(pitch < -1){
		pitch = -1; 
	}
	pitch = pitch * (PI/2); 
   
	
	return pitch;
}
int scaleRadsForScreen(double rad){
	int scale;
    double calc; 	
	    
		calc = ((39)/ (PI/2)); // 39 / PI/2 = 24.82817112 
      	scale = rad * calc;
		return scale; 
        		
	
}
void print_chars(int num, char use){
	int i = 0; 
	while(i<num){
		printf("%c", use); 
		i++; 
	}
	if(use != ' '){
		printf("\n"); 
	}
}
void graph_line(int number){
	 
	if(number==0){
		print_chars(39,' ');
		print_chars(1,'0'); 
	}
	else if(number<0) { //number is neg
		print_chars(number+39,' '); // number of spaces is -num + 39 
		print_chars(-number,'l'); // making the negative number positive 
	}
	else if(number>0){ //number is positive
		print_chars(39,' '); // 39 spaces to get to right side of screen 
		print_chars(number,'r'); 
	}
}



