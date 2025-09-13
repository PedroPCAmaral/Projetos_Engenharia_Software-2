#include <stdio.h>

int string_ocorre(char *str1, char *str2) {
   
    while (*str1) {
        char *p1 = str1;
        char *p2 = str2;
        
        while (*p1 && *p2 && (*p1 == *p2)) {
            p1++;
            p2++;
        }

        if (!*p2) {
            return 1;
        }
        str1++;
    }
    return 0;  
}

int main() {
    char str1[] = "Programacao Estruturada";
    
	char str2[] = "Estruturada";

    if (string_ocorre(str1, str2)) {
       
	    printf("A string \"%s\" ocorre dentro de \"%s\".\n", str2, str1);
    } else {
        
		printf("A string \"%s\" não ocorre dentro de \"%s\".\n", str2, str1);
    }

    return 0;
}

