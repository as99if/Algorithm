#include<iostream>

using namespace std;

struct list{
    int data;
    struct list *next;
};
typedef struct list node;
node *temp, *front, *prev;

void display(){
    node *matha;
    matha=front;
    if(front==NULL)
        cout<<"Empty Queue";
    else{
        cout<<"\nQueue : ";
        while(matha!=NULL){
            cout<<matha->data<<" ";
            matha=matha->next;
        }
    }
}

void show_menu(){
    cout<<"\n1. Insert \n2. Delete \n3. Exit"<<endl;
}


void enqueue(int item){         //insertfirst
   if(front==NULL){
        front=new node();
        front->data=item;
        front->next=NULL;
        prev=front;
    }
    else{
        temp=new node();
        temp->data=item;
        temp->next=NULL;
        prev->next=temp;
        prev=temp;
    }
    display();


}

void dequeue(){

     node *dead;          //deletelast
    if(front!=NULL){
        dead=front;
        front=front->next;
        delete(dead);
    display();
    }
    else
        cout<<"Empty stack";

}

                //deletelast





int main(){
    front=NULL;
    int i=1, choice, item;
    do{
        show_menu();
        cin>>choice;
        if(choice==1){
            cout<<"Value : ";
            cin>>item;
            enqueue(item);


        }
        else if(choice==2){
            dequeue();

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
