/*
ID: configl1
LANG: C
TASK: ride
*/

#include <stdio.h>
#include <string.h>

#define MAX_LEN 7

int main() {
    char comet[MAX_LEN], group[MAX_LEN];
    FILE *fp = NULL, *fin = NULL;
    fin = fopen("ride.in","r");
    fscanf(fin, "%s %s", comet, group);

    int comet_num = 1, group_num = 1;
    for (int i = 0; i < strlen(comet); i++) {
        comet_num *= comet[i] - 'A' + 1;
    }
    for (int i = 0; i < strlen(group); i++) {
        group_num *= group[i] - 'A' + 1;
    }
    fp = fopen("ride.out","w");
    if (comet_num % 47 == group_num % 47) {
        fprintf(fp,"GO\n");
    } else {
        fprintf(fp,"STAY\n");
    }
    fclose(fp);

    return 0;
}