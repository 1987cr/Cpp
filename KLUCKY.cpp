/*  http://www.spoj.com/problems/KLUCKY/  */

#include<stdio.h>
#include<math.h>

using namespace std;

void klucky(int n){
    int i,k;
    double res;
    res=0;
    while(n!=0){
        for(i=0;;i++){
            k=(int)pow(2.0,i);
            if(k>n){
                k=k/2;
                break;
            }
        }
        n=n-k;
        res=res+pow(5.0,i);
    }
    printf("%d\n",(int)res);
}

int main()
{
    int t,n;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%d",&n);
        klucky(n);
    }
    return 0;
}
