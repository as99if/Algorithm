#include<iostream>

using namespace std;

void insertionSort(int array[], int len){
    int i, j, temp;
    for(i=1; i<len; i++){
        j=i;
        while(j>0 && array[j-1]>array[j]){
            temp=array[j];
            array[j]=array[j-1];
            array[j-1]=temp;
            j=j-1;
        }
    }
}

int main(){
    int len, array[100], i;
    cout<<"Input length : ";
    cin>>len;
    cout<<"Input array :"<<endl;
    for(i=0; i<len; i++)
        cin>>array[i];

    insertionSort(array, len);

    cout<<"Output"<<endl;
    for(i=0; i<len; i++)
        cout<<array[i]<<" ";

return 0;
}
