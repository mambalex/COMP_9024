#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Graph.h"
#define MAX_WORD_LENGTH 20
#define FORMAT_STRING "%19s"



int main() {
    int i, j, n,  gap;
    Edge e;
    printf("Enter a number: ");
    scanf("%d", &n);
    Graph g = newGraph(n);
    char words[n][MAX_WORD_LENGTH];
    for (i=0; i<n; i++){
        printf("Enter word: ");
        scanf(FORMAT_STRING, words[i]);
    }
    for (i=0; i<n; i++){
        for(j=i+1; j<n; j++) {
            int counter = 0;
            int k = 0;
            gap = (strlen(words[i]) > strlen(words[j])) ? strlen(words[i]) - strlen(words[j]) : strlen(words[j]) - strlen(words[i]);
            if(gap==0){
                while (k < MAX_WORD_LENGTH) {
                    if (words[i][k] == '\0' || words[j][k] == '\0'){
                        break; }
                    if (words[i][k] != words[j][k]) {
                        counter += 1;
                        k += 1;
                    } else { k += 1; }
                }
                if (counter == 1){
                    e.v = i;
                    e.w = j;
                    insertEdge(g, e);
                }
            } else if ( gap == 1){
                if(strlen(words[i]) > strlen(words[j])){
                    for(k=0; words[i][k] != '\0';k++){
                        char temp[MAX_WORD_LENGTH];
                        strcpy(temp,words[i]);
                        memmove(&temp[k], &temp[k + 1], strlen(temp) - k);
                        if (strcmp(temp, words[j])== 0){
                            e.v = i;
                            e.w = j;
                            insertEdge(g, e);
                            }
                    }
                } else{
                    for(k=0; words[j][k] != '\0';k++){
                        char temp[MAX_WORD_LENGTH];
                        strcpy(temp,words[j]);
                        memmove(&temp[k], &temp[k + 1], strlen(temp) - k);
                        if (strcmp(temp, words[i])== 0){
                            e.v = j;
                            e.w = i;
                            insertEdge(g, e);
                        }
                    }
                }

            }
//            printf("%s\t%s\t%d\n", words[i], words[j], counter);
        }
    }
    show(g,n,MAX_WORD_LENGTH,words);
    printf("\n\n");
    FindLongestPath(g,n,MAX_WORD_LENGTH,words);
    freeGraph(g);
    return 0;
}

