#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#define pi 3.14159265358979323846

int main()
{
    char object[50];
    char input[50];
    char x[20], y[20], radius[20];
    char circle[] = "circle";
    int i, index;
    double x_num, y_num, radius_num;

    int bracket_open = 0, bracket_close = 0, point_one = 0;
    int error_bracket_open = 0, error_bracket_close = 0;

    for (int i = 0; i < 50; i++) {
        object[i] = '\0';
        input[i] = '\0';
    }

    fgets(input, sizeof(input), stdin);

    // working with string
    for (int j = 0; j < strlen(input); j++) {
        input[j] = tolower(input[j]);
    }

    for (int j = 0, m = 0; j < strlen(input); j++) {
        if ((input[j]) == ' ' && (input[j + 1] == ' '))
            continue;
        else {
            object[m] = input[j];
            m++;
        }
    }

    // start of the treatment errors
    if (object[0] == 'c') {
        for (int j = 0; j < strlen(object); j++) {
            if (object[j] == '(') {
                bracket_open++;
                error_bracket_open = j;
            }

            if (object[j] == ')') {
                bracket_close++;
                error_bracket_close = j;
            }

            if (object[j] == ',') {
                point_one++;
            }
        }
        if (bracket_open != 1) {
            printf("Error at column %d: expected ')'", error_bracket_open);
            return 1;
        }
        if (bracket_close != 1) {
            printf("Error at column %d: expected '('", error_bracket_close);
            return 1;
        }
        if (point_one != 1) {
            printf("Error: expected 'circle(x y, r)'\n");
            return 5;
        }

        for (i = 0; object[i] != '('; i++) {
            if (object[i] != circle[i]) {
                printf("Error at column %d: expected 'circle'\n", i);
                return 2;
            }
        }

        for (int j = 0; object[i] != ' '; j++) {
            if (object[i] == ')') {
                printf("Error: expected 'circle(x y, r)'\n");
                return 5;
            }
            for (i = i + 1; object[i] != ' '; i++, j++) {
                x[j] = object[i];
            }
            index = j;
        }
        x_num = atof(x);
        for (int j = 0, point = 0, minus = 0; j < index; j++) {
            if (x[0] == '.') {
                printf("1Error at collum %d: expected '<double>'\n", i);
                return 3;
            }
            if (x[j] == '.')
                point++;
            if (x[j] == '-')
                minus++;
            if (isalpha(x[j]) != 0) {
                printf("2Error at collum %d: expected '<double>'\n", i);
                return 3;
            }
            if (point > 1 || minus > 1) {
                printf("3Error at collum %d: expected '<double>'\n", i);
                return 3;
            }
        }

        for (int j = 0; object[i] != ','; j++) {
            if (object[i] == ')') {
                printf("Error: expected 'circle(x y, r)'\n");
                return 5;
            }
            for (i = i + 1; object[i] != ','; i++, j++) {
                y[j] = object[i];
            }
            index = j;
        }
        y_num = atof(y);
        for (int j = 0, point = 0, minus = 0; j < index; j++) {
            if (y[0] == '.') {
                printf("4Error at collum %d: expected '<double>'\n", i);
                return 3;
            }
            if (y[j] == '.')
                point++;
            if (y[j] == '-')
                minus++;
            if (isalpha(y[j]) != 0) {
                printf("5Error at collum %d: expected '<double>'\n", i);
                return 3;
            }
            if (point > 1 || minus > 1) {
                printf("6Error at collum %d: expected '<double>'\n", i);
                return 3;
            }
        }

        for (int j = 0; object[i] != ')'; j++) {
            for (i = i + 2; object[i] != ')'; i++, j++) {
                radius[j] = object[i];
            }
            index = j;
        }
        radius_num = atof(radius);
        for (int j = 0, point = 0, minus = 0; j < index; j++) {
            if (radius[0] == '.') {
                printf("7Error at collum %d: expected '<double>'\n", i);
                return 3;
            }
            if (radius[j] == '.')
                point++;
            if (radius[j] == '-') {
                printf("8Error at collum %d: expected positive number\n", i);
                return 3;
            }
            if (isalpha(radius[j]) != 0) {
                printf("9Error at collum %d: expected '<double>'\n", i);
                return 3;
            }
            if (point > 1 || minus > 1) {
                printf("10Error at collum %d: expected '<double>'\n", i);
                return 3;
            }
        }

        if (i + 1 != strlen(object) - 1) {
            printf("Error at column %d: unexpected token", i);
            return 4;
        }
        printf("%s", object);
        printf("x = %f\ny = %f\nradius = %f\n", x_num, y_num, radius_num);
    }

    else {
        printf("\nError at column 0: expected 'circle', 'triangle' or "
               "'polygon'");
        return 5;
    }
}