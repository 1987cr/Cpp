/*  http://www.spoj.com/problems/RPLN/  */

#include<stdio.h>
#include<math.h>
#include<string.h>
using namespace std;

const int MAX=100010;
int score[MAX];

class SegmentTree{
private:
    int *tree,sz;
public:
    SegmentTree(const int &n){
        sz=2*((int)pow(2,ceil((((int)log2(n))+1))));
        tree=new int[sz];
        cleanTree();
    }
    ~SegmentTree(){
        delete tree;
    }

    void initialize(int i,int start,int end){
        if(start==end){
            tree[i]=start;
        }else{
            int mid=(start+end)/2;
            initialize(2*i,start,mid);
            initialize(2*i+1,mid+1,end);
            if(score[tree[2*i]]<=score[tree[2*i+1]]) tree[i]=tree[2*i];
            else tree[i]=tree[2*i+1];
        }
    }
    int query(int i,int start,int end,int a,int b){
        int id1,id2,mid;
        if (a>end || b<start) return -1;
        if (start>=a && end<=b) return tree[i];
        mid = (start+end)/2;
        id1 = query(2*i,start,mid,a,b);
        id2 = query(2*i+1,mid+1,end,a,b);
        if (id1==-1) return id2;
        if (id2==-1) return id1;
        if(score[id1]<=score[id2]) return id1;
        else return id2;
    }
    void cleanTree(){
        for(int i=0;i<sz;i++) tree[i]=-1;
    }
};

int main(){
	//freopen("RPLN.in","r",stdin);
	int t,n,q,a,b;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        scanf("%d",&n);
        scanf("%d",&q);
        SegmentTree mySegmentTree(n);
        for(int j=0;j<n;j++) scanf("%d",&score[j]);
        mySegmentTree.initialize(1,0,n-1);
        printf("Scenario #%d:\n\n",i);
        for(int k=0;k<q;k++){
            scanf("%d%d",&a,&b);
            printf("%d\n",score[mySegmentTree.query(1,0,n-1,a-1,b-1)]);
        }
    }
	//fclose(stdin);
    return 0;
}

