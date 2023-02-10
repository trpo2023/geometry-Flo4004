#include <stdio.h>
#include <string.h>

int main()
{
    char object[20];
    fgets(object, sizeof(object), stdin);

    if (object[0] == 99) {
        for (int i = 0; i != strlen(object); i++) {
            printf("%s == %d\n", object[i]);
        }
    } else {
        printf("\nError at column 0: expected 'circle', 'triangle' or "
               "'polygon'");
    }
}