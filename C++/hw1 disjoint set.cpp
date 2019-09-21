#include<iostream>
#include<stdio.h>

using namespace std;

struct set{
    int value;
    int parent;
    struct set *next;
};

typedef struct set node;

node *front;
node *prev;


void display(){
    node *matha;
    matha=front;
    if(front==NULL)
        cout<<"No Set"<<endl;
    else{
        cout<<"\nSet : ";
        while(matha!=NULL){
            cout<<matha->value<<" at "<<matha->parent<<" ; ";
            matha=matha->next;
        }
    }
}

void make_set(int u){

    if(front==NULL){
        front=new node();
        front->value=u;
        front->parent=u;
        prev=front;
        prev->next=NULL;
    }

    else{
        node *temp;
        temp=new node();
        temp->value=u;
        temp->parent=u;
        prev->next=temp;
        prev=temp;
        prev->next=NULL;
    }
    display();
}

int find_set(int u){
    node *temp;
    temp=front;

    while(temp!=NULL){
        if(temp->value==u){
            //display();
            return temp->parent;
        }
        else
            temp=temp->next;
    }

    if(temp==NULL){
        cout<<"\n\n"<<u<<" Not Found"<<endl;
        return -1;
    }
}

void union_set(int u, int v){
    node *temp;
    temp=front;

    while(temp!=NULL){
        if(temp->value==v){
            temp->parent=find_set(u);
            display();
            return;
        }
        else
            temp=temp->next;
    }
    if(temp==NULL)
        cout<<"No set"<<endl;

}


int main(){

    make_set(2);
    make_set(5);
    make_set(6);
    make_set(7);
    make_set(8);

    union_set(2,8);
    union_set(5,7);
    union_set(2,6);


    if(find_set(6)== find_set(8))
        printf("\n\n6,8 in same Set\n");
    else
        printf("\n\n6,8 in different Set\n");

return 0;
}
