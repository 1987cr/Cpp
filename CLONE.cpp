/*  http://www.spoj.com/problems/CLONE/  */

#include<string>
#include<stdio.h>
#include<map>
#include<iostream>

#define MAX 20000

using namespace std;
int myVector[MAX];

int main(){
    //freopen ("CLONE.in","r",stdin);
    map<string,int> myMap;
    map<string,int>::iterator it;
    int n,m;
    string DNA;
    for(;;){
        scanf("%d",&n);
        scanf("%d",&m);
        if(n==0 && m==0) break;
        for(int j=0;j<n;j++){
            cin>>DNA;
            myMap[DNA]++;
        }
        for (it=myMap.begin(); it!=myMap.end(); ++it) myVector[it->second]++;
        for (int j=1;j<=n;j++){
            printf("%d\n",myVector[j]);
            myVector[j]=0;
        }
        myMap.clear();
    }
    //fclose (stdin);
    return 0;
}
