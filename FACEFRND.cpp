/*  http://www.spoj.com/problems/FACEFRND/  */

#include<stdio.h>
#include<set>

using namespace std;

int main()
{
    //freopen("FACEFRND.in","r",stdin);
    set<int> friends;
    set<int> f_Friends;
    set<int>::iterator it1,it2;
    int N,M,ID;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&ID);
        friends.insert(ID);
        scanf("%d",&M);
        for(int j=0;j<M;j++){
            scanf("%d",&ID);
            f_Friends.insert(ID);
        }
    }
    for(it1=friends.begin();it1!=friends.end();it1++){
        it2=f_Friends.find(*it1);
        if(it2!=f_Friends.end()) f_Friends.erase(it2);
    }
    printf("%d",f_Friends.size());
   //fclose(stdin);
    return 0;
}
