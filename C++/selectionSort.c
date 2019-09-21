#include <stdio.h>

void selectionSort(int a[]){
	int min;
	int j,k;
	for(j=0;j<10;j++){              // minimum value bair koire swap
		min=j;
		for(k=j+1;k<10;k++){            // ei loop e minimum value value bair korlam
			if(a[k]<a[min])
                min=k;
		}
		int temp = a[j];
		a[j] = a[min];
		a[min] = temp;
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
