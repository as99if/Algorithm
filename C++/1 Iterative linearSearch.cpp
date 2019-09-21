#include<iostream>
                        //iterative means using loops
using namespace std;

void linearSearch(int a[], int n, int key){
    int i, found=0;
    for(i=0; i<n; i++){
        if(key==a[i]){
            found=1;
            cout<<key<<" found at index "<< i+1<<endl;
            break;
        }
    }
    if(found==0)
        cout<<"Not found"<<endl;
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
    linearSearch( a, n, key);
return 0;
}
