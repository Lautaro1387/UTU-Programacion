#include <stdio.h>


const int MAX = 80;

int main(){

        char string[MAX];
        char c;
        int i = 0;
        int n = 0;

        printf("Ingrese una cadena");
        scanf("%c", &c);
        while (c != '\n' && i<MAX-1) {
            string[i] = c;
            scanf("%c", &c);
            i++;
        }
        string[i] = '\0';
        for (i = 0; i<string[i]; i++){
            printf("%c", c);
        }
}