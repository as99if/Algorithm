#include<iostream>

using namespace std;

void bubbleSort(int array[], int len){
    int i, j, temp;
    for(i=1; i<len; i++){
        for(j=0; j<len-1; j++){
            if(array[j]>array[j+1]){
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
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

    bubbleSort(array, len);

    cout<<"Output"<<endl;
    for(i=0; i<len; i++)
        cout<<array[i]<<" ";

return 0;
}
