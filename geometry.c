#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define pi 3.14159265358979323846

int main()
{
    char object[20];
    char x[20], y[20];
    char circle[] = "circle";
    int i;
    double x_num, y_num;
    fgets(object, sizeof(object), stdin);

    if (object[0] == 'c') {
        for (i = 0; object[i] != '('; i++) {
            if (object[i] != circle[i]) {
                printf("Error at column %d: expected 'circle'\n", i);
                break;
            }
        }

        for (int j = 0; object[i] != ' '; j++) {
            for (i = i + 1; object[i] != ' '; i++, j++) {
                x[j] = object[i];
            }
        }
        x_num = atof(x);
        if (isdigit(x_num) == 0) {
            printf("Error at collum %d: expected '<double>'\n", i);
            exit;
        }

        for (int j = 0; object[i] != ','; j++) {
            for (i = i + 1; object[i] != ','; i++, j++) {
                y[j] = object[i];
            }
        }
        y_num = atof(y);
        if (isdigit(y_num) != 0) {
            printf("Error at collum %d: expected '<double>'\n", i + 1);
            exit;
        }

        printf("%f %f", x_num, y_num);
    }

    else {
        printf("\nError at column 0: expected 'circle', 'triangle' or "
               "'polygon'");
    }
}