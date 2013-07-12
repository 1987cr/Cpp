/*  http://www.spoj.com/problems/PQUEUE/  */

#include<stdio.h>
#include<queue>
using namespace std;

int main(){
    //freopen("PQUEUE.in","r",stdin);
    priority_queue<int> myPqueue;
    queue<int> myQueue;
    int t,nJobs,myPosition,priority,hours;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        hours=0;
        scanf("%d",&nJobs);
        scanf("%d",&myPosition);
        for(int j=0;j<nJobs;j++){
            scanf("%d",&priority);
            myPqueue.push(priority);
            myQueue.push(priority);
        }
        while (!myPqueue.empty()){
            if(myQueue.front()<myPqueue.top()){
                myQueue.push(myQueue.front());
                myQueue.pop();
                if(myPosition==0) myPosition=myQueue.size()-1;
                else myPosition--;
            }else{
                myQueue.pop();
                myPqueue.pop();
                hours++;
                if(myPosition==0) break;
                else myPosition--;
            }
        }
        printf("%d\n",hours);
        while (!myPqueue.empty()){
            myQueue.pop();
            myPqueue.pop();
        }
    }
    //fclose(stdin);
    return 0;
}
