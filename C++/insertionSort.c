#include<stdio.h>


void inSort(int a[]){
	int x,y;
	int temp;
	for(x=1;x<10;x++){
		for(y = x; y>0 ; y--){
		    if(a[y]<a[y-1]){
                temp = a[y];
                a[y] = a[y-1];
                a[y-1] = temp;
		    }
		}
	}
}
int main(){
    int  i;
    int num[10];
    printf("Input : ");
    for(i=0; i<10; i++)
        scanf("%d", &num[i]);
    inSort(num);
    printf("output :");
    for (i=0;i<10 ;i++ )
    	printf("%d ",num[i]);

return 0;
}
