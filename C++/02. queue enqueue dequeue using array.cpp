#include<iostream>

using namespace std;

#define size 4

int a[size+1] ;

int f=0, r=0;

void display(){
    int i, s;
        cout<<"\nArray : ";
        if(f==r){
            cout<<"Queue is empty"<<endl;
        }

        if(f!=r){
            for(i=f; i<r; i=s){
                 s=(i+1)%(size+1);
                 cout<<a[s]<<" ";
            }
        }



}

void show_menu(){
    cout<<"\n1. Insert \n2. Delete \n3. Exit"<<endl;
}


void enqueue(int item){
    int s;
    s=(r+1)%(size+1);
    if(s==f)
        cout<<"Queue is full"<<endl;
    else{
        a[s]=item;
        r=s;
    }
}

void dequeue(){
    int s;
    s=(f+1)%(size+1);
    if(f==r){
        cout<<"Queue is empty"<<endl;
    }

    else{
        a[s]=0;
        f=s;
    }
}




int main(){
    int i=1, choice, item;
    do{
        show_menu();
        cin>>choice;
        if(choice==1){
            cout<<"Value : ";
            cin>>item;
            enqueue(item);
            display();

        }
        else if(choice==2){
            dequeue();
            display();
        }
        else if(choice=3){
            i=-1;
        }
        else{
            cout<<"Wrong Choice"<<endl;
        }
    }while(i==1);
return 0;
}
