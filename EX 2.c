#include <stdio.h>

int main() {
    int a, b;

    
    if (&a > &b) {
        
		printf("O endereco de a (%p) é maior que o de b (%p)\n", (void*)&a, (void*)&b);
    } else {
       
	    printf("O endereco de b (%p) é maior que o de a (%p)\n", (void*)&b, (void*)&a);
    }

    return 0;
}
