/*  http://www.spoj.com/problems/BEENUMS/  */

#include<stdio.h>

using namespace std;

int main()
{
    //freopen(".in","r",stdin);
    int N,Bee;
    for(;;){
        scanf("%d",&N);
        if(N==-1) break;
        Bee=1;
        for(int i=0;Bee<N;i++) Bee=Bee+i*6;
        if(Bee==N) printf("Y\n");
        else printf("N\n");
    }
    //fclose(stdin);
    return 0;
}
