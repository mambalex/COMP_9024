// Student record implementation ... Assignment 1 COMP9024 17s2
#include <stdio.h>
#include <string.h>
#define LINE_LENGTH 1024

// scan input for a positive integer, returns -1 if none
int readInt(void) {
   char line[LINE_LENGTH];
   int  n;

   fgets(line, LINE_LENGTH, stdin);
   if ( (sscanf(line, "%d", &n) != 1) || n <= 0 )
      return -1;
   else
      return n;
}

// scan input for a positive floating point number, returns -1 if none
float readFloat(void) {
   char  line[LINE_LENGTH];
   float f;

   fgets(line, LINE_LENGTH, stdin);
   if ( (sscanf(line, "%f", &f) != 1) || f <= 0.0 )
      return -1;
   else
      return f;
}

/*** Your code for stage 1 starts here ***/

int readValidID(void) {
	int id, n;
	int count = 1;

	id = readInt();
	n = id;
	while(n >= 10){
	  	count++;
	 	 n = n / 10;
	}
	if(count == 7){
		return id;
	}
	else{
		printf("Not valid. Enter a valid value: ");
		return	readValidID();
	}	
}

int readValidCredits(void) {
	int c;
	c = readInt();
	if(c < 2 || c > 480){
		printf("Not valid. Enter a valid value: ");
		return readValidCredits();
	}
  	return c;
}

float readValidWAM(void) {
  	float WAM;
   	WAM = readFloat();
  	if(WAM >= 50 && WAM <= 100){
   		return WAM;
  	}else{
   		printf("Not valid. Enter a valid value: ");
		return readValidWAM();
   	}
}

void printStudentData(int zID, int credits, float WAM) {
	char Level[5];
	if (WAM >= 85){strcpy(Level,"HD");}
	else if (WAM >= 75 && WAM < 85 ){strcpy(Level,"DN");}
	else if (WAM >= 65 && WAM < 75 ){strcpy(Level,"CR");}
        else if (WAM >= 50 && WAM < 65 ){strcpy(Level,"PS");}
	printf("------------------------\n");
	printf("Student zID: z%d\n", zID );
 	printf("Credits: %d\n", credits);
	printf("Level of performance: %s\n", Level);
	printf("------------------------\n");
   return;  
}

