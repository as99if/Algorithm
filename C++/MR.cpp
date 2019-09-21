#include<iostream>

using namespace std;

struct file{
    string name;
    int size, criminal;
}input[10];

int n, USB_size, table[20][20] = {0};

int max(int i, int j){
    if(i >= j)
        return i;
    else
        return j;
}


int create_knapsack(struct file x[], int S){
    int s;

    for(int i=1; i <= n; i++){
        for(s=1; s <= S; s++){
            if(x[i].size > s){
                table[i][s] = table[i-1][s];
            }
            else
                table[i][s] = max( table[i-1][s] , ( x[i].criminal + table[i-1][s - x[i].size] ) );
        }
    }
return table[n][S];
}

void find_items(int n, int S){
    int i=n, j=S;
    while(i>0 && j>0){
        if(table[i][j] != table[i-1][j]){
            cout<<"File "<<i<<endl;
            i=i-1;
            j=j-input[i].size;
        }
        else
            i=i-1;
    }
}

int main(){
    cout<<"Input number of files : ";
    cin>>n;
    cout<<"Input size of USB drive : ";
    cin>>USB_size;

    for(int i=1; i<=n; i++){
        cout<<"\nInput File - "<<i<<" - its name, number of criminals and size : ";
        cin>>input[i].name>>input[i].criminal>>input[i].size;
    }

    cout<<"\n\n"<<"Optimal number of criminals "<<create_knapsack(input, USB_size)<<endl;


    for(int i=0; i<=n; i++){
        for(int j=0; j<=USB_size; j++){
            cout<<table[i][j]<<"   ";
        }
        cout<<"\n";
    }
    cout<<"Files taken : "<<endl;
    find_items(n, USB_size);
return 0;
}


