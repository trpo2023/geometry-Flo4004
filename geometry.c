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

    int bracket_open = 0, bracket_close = 0;
    int error_bracket_open = 0, error_bracket_close = 0;

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
        }
        if (bracket_open != 1) {
            printf("Error at column %d: expected ')'", error_bracket_open);
            return 1;
        }
        if (bracket_close != 1) {
            printf("Error at column %d: expected '('", error_bracket_close);
            return 1;
        }

        for (i = 0; object[i] != '('; i++) {
            if (object[i] != circle[i]) {
                printf("Error at column %d: expected 'circle'\n", i);
                return 2;
            }
        }

        for (int j = 0; object[i] != ' '; j++) {
            for (i = i + 1; object[i] != ' '; i++, j++) {
                x[j] = object[i];
            }
            index = j;
        }
        x_num = atof(x);
        for (int j = 0; j < index; j++) {
            if (isalpha(x[j]) != 0) {
                printf("Error at collum %d: expected '<double>'\n", i);
                return 3;
            }
        }

        for (int j = 0; object[i] != ','; j++) {
            for (i = i + 1; object[i] != ','; i++, j++) {
                y[j] = object[i];
            }
            index = j;
        }
        y_num = atof(y);
        for (int j = 0; j < index; j++) {
            if (isalpha(y[j]) != 0) {
                printf("Error at collum %d: expected '<double>'\n", i);
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
        for (int j = 0; j < index; j++) {
            if (isalpha(radius[j]) != 0) {
                printf("Error at collum %d: expected '<double>'\n", i);
                return 3;
            }
        }

        char* bracket_close_last;
        bracket_close_last = strrchr(object, ')');
        if (bracket_close_last - object + 2 != strlen(object)) {
            printf("Error at column %ld: unexpected token",
                   bracket_close_last - object + 1);
        }

    }

    else {
        printf("\nError at column 0: expected 'circle', 'triangle' or "
               "'polygon'");
    }
}