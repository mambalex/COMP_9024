/**
     main.c

     Program supplied as a starting point for
     Assignment 1: Student record manager

     COMP9024 17s2
**/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

#include "studentRecord.h"
#include "studentLL.h"

void printHelp();
void StudentLinkedListProcessing();



int main(int argc, char *argv[]) {
   int n,i;
   float totalWAM = 0.000;
   float totalCdPt = 0.000;
   float WgAvrWAM = 0.000;

         
   if (argc == 2) {
	n = atoi(argv[1]);
	studentRecordT *std =  malloc(n*sizeof(studentRecordT));
  	assert(std!= NULL);

	for(i = 0; i < n; i++){
	    printf("Enter student ID: ");
	    std[i].zID = readValidID();
	    printf("Enter credit points: ");
	    std[i].credits = readValidCredits();
	    printf("Enter WAM: ");
	    std[i].WAM = readValidWAM(); 
	    	}
	for(i = 0; i < n; i++){
       	    totalCdPt += std[i].credits;
	    totalWAM += std[i].WAM;
	    printStudentData(std[i].zID, std[i].credits, std[i].WAM);
	}
	for(i = 0; i < n; i++){
	    WgAvrWAM += std[i].credits / totalCdPt * std[i].WAM;
	}
       	 printf("Average WAM: %.3f\n",totalWAM/n);
	 printf("Weighted average WAM: %.3f\n",WgAvrWAM);
         free(std);
   } else {
     	 StudentLinkedListProcessing();
   }
   return 0;
}

/* Code for Stages 2 and 3 starts here */

void StudentLinkedListProcessing() {
   int op, ch;

   List list = newLL();  // create a new linked list
   
   while (1) {
      printf("Enter command (a,f,g,p,q, h for Help)> ");

      do {
	 ch = getchar();
      } while (!isalpha(ch) && ch != '\n');  // isalpha() defined in ctype.h
      op = ch;
      // skip the rest of the line until newline is encountered
      while (ch != '\n') {
	 ch = getchar();
      }

      switch (op) {

         case 'a':
         case 'A':
	    ;
	    int cr, zid;
	    float Wam;

	    printf("Enter student ID: ");
	    zid = readValidID();
	    printf("Enter credit points: ");
   	    cr = readValidCredits();
     	    printf("Enter WAM: ");
  	    Wam = readValidWAM(); 
	    insertLL(list, zid, cr, Wam); 
	    break;

         case 'f':
         case 'F':
	    ;
	    int id;
	    printf("Enter student ID: ");
	    id = readValidID();
	    inLL(list, id);
	    break;
	    
         case 'g':
         case 'G':
	    ;
	    int n = 0;
	    float wam = 0.000;
  	    float w_wam = 0.000;
 	    int *pn = &n;
 	    float *pwam = &wam;
  	    float *pw_wam = &w_wam;
	   
	    getStatLL(list, pn, pwam,pw_wam);
	    printf("Number of records: %d\n",n);
	    printf("Average WAM: %.3f\n",wam / n);
	    printf("Average weighted WAM: %.3f\n",w_wam); 
	    break; 
	    
         case 'h':
         case 'H':
            printHelp();
	    break;
	    
         case 'p':
         case 'P':
            showLL(list); 
	    break;

	 case 'q':
         case 'Q':
            dropLL(list);       // destroy linked list before returning
	    printf("Bye.\n");
	    return;
      }
   }
}

void printHelp() {
   printf("\n");
   printf(" A - Add student record\n" );
   printf(" F - Find student record\n" );
   printf(" G - Get statistics\n" );
   printf(" H - Help\n");
   printf(" P - Print all records\n" );
   printf(" Q - Quit\n");
   printf("\n");
}



