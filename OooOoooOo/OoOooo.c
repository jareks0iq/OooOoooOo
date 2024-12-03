#include <stdio.h>
#include <string.h>
int main() {
    char buffer[2000];
    FILE *fp2 = fopen("output.txt", "w");
    FILE *fp = fopen("lab4-test-file.txt", "r");
    if (fp) {
        int countO = 0, counto = 0, flag = 0, i = 0, countline = 1;
        while ((buffer[i] = fgetc(fp)) != EOF) {
            if (buffer[i] != '\n') { 
                if (buffer[i] == 'O') { countO++; }
                else if (buffer[i] == 'o') { counto++; }
            }
            else { fprintf(fp2, "O - %d o - %d line - %d\n", countO, counto, countline); countO = 0, counto = 0; countline++; }
            if (i == 1999) { i = 0; }
            else { i++; }
        }
        fclose(fp);
        fclose(fp2);
    }
    else {
        printf("1) oh nooo... =(");
    }
}