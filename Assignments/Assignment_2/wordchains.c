#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Graph.h"
#define MAX_WORD_LENGTH 20
#define FORMAT_STRING "%19s"



int main() {        /* Overall time complexity: O(mn²), n is the number of input words and m is maximum length of the words */
    int i, j, n,  gap;               /* time complexity: O(1) */
    Edge e;                          /* time complexity: O(1) */
    printf("Enter a number: ");      /* time complexity: O(1) */
    scanf("%d", &n);                 /* time complexity: O(1) */
    Graph g = newGraph(n);           /* time complexity: O(1) */
    char words[n][MAX_WORD_LENGTH];  /* time complexity: O(1) */
    for (i=0; i<n; i++){             /* input words, time complexity: O(n) */
        printf("Enter word: ");             /* time complexity: O(n) */
        scanf(FORMAT_STRING, words[i]);     /* time complexity: O(n) */
    }
    for (i=0; i<n; i++){            /*loop all words, time complexity: O(n) */
        for(j=i+1; j<n; j++) {      /*loop all words, time complexity: O(n²) */
            int counter = 0;        /* time complexity: O(n²) */
            int k = 0;              /* time complexity: O(n²) */
            gap = (strlen(words[i]) > strlen(words[j])) ? strlen(words[i]) - strlen(words[j]) : strlen(words[j]) - strlen(words[i]);
                                                     /* gaps between length of words, time complexity: O(n²) */
            if(gap==0){                              /*two words have same length, time complexity: O(n²) */
                while (words[i][k] != '\0') {        /*loop each character in the word, time complexity: O(mn²) */
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
            } else if ( gap == 1){                                  /*the gap of length is 1, time complexity: O(n²) */
                if(strlen(words[i]) > strlen(words[j])){            /*words[i] longer than words[j], time complexity: O(n²) */
                    for(k=0; words[i][k] != '\0';k++){              /*remove 1 character from words[i], time complexity: O(mn²) */
                        char temp[MAX_WORD_LENGTH];
                        strcpy(temp,words[i]);
                        memmove(&temp[k], &temp[k + 1], strlen(temp) - k); /*remove 1 character from words[i], time complexity: O(mn²) */
                        if (strcmp(temp, words[j])== 0){                   /*after removing 1 character, words[i]=word[j], time complexity: O(mn²) */
                            e.v = i;
                            e.w = j;
                            insertEdge(g, e);
                            }
                    }
                } else{                                              /*words[j] longer than words[i], time complexity: O(n²) */
                    for(k=0; words[j][k] != '\0';k++){               /*remove 1 character from words[i], time complexity: O(mn²) */
                        char temp[MAX_WORD_LENGTH];
                        strcpy(temp,words[j]);
                        memmove(&temp[k], &temp[k + 1], strlen(temp) - k);   /*remove 1 character from words[j], time complexity: O(mn²) */
                        if (strcmp(temp, words[i])== 0){                     /*after removing 1 character, words[i]=word[j], time complexity: O(mn²) */
                            e.v = j;
                            e.w = i;
                            insertEdge(g, e);
                        }
                    }
                }

            }
        }
    }

    show(g,n,MAX_WORD_LENGTH,words);               /* dedtails in Graph.c, print adjacency, time complexity: O(n²) */
    printf("\n\n");                                /* time complexity: O(1) */
    FindLongestPath(g,n,MAX_WORD_LENGTH,words);    /* dedtails in Graph.c, overall time complexity: O(n²) */
    freeGraph(g);                                  /* time complexity: O(n²) */
    return 0;                                      /* time complexity: O(1) */
}

