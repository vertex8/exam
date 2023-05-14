/*
ID: configl1
LANG: C
TASK: gift1
*/

#include <stdio.h>
#include <string.h>

#define MAX_NP 10
#define MAX_NAME_LEN 15

int main() {
    FILE *fin = fopen("gift1.in", "r");
    FILE *fout = fopen("gift1.out", "w");

    int np, money[MAX_NP], balance[MAX_NP];
    char names[MAX_NP][MAX_NAME_LEN];
    fscanf(fin, "%d", &np);

    // Input names and initialize balance to 0
    for (int i = 0; i < np; i++) {
        fscanf(fin, "%s", names[i]);
        balance[i] = 0;
    }

    // Input gift-giving information and update balances
    for (int i = 0; i < np; i++) {
        char giver[MAX_NAME_LEN];
        int total_gift, num_receivers;
        fscanf(fin, "%s %d %d", giver, &total_gift, &num_receivers);

        int giver_index;
        for (int j = 0; j < np; j++) {
            if (strcmp(giver, names[j]) == 0) {
                giver_index = j;
                break;
            }
        }

        if (num_receivers > 0) {
            int gift_per_person = total_gift / num_receivers;
            balance[giver_index] -= gift_per_person * num_receivers;
            for (int j = 0; j < num_receivers; j++) {
                char receiver[MAX_NAME_LEN];
                fscanf(fin, "%s", receiver);

                int receiver_index;
                for (int k = 0; k < np; k++) {
                    if (strcmp(receiver, names[k]) == 0) {
                        receiver_index = k;
                        break;
                    }
                }

                balance[receiver_index] += gift_per_person;
            }
        }
    }

    // Output final balances
    for (int i = 0; i < np; i++) {
        fprintf(fout, "%s %d\n", names[i], balance[i]);
    }

    fclose(fin);
    fclose(fout);
    return 0;
}