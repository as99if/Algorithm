#include<iostream>

using namespace std;


void merge(int A[], int front, int mid, int rear){
    int i, j;

    int n1=mid-front+1;
    int n2=rear-mid;

    int L[n1+1], R[n2+1];       //left ar right duita temporary array nilam

    for(i=0; i<n1; i++)
        L[i]=A[front+i];        //left e assign korlam, mid porjonto

    for(i=0; i<n2; i++)         // mid er por theke right e assign korlam
        R[i]=A[mid+1+i];

    L[n1]=200;          //ekta boro value
    R[n2]=200;          // ''
    i=0, j=0;
    int k;
    for(k=front; k<=rear; k++){             //left choto hole array te jabe
        if(L[i]<=R[j]){
            A[k]=L[i];
            i++;
        }
        else{
            A[k]=R[j];                  //right choto hole array te jabe
            j++;
        }
    }
}

void merge_sort(int A[], int front, int rear){
    if(front<rear){
        int mid=(front+rear)/2;
        merge_sort(A, front, mid);
        merge_sort(A, mid+1, rear);
        merge(A, front, mid, rear);
    }

}

int main(){
    int array[20];
    int n, i;
    cout<<"Input length"<<endl;
    cin>>n;
    cout<<"Input array elements"<<endl;
    for(i=0; i<n; i++)
        cin>>array[i];

    int front=0, rear=n-1;

    merge_sort(array, front, rear);

    cout<<"Sorted :"<<endl;
    for(i=0; i<n; i++)
        cout<<array[i]<<" ";

return 0;
}
