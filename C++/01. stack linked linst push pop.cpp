#include<iostream>

using namespace std;

struct list{
    int data;
    struct list *next;
};
typedef struct list node;
node *head, *temp;
node *prev;

void display(){
    node *matha;
    matha=head;
    if(head==NULL)
        cout<<"Empty Stack";
    else{
        cout<<"\nStack : ";
        while(matha!=NULL){
            cout<<matha->data<<" ";
            matha=matha->next;
        }
    }
}
void show_menu(){
    cout<<"\n1. Insert \n2. Delete \n3.Exit"<<endl;
}


void push(int item){                //insertfirst

    if(head==NULL){
        head=new node();
        head->data=item;
        head->next=NULL;
        prev=head;
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

void pop(){
   node *dead;
    if(head->next!=NULL){
        dead=head;
        while(dead->next->next!=NULL){
            dead=dead->next;
        }
        delete(dead->next);
        dead->next=NULL;
        display();
    }
    else if(head->next==NULL){
        delete(head);
        cout<<"Empty queue";
    }
    else
         cout<<"Empty queue";
}



int main(){
    head=NULL;
    int i=1, choice, item;
    do{
        show_menu();
        cin>>choice;
        if(choice==1){
            cout<<"Value : ";
            cin>>item;
            push(item);

        }
        else if(choice==2){
            pop();
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


