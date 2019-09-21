#include<stdio.h>
#include<iostream>

using namespace std;

void makeChange(int coin[], int n, int value){
    int i, j, k;
    int min_coin[value];

    int count[value+1][n];
    for(i=0; i<value+1; i++){
        for(j=0; j<n; j++)
            count[i][j]=0;
    }
    int min;

    //int count[MAX];
    min_coin[0] = 0;

    for (i=1; i <= value; i++){
        min = 999;
        for (j = 0; j<n; j++){
            if (coin[j] <= i){
                if (min > min_coin[i-coin[j]]+1){
                    min = min_coin[i-coin[j]]+1;

                    for(k = 0; k < n; k++)
                        count[i][k] = count[i-coin[j]][k];

                    count[i][j]++;
                }
            }
        }
        min_coin[i] = min;
    }

    for(int i=0; i<=6; i++)
        cout<<min_coin[i]<<"  ";

    cout<<"\n\n";

    for(int i=0; i<=6; i++){
        for(int j=0; j<4; j++){
            cout<<"   "<<count[i][j];
        }
        cout<<"\n";
    }
    printf("\n\nminimum coins required %d \n", min_coin[value]);
    for( i = 0; i < 4; i++)
        printf("%d: %d\n", coin[i], count[value][i]);

}

int main(){
    int coin[] = {1,2,3,5};
    makeChange(coin, 4, 6 );

return 0;
}
