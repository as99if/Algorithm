#include<iostream>
#include<stdio.h>
using namespace std;

struct array{
    int item, index;
}s[20];

int i=0;

void make_set(int x){
    s[i].item=x;
    s[i].index=x;
    i++;
}

void union_set(int u, int v){
    for(int j=0; j<20; j++)
        if(s[j].item == v)
            s[j].index = u;

}

int find_set(int x){
    for(int j=0; j<20; j++){
        if(x==s[j].item)
            return s[j].index;
    }
}


int main(){

    make_set(2);
    make_set(5);
    make_set(6);
    make_set(7);
    make_set(8);

    union_set(2,8);
    union_set(5,7);
    union_set(2,6);


    if(find_set(6)== find_set(8))
        printf("\n\n6,8 in same Set\n");
    else
        printf("\n\n6,8 in different Set\n");

return 0;
}
