#include <stdio.h>
#include <math.h>

#define PI 3.1415

int main()
{
    float grau, rad, cosseno;

    printf("Qual valor do grau? ");
    scanf("%f", &grau);

    rad = grau * PI / 180;

    cosseno = cos(rad);

    printf("Cosseno: %.4f\n", cosseno);

    return 0;
}

	
	
	
	
	
	

