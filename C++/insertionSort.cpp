#include<iostream>

using namespace std;


void insertionSort(int a[], int n){
	int i, j;
	for(i=1;i<n;i++){           //first er ta sorted ase dhorbo
		for(j = i; j>0 ; j--){
		    if(a[j]<a[j-1]){
                int temp = a[j];        //swap(a[k],a[k-1]);
                a[j] = a[j-1];
                a[j-1] = temp;
		    }

		}

	}
}

int main(){
    int  i, n;
    int num[100];
    cout<<"Input the length of array :"<<endl;
    cin>>n;
    cout<<"Input : "<<endl;
    for(i=0; i<n; i++)
        cin>>num[i];
    insertionSort(num, n);
    cout<<"output :"<<endl;
    for (i=0;i<n ;i++ )
    	cout<<num[i]<<endl;

return 0;
}
