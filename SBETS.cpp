/*  http://www.spoj.com/problems/SBETS/  */

#include<string>
#include<stdio.h>
#include<map>
#include<iostream>

using namespace std;

int main(){
    //freopen ("SBETS.in","r",stdin);
    map<string,int> myMap;
    map<string,int>::iterator it;
    string team1,team2;
    int T,goals1, goals2;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        for(int j=0;j<16;j++){
            cin>>team1>>team2;
            scanf("%d",&goals1);
            scanf("%d",&goals2);
            if(goals1>goals2){
                myMap[team1]++;
            }else{
                myMap[team2]++;
            }
        }
        for (it=myMap.begin(); it!=myMap.end(); ++it){
            if(it->second==3){
                printf("%s\n",it->first.c_str());
                break;
            }
        }
        myMap.clear();
    }
    //fclose (stdin);
    return 0;
}
