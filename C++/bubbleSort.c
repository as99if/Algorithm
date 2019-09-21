#include <stdio.h>

void selectionSort(int a[]){
	int min;
	int i,j;
	for(i=0;i<10;i++){
        for(j=9; j>i; j--){
            if(a[i]>a[j]){
                int temp=a[j];
                a[j]=a[i];
                a[i]=temp;
            }
        }
	}
}
int main(){
    int num[10];
    int i;
    printf("input : ");

    for (i=0;i<10 ;i++ )
    	scanf("%d ",&num[i]);
    printf("\n");
    selectionSort(num);

    printf("output:");
    for (i=0;i<10 ;i++ )
    	printf("%d ",num[i]);

return 0;
}
