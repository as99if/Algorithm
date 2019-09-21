#include<iostream>
                    // Iterative binary search
using namespace std;

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
        cout<<key<<" found at index "<<mid+1<<endl;


}

int main(){
    int n, a[50], i, key;
    cout<<"Input length of array : "<<endl;
    cin>>n;
    cout<<"Input the array :"<<endl;        //input array must be sorted
    for(i=0; i<n; i++)
        cin>>a[i];
    cout<<"Input key to search : "<<endl;
    cin>>key;
    binarySearch( a, n, key);
return 0;
}
