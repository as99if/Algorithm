#include<iostream>

using namespace std;

struct item{
    int weight, value;
}input[10];

int n, sack_Weight, table[20][20] = {0};

int max(int i, int j){
    if(i >= j)
        return i;
    else
        return j;
}


int create_knapsack(struct item x[], int W){
    int w;

    for(int i=1; i <= n; i++){
        for(w=1; w <= W; w++){
            if(x[i].weight > w){
                table[i][w] = table[i-1][w];
            }
            else
                table[i][w] = max( table[i-1][w] , ( x[i].value + table[i-1][w - x[i].weight] ) );
        }
    }
return table[n][W];
}

void find_items(int n, int W){
    int i=n, j=W;
    while(i>0 && j>0){
        if(table[i][j] != table[i-1][j]){
            cout<<"item "<<i<<endl;
            i=i-1;
            j=j-input[i].weight;
        }
        else
            i=i-1;
    }
}

int main(){
    cout<<"Input number of items : ";
    cin>>n;
    cout<<"Input weight of sack : ";
    cin>>sack_Weight;

    for(int i=1; i<=n; i++){
        cout<<"\nInput Item - "<<i<<" - its value and weight : ";
        cin>>input[i].value>>input[i].weight;
    }

    cout<<"\n\n"<<"Optimal benefit "<<create_knapsack(input, sack_Weight)<<endl;

    for(int i=0; i<=n; i++){
        for(int j=0; j<=sack_Weight; j++){
            cout<<table[i][j]<<"   ";
        }
        cout<<"\n";
    }
    cout<<"Items :"<<endl;
    find_items(n, sack_Weight);
return 0;
}

