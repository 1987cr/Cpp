/*  http://www.spoj.com/problems/PRESIDEN/  */

#include<stdio.h>
#include<list>
#include<map>

using namespace std;

const int MAX=110;
list<int> myList[MAX];

int main()
{
    //freopen("PRESIDEN.in","r",stdin);
    map<int,float> myMap;
    map<int,float>::iterator it;

    int T,C,V,preference,firstP,secondP;
    double percentage;

    scanf("%d",&T);

    for(int i=0;i<T;i++){
        scanf("%d",&C);
        scanf("%d",&V);
        for(int j=0;j<V;j++){
            for(int k=0;k<C;k++){
                scanf("%d",&preference);
                if(k==0){
                    percentage=(1/(float)V)*100.00;
                    myMap[preference]=myMap[preference]+percentage;
                }
                myList[j].push_back(preference);
            }
        }
        percentage=0;
        for(it=myMap.begin();it!=myMap.end();it++){
            if(it->second>percentage){
                firstP=it->first;
                percentage=it->second;
            }
        }
        if(percentage>50.00){
            printf("%d 1\n",firstP);
        }else{
            it=myMap.find(firstP);
            myMap.erase(it);
            percentage=0;
            for(it=myMap.begin();it!=myMap.end();it++){
                if(it->second>percentage){
                    secondP=it->first;
                    percentage=it->second;
                }
            }
            myMap.clear();
            for(int h=0;h<V;h++){
                for (list<int>::iterator itl=myList[h].begin(); itl != myList[h].end(); ++itl){
                    if((*itl)==firstP || (*itl)==secondP){
                        myMap[*itl]++;
                        break;
                    }
                }
            }
            percentage=0;
            for(it=myMap.begin();it!=myMap.end();it++){
                if(it->second > percentage){
                    firstP=it->first;
                    percentage=it->second;
                }
            }
            printf("%d 2\n",firstP);
        }

        for(int h=0;h<110;h++) myList[h].clear();
        myMap.clear();
    }
    //fclose(stdin);
    return 0;
}
