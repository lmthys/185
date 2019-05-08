/* Lab 4 Wrapper Program */

#include <stdio.h>
#include <math.h>

#define TRUE 1
int ButtonsPressed(int x, int y, int z, int c);

int main(void) {
	
	int ax, ay, az, ab, ac, av; 	


	while (TRUE) {
	scanf("%d, %d, %d, %d, %d, %d", &ax, &ay, &az, &ab, &ac, &av);	
    //printf("The buttons equal %d,%d,%d, %d, %d, %d\n", ax, ay, az, ab, ac, av);
    printf("The number of keys pressed is %d\n", ButtonsPressed(ax, ay, az, ab)); 
	
	fflush(stdout); 


	}

return 0;
}
int ButtonsPressed(int x, int y, int z, int c) {
	int buttons = 0; 
	buttons = (x + y + z + c); 
	return buttons; 
}


