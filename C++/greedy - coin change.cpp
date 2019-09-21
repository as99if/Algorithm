#include<iostream>

using namespace std;

void insertion_sort(int array[], int len){
    int i, j, temp;
    for(i=1; i<len; i++){
        j=i;
        while(j>0 && array[j-1]<array[j]){
            temp=array[j];
            array[j]=array[j-1];
            array[j-1]=temp;
            j=j-1;
        }
    }
}

int main(){
    int ammount = 66;
    int coin[4]={10,20,5,1};
    int num=0;
    int i;
    int length=4;
    insertion_sort(coin, length);

    for(i=0; i<length; i++){                    //greedy coin changiong local
        if(coin[i]<=ammount){
            num=ammount/coin[i];
            cout<<num<<" of "<<coin[i]<<endl;
            ammount-=(num*coin[i]);
        }
    }
return 0;
}
