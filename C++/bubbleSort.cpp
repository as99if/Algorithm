#include<iostream>

using namespace std;

void bubble(int num[], int n){
    int i, j, temp;
    for(j=0; j<n-1; j++){           //pashapashi duita duita kore swap kore
        for(i=0; i<n-1; i++){
            if(num[i]>num[i+1]){
                temp=num[i];
                num[i]=num[i+1];
                num[i+1]=temp;
            }
        }
    }
}

int main(){
    int num[100], i, n;
    cout<<"input array length :"<<endl;
    cin>>n;
    cout<<"Input :"<<endl;
    for(i=0; i<n; i++)
        cin>>num[i];
    bubble(num, n);
    cout<<"output :"<<endl;
    for(i=0; i<n; i++)
        cout<<num[i]<<endl;
return 0;
}
