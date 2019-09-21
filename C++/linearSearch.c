#include<stdio.h>

int main(){
    int num[5], key, i, found =0;
    printf("input : ");
    for(i=0; i<5; i++)
        scanf("%d", &num[i]);
    printf("input key : ");
        scanf("%d", &key);
    for(i=0; i<5; i++){
        if(key==num[i]){
            found=1;
            break;
        }
    }
    if(found==0) printf("not found");
    else printf("found at index number %d", i+1);
return 0;
}
