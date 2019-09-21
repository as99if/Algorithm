#include<iostream>
                    // Iterative binary search with selection sort
using namespace std;

void selectionSort(int a[], int n){
    int i, j, min, temp;
    for(i=0; i<n; i++){
        min=i;
        for(j=i+1; j<n; j++){
            if(a[min]>a[j]){
                min=j;
            }
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
        }
    }
}

void binarySearch(int a[], int n, int key){
    int found=0, mid;
    int low=0;
    int high=n-1;

    while(low<high){
        mid = (low+high)/2;
        if(a[mid]==key){
            found=1;
            break;
        }
        else if(key<a[mid])
            high=mid-1;
        else if(key>a[mid])
            low=mid+1;
    }
    if(found==0)
        cout<<"Not found"<<endl;
    else
        cout<<"Found"<<endl;
}

int main(){
    int n, a[50], i, key;
    cout<<"Input length of array : "<<endl;
    cin>>n;
    cout<<"Input the array :"<<endl;
    for(i=0; i<n; i++)
        cin>>a[i];
    selectionSort(a, n);

    cout<<"Input key to search : "<<endl;
    cin>>key;

    binarySearch( a, n, key);
return 0;
}
