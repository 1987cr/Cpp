/*  http://www.spoj.com/problems/STAMPS/  */

#include<stdio.h>
#include<queue>
using namespace std;

int main()
{
    //freopen("STAMPS.in","r",stdin);
    int T,stampsToBeat,offeredStamps,friends,borrowedStamps,friendsToBorrow;
    bool didBreak;
    priority_queue<int> myPq;
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        didBreak=false;
        borrowedStamps=0;
        friendsToBorrow=0;
        scanf("%d",&stampsToBeat);
        scanf("%d",&friends);
        for(int j=0;j<friends;j++){
            scanf("%d",&offeredStamps);
            myPq.push(offeredStamps);
        }
        while (!myPq.empty()){
            borrowedStamps+=myPq.top();
            friendsToBorrow++;
            myPq.pop();
            if(borrowedStamps>=stampsToBeat){
                didBreak=true;
                break;
            }
        }
        if(didBreak) printf("Scenario #%d:\n%d\n",i,friendsToBorrow);
        else printf("Scenario #%d:\nimpossible\n",i);
        while (!myPq.empty()){
            myPq.pop();
        }
    }
    //fclose(stdin);
    return 0;
}
