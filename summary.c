#include <stdio.h>
#include <stdlib.h>
#define MAX 50
/*function prototype*/
int* summary(int a[], int length);

int main()
{
	int k;
	int length=0;
	int userArray[MAX];	
	printf("Enter some numbers\n");
		while(scanf("%d", &k) == 1){
		userArray[length] = k;
		length++;	
		}/*while*/
	
	summary(userArray, length);	
	
	return 0;
}/*main*/

int* summary(int a[], int length)
{
	int i;
	int counter = 0;
	int *p;
	p = (int *) malloc(length * sizeof(int));

		if(!p){
		printf("memory allocation failed!");
		exit(0);
		}/*if null*/

	
	//copy a[] to p[]
	

	for(i=0 ; i<length ; i++){

		counter+=a[i];
		p[i] = counter;
		printf("a[%d] is: %d\n",i, a[i]);
		printf("p[%d] is: %d\n\n",i, p[i]);

	}/*for*/

}/*summary*/
