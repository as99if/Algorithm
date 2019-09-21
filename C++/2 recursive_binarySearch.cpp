#include<iostream>
                //recursive binary search
using namespace std;

int recursive_binarySearch(int a[], int low, int high, int mid, int key){

    if(low>high)
        return 0;
    else{
        mid = (low+high)/2;
        if(a[mid]==key){
            return 1;
        }
        else if(key<a[mid])
            recursive_binarySearch(a, low, mid-1, mid, key);    //low=mid-1
        else if(key>a[mid])
            recursive_binarySearch(a, mid+1, high, mid, key);  //high=mid+1
    }

}

int main(){
    int n, a[50], i, key, found;
    cout<<"Input length of array : "<<endl;
    cin>>n;
    cout<<"Input the array :"<<endl;        //input array must be sorted
    for(i=0; i<n; i++)
        cin>>a[i];
    cout<<"Input key to search : "<<endl;
    cin>>key;
    found=recursive_binarySearch( a, 0, n-1, 0, key);  // low=0; high=n-1
    if(found==1)
        cout<<"Found"<<endl;
    else
        cout<<"Not Found"<<endl;
return 0;
}

