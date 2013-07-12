/*  http://www.spoj.com/problems/ALIEN/  */

#include<stdio.h>
#include<algorithm>

using namespace std;

const int MAX=100000;
int station[MAX];

int main(){
	//freopen("ALIENS.in","r",stdin);
	int t,maxPeople,nStations,leftIdx,maxIdx,minPeople,sum;
	scanf("%d",&t);
    for(int i=0;i<t;i++){
        maxIdx=0;
        leftIdx=0;
        sum=0;
        scanf("%d",&nStations);
        scanf("%d",&maxPeople);
        for(int j=0;j<nStations;j++){
            scanf("%d",&station[j]);
            sum+=station[j];
            while(sum>maxPeople){
                sum-=station[leftIdx];
                leftIdx++;
            }
            if(j-leftIdx+1>maxIdx) minPeople=sum;
            maxIdx=max(maxIdx,j-leftIdx+1);
            if(j-leftIdx+1==maxIdx) minPeople=min(minPeople,sum);
        }
        printf("%d %d\n",minPeople,maxIdx);
    }
	//fclose(stdin);
	return 0;
}
