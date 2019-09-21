#include<iostream>

using namespace std;

struct array{
    char item;
    int key;
}a[20], maxheap, temp;

int heapsize=0;

int parent(int i){
    return i/2;
}
int left(int i){
    return 2*i;
}
int right(int i){
    return (2*i+1);
}

void max_heapify(int i){
    int l=2*i;
    int r=2*i;
    int largest;
    if(l<=heapsize && a[l].key > a[i].key)
        largest=l;
    else
        largest=i;
    if(r<=heapsize && a[r].key > a[largest].key)
        largest=r;

    if(largest != i){
        temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;
        max_heapify(largest);
    }
}

void increase_key(char x, int key){
    int i;
    for(i=1; i<=heapsize; i++){
        if(a[i].item == 'x')
            break;
    }
    if(key<a[i].key)
        cout<<"new key is less"<<endl;
    else
        a[i].key=key;

    while(i>1 && a[parent(i)].key < a[i].key){
        temp=a[i];
        a[i]=a[parent(i)];
        a[parent(i)]=temp;
        i=parent(i);
    }
}

void insert(struct array x){
    heapsize=heapsize+1;
    a[heapsize].item=x.item;
    a[heapsize].key=x.key;
    increase_key(x.item, x.key);
}

int maximum(){
    return a[1].item;
}

int extract_max(){
    if(heapsize>=1){
        maxheap=a[1];
        a[1]=a[heapsize];
        heapsize=heapsize-1;
        max_heapify(1);
        return maxheap.item;
    }
}

void display(){
    cout<<"\nOutput : ";
    for(int i=1; i<=heapsize; i++)
        cout<<a[i].item<<"-"<<a[i].key<<"\t";
}

void showmessage()
{
    cout<<"\n1. Insert \n2.Extract Max \n3.Maximum \n4.Increase Key \n5. Exit"<<endl;
}


int main()
{
    int i=1,choice;
    struct array x;


    do{
            showmessage();
            cout<<"\nEnter your choice:";
            cin>>choice;


            if(choice==1){
                cout<<"\nData:";
                cin>>x.item;
                cout<<"\nKey:";
                cin>>x.key;
                insert(x);
                display();
            }
            else if(choice==2){
                cout<<"\nExtracted Max : "<<extract_max()<<endl;
                display();
            }
            else if(choice==3){
                cout<<"\nMaximum : "<<maximum()<<endl;
                display();
            }
            else if(choice==4)
            {
                cout<<"\nData:";
                cin>>x.item;
                cout<<"\nKey:";
                cin>>x.key;
                increase_key(x. item, x.key);
                display();
            }
            else if(choice==5)
            {
                i=0;
            }
            else{
                cout<<"\nWrong input.\n"<<endl;
            }

    }
    while(i);

    return 0;
}
