#include<vector>
#include<stack>
#include<iostream>
#include<stdlib.h> //atoi
#include<stdio.h> //freopen
#include <string>

#define MAX 1000

using namespace std;

vector<int> graph[MAX];
bool visitados[MAX];

//////////
void imprimir(int N){
    for(int k=0;k<N;k++){
        for (vector<int>::iterator it = graph[k].begin() ; it != graph[k].end(); ++it){
            cout << ' ' << *it;
        }
        cout<<endl;
    }
}
//////////
void dfs(int inicio){
    int i;
    cout<<inicio;
    visitados[inicio]=true;
    stack<int> pila;
    pila.push(inicio);
    while(!pila.empty()){
        inicio=pila.top();
        for (i=0;i<graph[inicio].size();i++){
            if(!visitados[ graph[inicio][i] ]){
                visitados[graph[inicio][i]]=true;
                pila.push(graph[inicio][i]);
                cout<<" "<<graph[inicio][i];
                break;
            }
        }
        if(i==graph[inicio].size()) pila.pop();
    }
}
//////////
int main(){
    freopen("datos.in", "r", stdin);
    string i,j;
    int I,J,N,max=0;
    cin>>N;
    for(;;){
        cin>>i;if(i.compare("end")==0) break;
        cin>>j;
        I= atoi(i.c_str());
        J=atoi(j.c_str());
        graph[I].push_back(J);
        graph[J].push_back(I);
    }
    dfs(0);

}
