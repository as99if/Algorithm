#include<iostream>
#include<stdio.h>

using namespace std;

int graph[20][20]={0}, i, j, n;
char vertex[20]={0};
int visited[20], key[20], totalcost=0;
char parent[20];


void make_graph(){
    for( i=0; i<n; i++){
        for( j=i; j<n; j++){
            if(i!=j){
                cout<<"Input cost between "<<vertex[i]<<" and "<<vertex[j]<<" : ";
                cin>>graph[i][j];
                graph[j][i]=graph[i][j];
            }
        }
    }
}

void print_graph(){
    cout<<"   ";
    for(i=0; i<n; i++)
        cout<<vertex[i]<<"  ";
    cout<<"\n";
    for(i=0; i<n; i++){
        cout<<vertex[i]<<"  ";
        for(j=0; j<n; j++){
            cout<<graph[i][j]<<"  ";
        }
        cout<<"\n";
    }
    cout<<"\nvisited array : ";
    for(i=0; i<n; i++)
        cout<<visited[i]<<" ";
    cout<<"\nkey array : ";
    for(i=0; i<n; i++)
        cout<<key[i]<<" ";
    cout<<"\nparent array : ";
    for(i=0; i<n; i++)
        cout<<parent[i]<<" ";

}


void prims(){
    int u, v, l=0;
    key[0]=0;                                               //source initialization
    parent[0]=vertex[0];
    cout<<"prims e dhuklam"<<endl;
    int min;
    //while(count<n){
        for(i=0; i<n; i++){
            cout<<"i = "<<i<<endl;
            min=99;
            for(j=0; j<n; j++){
                if(visited[j]==-1){                         //visited=-1 mane queue e ase
                    cout<<"min khujtesi, j == "<<j<<endl;

                    if(key[j]<=min){
                        min=key[j];
                        u=j;
                    }
                }
            }
            cout<<"min = "<<vertex[u]<<" "<<min<<endl;
            visited[u]=1;                                   //extract-min

            cout<<"adj = ";
            for(v=0; v<n; v++){                             //adjacent khuje kaj korbo
                if(graph[u][v]!=0){
                    if(visited[v]!=1 || graph[u][v]<key[v]){
                        parent[v]=vertex[u];
                        key[v]=graph[u][v];
                        cout<<vertex[v]<<" ";
                    }
                }
                graph[u][v]=0;
                graph[v][u]=0;
            }
            cout<<"adj paisi, next min khujbo"<<endl;
        }
}

void result(){
    for(i=0; i<n; i++){
        cout<<parent[i]<<" + "<<vertex[i]<<endl;
    }
    cout<<" B| B| B| B| ";

}

int main(){
    cout<<"Input number of nodes :";
    cin>>n;
    cout<<"Input all vertex : ";
    for(i=0; i<n; i++){
        cin>>vertex[i];
        key[i]=999;
        parent[i]='null';
        visited[i]=-1;
    }

    make_graph();
    print_graph();
    prims();
    for(i=0; i<n; i++){
        totalcost=totalcost+key[i];
    }
    cout<<"Cost : "<<totalcost<<endl;
    result();
return 0;
}
