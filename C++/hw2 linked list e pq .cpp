#include<iostream>
#include<stdio.h>

using namespace std;

struct element{
    char data;
    int key;
};

typedef struct element element;

struct priority_queue{
    element item;
    struct priority_queue *next;
};

typedef struct priority_queue node;

node *front;
node *prev;


void display(){
    node *matha;
    matha=front;
    if(front==NULL)
        cout<<"No element"<<endl;
    else{
        cout<<"\nQueue : ";
        while(matha!=NULL){
            cout<<matha->item.data<<" -> "<<matha->item.key<<" ; ";
            matha=matha->next;
        }
    }
}


void insert(element v){
    /* Special case for the head end */
    node *temp;
    if(front==NULL){
        front=new node();
        front->item=v;
        front->next=NULL;
    }

    else if (front->item.key <= v.key){
        temp=new node();
        temp->item=v;
        temp->next=front;
        temp=front;
    }
    else
    {
        /* Locate the node before the point of insertion */
        node *current;
        current=front;
        while (current->next!=NULL && current->next->item.key > v.key){
            current = current->next;
        }
        temp=new node();
        temp->item=v;
        temp->next = current->next;
        current->next = temp;
    }
display();
}

element maximum(){
    return front->item;
}

element extract_max(){
    node *dead;
    dead=front;
    front=front->next;
    element max=dead->item;
    delete(dead);
    return max;
}


void increase_key(element x,int k){
    node *temp;
    temp=front;
    node *max;
    while(temp->next!=NULL){
        if(temp->next->item.data == x.data){
            temp->next->item.key=k;

            max=temp->next;
            temp->next=temp->next->next;
            max->next=front;
            front=max;
            display();
            return;
        }
        else
            temp=temp->next;
    }

    display();
}

int main(){
    element a,b,c,d,e;

    a.data='a';
    a.key=3;
    insert(a);
    b.data='b';
    b.key=2;
    insert(b);
    c.data='c';
    c.key=4;
    insert(c);
    d.data='d';
    d.key=1;
    insert(d);


    printf("Maximum %c",maximum().data);
    increase_key(d,5);
    printf("Maximum %c",maximum().data);

    cout<<"\nExtract_Max : "<<extract_max().data;

    display();
return 0;
}
