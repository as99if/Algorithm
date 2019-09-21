#include<iostream>

using namespace std;

struct in{
    char name;
    int start_time, end_time;
};

typedef struct in input;

input x[20], output;
int n;

void greedy_activity_Selection(input x[]){
    output=x[0];
    cout<<output.name<<" "<<output.start_time<<" "<<output.end_time<<endl;
    for(int i=1; i<n; i++){
        if(x[i].start_time >= output.end_time){
            output=x[i];
            cout<<output.name<<" "<<output.start_time<<" "<<output.end_time<<endl;
        }
    }
}

void sort(input x[]){
    int i, j;
    input temp;
    for(i=1; i<n; i++){

        j=i;
        while(j>0 && x[j-1].end_time>x[j].end_time){
            temp=x[j];
            x[j]=x[j-1];
            x[j-1]=temp;
            j=j-1;
        }
    }
}

int main(){
    cout<<"Input activity number : ";
    cin>>n;

    for(int i=0; i<n; i++){
        cout<<"Input activity name, start and end time : ";
        cin>>x[i].name>>x[i].start_time>>x[i].end_time;
    }

    sort(x);
    cout<<"/nsorted inputs :"<<endl;
    for(int i=0; i<n; i++){
        cout<<x[i].name<<" "<<x[i].start_time<<" "<<x[i].end_time<<endl;
    }

    cout<<"/n/nSelected activities :"<<endl;
    greedy_activity_Selection(x);


return 0;
}
