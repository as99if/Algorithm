#include<iostream>

using namespace std;

#define size 3

int a[size] ;

int top=-1;

void display(){
    int i;
    if(top==-1)
        cout<<"Stack Empty"<<endl;

    else{                   //if(top>=0)
        cout<<"\nArray : ";
        for(i=0; i<=top; i++){
            cout<<a[i]<<" ";
        }
    }
}
void show_menu(){
    cout<<"\n\n1. Insert \n2. Delete \n3.Exit"<<endl;
}


void push(int item){
    if(top+1==size){
        cout<<"Stack Overflow"<<endl;
        return;
    }
    else{               //if(top<=size)
        top++;
        a[top]=item;
    }
}

int pop(){
    if(top==-1){
        cout<<"Stack Underflow"<<endl;
        return 0;
    }
    else{           //if(top>=0)
        int out=a[top];
        a[top]=0;
        top--;
        return out;
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
            push(item);
            display();
        }
        else if(choice==2){
            cout<<"\nPop : "<<pop()<<endl;
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

