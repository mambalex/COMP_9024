#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "studentLL.h"
#include "studentRecord.h"

// linked list node type
// DO NOT CHANGE
typedef struct node {
    studentRecordT data;
    struct node    *next;
} NodeT;

// linked list type
typedef struct ListRep {
   NodeT *head;

/* Add more fields if you wish */

} ListRep;

/*** Your code for stages 2 & 3 starts here ***/

// Time complexity:  O(1) 
// Explanation:  The time complexity of each step as shown in the following
// 	         PrefixAverages = 3 * O(1) =  O(1)

List newLL() {
   ListRep *list = malloc(sizeof(ListRep));	//O(1)
   list -> head = NULL;				//O(1)
   return list;  }				//O(1)


// Time complexity: O(n)
// Explanation:  The time complexity of each step as shown in the following
//		 PrefixAverages = 3 * O(1) + 4 * O(n) = O(n)

void dropLL(List listp) {
	NodeT *p;			//O(1)
	p = listp ->head;		//O(1)
	while (p != NULL) {		//O(n)
     	 NodeT *temp = p->next;		//O(n)
     	 free(p);			//O(n)
     	 p = temp;			//O(n)
}
   return; 				//O(1)
} 


// Time complexity:   O(n)
// Explanation:  The time complexity of each step as shown in the following
//		 PrefixAverages = 11 * O(1) + 3 * O(n) = O(n)

void inLL(List listp, int zid) {
	NodeT *p;         //O(1)
	char Level[5];    //O(1)
		for(p = listp->head; p != NULL; p = p->next){     //O(n)
		if (p -> data.zID == zid){		     	  //O(n)
			if (p -> data.WAM >= 85){strcpy(Level,"HD");}     			    //O(1)
			else if (p -> data.WAM >= 75 && p -> data.WAM < 85 ){strcpy(Level,"DN");}   //O(1)
			else if (p -> data.WAM >= 65 && p -> data.WAM < 75 ){strcpy(Level,"CR");}   //O(1)
       			else if (p -> data.WAM >= 50 && p -> data.WAM < 65 ){strcpy(Level,"PS");}   //O(1)
			printf("------------------------\n");	 	//O(1)
			printf("Student zID: z%d\n",p -> data.zID);	//O(1)
 			printf("Credits: %d\n",p -> data.credits);	//O(1)
			printf("Level of performance: %s\n",Level);	//O(1)
			printf("------------------------\n");		//O(1)
		
		}else if(p -> next == NULL){			//O(n)
			printf("No record found.\n");		//O(1)
		}

	}

}


// Time complexity: O(n)
// Explanation:  The time complexity of each step as shown in the following
//		 PrefixAverages = 32 * O(1) + 4 * O(n) = O(n)

void insertLL(List listp, int zid, int cr, float wam) {
     NodeT *k;	//O(1)
     NodeT*  new_node = malloc(sizeof(NodeT));		//O(1)
	     new_node -> data.zID = zid;		//O(1)
	     new_node -> data.credits = cr;		//O(1)
	     new_node -> data.WAM = wam;		//O(1)
	     if(listp -> head == NULL ){		//O(1)
		new_node -> next = NULL;		//O(1)
		listp -> head  = new_node;		//O(1)
		 printf("Student record added.\n");	//O(1)
		 return;				//O(1)
	         }
	     else if(listp -> head -> data.zID > zid ){		//O(1)
	              new_node -> next = listp -> head;		//O(1)
		      listp -> head = new_node; 		//O(1)
		      printf("Student record added.\n");	//O(1)
		      return;					//O(1)
      
	       }
	     else if(listp -> head -> data.zID == zid ){	//O(1)
		       new_node -> next = listp -> head -> next;//O(1)
		       listp -> head = new_node;		//O(1)
		       printf("Student record updated.\n");	//O(1)
	     		return;					//O(1)
	     }

 	     for(k = listp -> head; k != NULL; k = k -> next){	//O(n)
      	       if( k -> data.zID < zid && k -> next == NULL){	//O(n)
		    k -> next = new_node;			//O(1)
		    new_node -> next = NULL;			//O(1)
	            printf("Student record added.\n");		//O(1)
	            return;
	       }
	       else if(k -> next -> data.zID == zid){		//O(n)
		     new_node -> next = k -> next -> next;	//O(1)
		     k -> next = new_node;			//O(1)
		     printf("Student record updated.\n");	//O(1)
		    return;					//O(1)
		    
	       }
	       else if(k -> data.zID < zid && zid < k -> next -> data.zID ){	//O(n)
		new_node -> next = k -> next;					//O(1)
		k -> next = new_node;						//O(1)
	        printf("Student record added.\n");				//O(1)
		return;								//O(1)
		}
	     }  	
   return;		//O(1)
}


// Time complexity: O(n)
// Explanation:  The time complexity of each step as shown in the following
//		 PrefixAverages = 3 * O(1) + 6 * O(n) = O(n)

void getStatLL(List listp, int *n, float *wam, float *w_wam) {
	NodeT *p;		//O(1)
	float credits = 0;	//O(1)

	for(p = listp -> head; p != NULL; p = p -> next){	//O(n)
	 *n += 1;						//O(n)
	 credits += p -> data.credits;				//O(n)
	 *wam += p -> data.WAM;					//O(n)
		}
	for(p = listp -> head; p != NULL; p = p -> next){	//O(n)
	 *w_wam += p -> data.credits / credits * p -> data.WAM;	//O(n)
	}
   return; } 	//O(1)

// Time complexity: O(n)
// Explanation:  The time complexity of each step as shown in the following
//		 PrefixAverages = 5 * O(1) + 13 * O(n) = O(n)

void showLL(List listp) {
	char Level[5];		//O(1)
	int credits,zID;	//O(1)
        float WAM;		//O(1)
	NodeT *p;		//O(1)
	for(p = listp -> head; p != NULL; p = p -> next){	//O(n)
	 zID = p -> data.zID;					//O(n)
	 credits = p -> data.credits;				//O(n)
	 WAM = p -> data.WAM;					//O(n)

	if (WAM >= 85){strcpy(Level,"HD");}			//O(n)
	else if (WAM >= 75 && WAM < 85 ){strcpy(Level,"DN");}	//O(n)
	else if (WAM >= 65 && WAM < 75 ){strcpy(Level,"CR");}	//O(n)
        else if (WAM >= 50 && WAM < 65 ){strcpy(Level,"PS");}	//O(n)
	printf("------------------------\n");			//O(n)
	printf("Student zID: z%d\n",zID );			//O(n)
 	printf("Credits: %d\n",credits);			//O(n)
	printf("Level of performance: %s\n",Level);		//O(n)
	printf("------------------------\n");			//O(n)
	}
        return;	//O(1)

}
