#include<iostream>

using namespace std;

int array[20], n, heapsize;

int left(int i){
    return 2*i;
}
int right(int i){
    return (2*i+1);
}

void max_heapify(int a[], int i){
    int l=left(i);
    int r=right(r);
    int largest;
    if(l<=heapsize && a[l]>a[i])
        largest=l;
    else
        largest=i;
    if(r<=heapsize && a[r]>a[largest])
        largest=r;

    if(largest != i){
        int temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;
        max_heapify(a, largest);
    }

}

void build_max_heap(int a[]){
    heapsize=n;
    for(int i=n/2; i>=1; i--){
        max_heapify(a, i);
    }
}

void heap_sort(int a[]){
        build_max_heap(a);
        for(int i=n; i>=2 ; i--){
            int temp=a[1];
            a[1]=a[i];
            a[i]=temp;
            heapsize=heapsize-1;
            max_heapify(a, 1);
        }
}

int main(){
    cout<<"Input number of elements : ";
    cin>>n;
    cout<<"\nInput elements : "<<endl;
    for(int i=1; i<=n; i++){
        cin>>array[i];
    }
    heap_sort(array);
    cout<<"\nOutput:"<<endl;
    for(int i=1; i<=n; i++){
        cout<<array[i]<<"  ";
    }

return 0;
}
