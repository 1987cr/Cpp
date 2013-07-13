/*  http://www.spoj.com/problems/ARRAYSUB/  */

#include<stdio.h>
#include<math.h>
#include<string.h>
using namespace std;

const int MAX=1000010;
int myArray[MAX];

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
            if(myArray[tree[2*i]]>=myArray[tree[2*i+1]]) tree[i]=tree[2*i];
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
        if(myArray[id1]>=myArray[id2]) return id1;
        else return id2;
    }
    void cleanTree(){
        for(int i=0;i<sz;i++) tree[i]=-1;
    }
    /*void printTree(){
        for(int i=0;i<sz;i++) printf("%d",tree[i]);
    }*/
};

int main(){
    freopen("ARRAYSUB.in","r",stdin);
    int n,k,a,b;
    b=0;
    scanf("%d",&n);
    SegmentTree mySegmentTree(n);
    for(int j=0;j<n;j++) scanf("%d",&myArray[j]);
    mySegmentTree.initialize(1,0,n-1);
    scanf("%d",&k);
    for(int i=0;b<n-1;i++){
        a=i;
        b=a+k-1;
        printf("%d ",myArray[mySegmentTree.query(1,0,n-1,a,b)]);
    }
    fclose(stdin);
    return 0;
}

