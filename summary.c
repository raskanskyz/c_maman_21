#include <stdio.h>
#include <stdlib.h>
#define MAX 50

/*function prototype*/
int* summary(int a[], int length);
void printArray(int array[], int i);
int main()
{
	int k;
	int length=0;
	int userArray[MAX];	
	printf("Enter some numbers:\n");
		while(scanf("%d", &k) == 1){
		userArray[length] = k;
		length++;	
		}/*while*/
	
	summary(userArray, length);	
	printf("\n");
	return 0;
}/*main*/

int* summary(int a[], int length){
	int i;
	int counter = 0;
	int *p;
	p = (int *) malloc(length * sizeof(int));

	if(!p){
		printf("memory allocation failed!");
		exit(0);
		}/*if null*/
	

	for(i=0 ; i<length ; i++){

		counter+=a[i];
		p[i] = counter;
	}/*for*/
	printArray(p, 0);
	return p;
	free(p);

}/*summary*/

void printArray(int array[], int i){	
	if(array[i]=='\0')
		return;
	else{
	printf("%d ", array[i]);
	printArray(array, i+1);
	}
}/*prinArray*/
