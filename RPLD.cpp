// http://www.spoj.com/problems/RPLD/
#include <stdio.h>
#include <utility>
#include<set>
using namespace std;

typedef pair<int,int> P;

int main(){
    //freopen ("input.txt","r",stdin);
    int T,N,R,I,C;
    bool possible;
    set<P> mySet;
    set<P>::iterator it;
    P myPair;

    scanf("%d",&T);

    for(int i=0;i<T;i++){
        possible=true;
        scanf("%d",&N);
        scanf("%d",&R);
        for(int j=0;j<R;j++){
            scanf("%d",&I);
            scanf("%d",&C);
            myPair=make_pair(I,C);
            it=mySet.find(myPair);
            if(it!=mySet.end()){
                possible=false;
            }else{
                mySet.insert(myPair);
            }
        }
        if(possible) printf("Scenario #%d: possible\n",i+1);
        else printf("Scenario #%d: impossible\n",i+1);
        mySet.clear();
    }
    //fclose (stdin);
    return 0;
}
