#include<stdio.h>

void binarysearch(int num[], int n, int key){
    int low=0, high=n-1;
                                    //algo khata
    while(low<high){
        int mid=(low+high)/2;           //ekhane flooring kora lagbe na, karon int nisi
        if(key==num[mid]){
            printf("found %d at index %d", key, mid+1);
            break;
        }
        else if(key<num[mid])
            high=mid-1;
        else if(key>num[mid])
            low=mid+1;

    }
    if(low>high)
        printf("not found");
}

int main(){
    int num[5], i, key;
    int n=5;
    printf("input array : \n");         //input sorted hote hobe
    for(i=0; i<5; i++)
        scanf("%d", &num[i]);
    printf("input key : ");
    scanf("%d", &key);

    binarysearch(num, n, key);

return 0;
}
