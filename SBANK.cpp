/*  http://www.spoj.com/problems/SBANK/  */

#include<string>
#include<stdio.h>
#include<map>
#include<iostream>

using namespace std;

int main(){
    //freopen ("SBANK.in","r",stdin);
    map<string,int> myMap;
    map<string,int>::iterator it;
    int n,t;
    string aux;
    char myString[256];

    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%d",&n);
        gets(myString); //?
        for(int j=0;j<n;j++){
            gets(myString);
            aux=myString;
            it=myMap.find(aux);
            if(it==myMap.end()){
                myMap[aux]=1;
            }else{
                myMap[aux]++;
            }
        }
        for(it=myMap.begin();it!=myMap.end();it++) printf("%s %d\n",it->first.c_str(),it->second);
        printf("\n");
        myMap.clear();
    }
    //fclose (stdin);
    return 0;
}
