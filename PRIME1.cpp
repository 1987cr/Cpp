#include<stdio.h>
#include<iostream>

using namespace std;

const int MAX=100000;
int Arr[MAX];

void a(int prim,int m, int n){
    int ini;
    ini=m/prim;
    ini=ini*prim;
    for(int i=ini;i<=n;i=i+prim) if(i!=prim && i>=m) Arr[i-m]=1;
}

int main()
{
    int t,n,m;

    scanf("%d",&t);
    
    for(int k=0;k<t;k++){
        if(k>0) printf("\n");
        scanf("%d",&m);
        scanf("%d",&n);
        for(int i=0;i<n-m+1;++i) Arr[i] = 0;
        for(int i=2;i*i<=n;++i) a(i,m,n);
        for(int i=0;i<n-m+1;++i) if(Arr[i]==0 && m+i!=1) printf("%d\n",m+i);
    }
    //system("PAUSE");
    }
