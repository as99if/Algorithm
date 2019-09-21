#include<iostream>
#include<stdio.h>

using namespace std;

int graph[20][20]={0}, i, j, n, temp;
char vertex[20]={0};
int visited[20], key[20], commulCost[20], totalcost=0;
char parent[20], source, destination, s, d;
int currentNode, pmin;


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

}

void dijkstra(){
    int v;
    cout<<"DIJKSTRA te dhuklam"<<endl;
    int min;
    while(currentNode!=d){
            if(visited[currentNode]==-1){
                                            //d = destination er index
            for(i=0; i<n; i++){
                if(graph[currentNode][i]!=0){
                    temp=commulCost[currentNode]+graph[currentNode][i];
                        if(temp<commulCost[i])
                            commulCost[i]=temp;
                }
            }


                min=99;
                for(j=0; j<n; j++){
                    if(graph[currentNode][j]!=0){
                        if(graph[currentNode][j]<=min){
                            min=graph[currentNode][j];
                            pmin=j;
                        }
                    }
                }
                                      //minimum neighbour v;



        visited[currentNode]=1;
        }
        currentNode=pmin;


        //}
    }

    //
}



int main(){
    cout<<"Input number of nodes :";
    cin>>n;
    cout<<"Input all vertex : ";
    for(i=0; i<n; i++){
        cin>>vertex[i];
        key[i]=999;
        commulCost[i]=999;
        parent[i]='null';
        visited[i]=-1;
    }
    cout<<"Select source and destination : ";
    cin>>source>>destination;
    for(i=0; i<n; i++){                     //source ar destination er node index s, d
        if(source==vertex[i])
            s=i;
        if(destination==vertex[i])
            d=i;
    }
    currentNode=s;
    commulCost[currentNode]=0;                  //source take common dhore rakhlam

    make_graph();
    print_graph();


    dijkstra();
    cout<<"\n\n"<<commulCost[d]<<endl;

    for(i=0; i<n; i++)
        cout<<" "<<commulCost[i];

    //dijkstra_result_array();
return 0;
}
