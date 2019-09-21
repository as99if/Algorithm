#include<iostream>

using namespace std;

float weight[20], profit[20], itemnumber[20];
float value[20];

void sort(int len){                         //value onujayi sort
    for (int i = 0; i < len; i++) {
      for (int j = i + 1; j < len; j++) {
         if (value[i] < value[j]) {
            int temp = value[j];
            value[j] = value[i];
            value[i] = temp;

            temp = weight[j];
            weight[j] = weight[i];
            weight[i] = temp;

            temp = profit[j];
            profit[j] = profit[i];
            profit[i] = temp;

            temp = itemnumber[j];
            itemnumber[j] = itemnumber[i];
            itemnumber[i] = temp;
         }
      }
   }
}

float min(float a, float b){
    if(a<b)
        return a;
    else
        return b;
}

void knapsack(int len, int capacity){
    float totalprofit=0, ammount=0, taken_weight=0;
    int i=0;
    while(taken_weight<capacity){
            ammount = min(weight[i], capacity - taken_weight);
            taken_weight = taken_weight + ammount;
            totalprofit = totalprofit + ammount*weight[i];
           // capacity = capacity - taken_weight;
            cout<<ammount<<" of item "<<itemnumber[i]<<endl;
            i++;
        }

    cout<<"Maximum profit : "<<totalprofit<<endl;
}


int main(){
    int i,j, len, capacity;

    cout<<"Input lenber of items :";
    cin>>len;
    for(i=0; i<len; i++){
        cout<<"Input weight and profit of item "<<i+1<<" : ";
        cin>>weight[i]>>profit[i];
        itemnumber[i]=i+1;
        value[i]=profit[i]/weight[i];
    }
    cout<<"Input capacity of knapsack : ";
    cin>>capacity;

    sort(len);

    knapsack(len, capacity);

return 0;
}
