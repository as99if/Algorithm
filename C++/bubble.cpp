#include<stdio.h>

void bubble(int num[], int n){
    int i, j, temp;
    for(j=0; j<n-1; j++){
        for(i=0; i<n-1; i++){
            if(num[i]>num[i+1]){
                temp=num[i];
                num[i]=num[i+1];
                num[i+1]=temp;
            }
        }
    }
}

int main(){
    int num[100], i, n;
    printf("input array length : ");
    scanf("%d", &n);
    printf("Input :\n");
    for(i=0; i<n; i++)
        scanf("%d", &num[i]);
    bubble(num, n);
    printf("output :\n");
    for(i=0; i<n; i++)
        printf("%d ", num[i]);
return 0;
}
