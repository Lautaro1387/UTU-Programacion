#include <stdio.h>

int main()
{
    char c;
    int cantVocales=0;
    printf("Ingrese la oracion: ");
    scanf("%c", &c);

    while(c!='\n')
    {
        switch(c)
        {
            case 'a': c = 'e';
                      cantVocales++;
                      break;
            case 'e': c = 'i';
                      cantVocales++;
                      break;
            case 'i': c = 'o';
                      cantVocales++;
                      break;
            case 'o': c = 'u';
                      cantVocales++;
                      break;
            case 'u': c = 'a';
                      cantVocales++;
                      break;
        }
        printf("%c", c);
        scanf("%c", &c);
    }
    printf("\nLa cantidad de vocales cambiadas es %d.", cantVocales);
}
