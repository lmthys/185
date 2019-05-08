
// CprE 185: Lab 3
// Problem 3: Esplora

#include <stdio.h>
#include <math.h>


int main() {
	double x, y, z;

	while (1) { 
		scanf("%lf , %lf , %lf", &x, &y, &z);
		printf("Magnitude of (%5.2lf,%5.2lf,%5.2lf) is: %6.2lf\n",
			x, y, z, sqrt(x*x+y*y+z*z) );
	}

	return 0;
}
// at rest it was .97, when it was moving it almost went to 2, when dropped it jumped from positive to negative 1 
// I think knowing the equation and what the xy and z axis's are helps us understand the outputs of the Esplora by having a sense of what the device is doing. It is showing how it moved while you moved it through the outputs. 
