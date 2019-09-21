#include<iostream>

using namespace std;

void selectionSort(int a[], int n){
    int i, j, min, temp;
    for(i=0; i<n-1; i++){           // last dui element n-2 tomo step e swapo hoye sorted hoye jay
        min=i;                      // i<n-1 or i=n-2 porjonto
        for(j=i+1; j<n; j++){
            if(a[min]>a[j]){        //ei loop e khali minimum ber korbe
                min=j;
            }
        temp=a[i];          //unsorted area er prothome niye ashbe minimum k
        a[i]=a[min];
        a[min]=temp;
        }
    }
}

int main(){
    int n, a[50], i, key;
    cout<<"Input length of array : "<<endl;
    cin>>n;
    cout<<"Input the unsorted array :"<<endl;
    for(i=0; i<n; i++)
        cin>>a[i];
    selectionSort(a, n);
    cout<<" Sorted :"<<endl;
    for(i=0; i<n; i++)
        cout<<a[i]<<endl;

return 0;
}
