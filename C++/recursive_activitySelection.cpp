#include<iostream>

using namespace std;

struct in{
    char name;
    int start_time, end_time;
};

typedef struct in input;

input x[20], output;
int n;


void recursive_greedy_activity_Selection(int k){
    if(k==0){
        output=x[k];
        cout<<output.name<<" "<<output.start_time<<" "<<output.end_time<<endl;
    }

    int m = k+1;

    while(m<=n && x[m].start_time < x[k].end_time)
        m++;

    if(m<n){
        int i=1;
        output=x[m];
        cout<<output.name<<" "<<output.start_time<<" "<<output.end_time<<endl;
        i++;
        recursive_greedy_activity_Selection(m);
    }
    else
        return;
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
    recursive_greedy_activity_Selection(0);




return 0;
}
