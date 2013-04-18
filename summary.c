/*  This program returns the summary of a given array. */

#include <stdio.h>
#include <stdlib.h>
#define MAX 50

/*function prototype*/
void summary(int a[], int length);
void printArray(int array[], int from, int to);

int main(){
	int k;
	int length=0;
	int userArray[MAX];
	printf("Enter up to 50 numbers to get a summary of them:\n");
	while((scanf("%d", &k) ==1)){
		userArray[length] = k;
		length++;

		if(getchar() == '\n'){
			summary(userArray, length);
			length = 0;
			printf("\n");
		}	
	}/*while*/

	summary(userArray, length);
	printf("\n");

	return 0;
}/*main*/

/* The 'summary' function dynamically allocates memory with a size that fits the 
   amount of numbers the user inputed (no greater than 50 numbers).
   if there is not enough memory to allocate, an error is displayed and the program
   terminates, otherwise the summary array is printed using the printArray method
   and the allocated memory is then freed. */
void summary(int a[], int length){
	int i;
	int counter = 0;
	int *p;
	p = (int *) malloc(length * sizeof(int) + 1);

	if(!p){
		printf("memory allocation failed!");
		exit(0);
	}/*if null*/


	for(i=0 ; i<length ; i++){

		counter+=a[i];
		p[i] = counter;

	}/*for*/
	p[length] = '\0';
	printArray(p, 0, length);
	free(p);
}/*summary*/

/* the 'printArray' function is recursively implemented.
   Base case: if end of array is reached, return.
   Otherwise print current number and call 'printArray' starting
   at the next index.  */
void printArray(int array[], int from, int to){
	if(from==to){
		return;
	}
	else{
		printf("%d ", array[from]);
		printArray(array, from+1, to);
	}
}/*prinArray*/
