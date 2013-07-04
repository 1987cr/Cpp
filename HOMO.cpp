/*  http://www.spoj.com/problems/HOMO/  */

#include<string>
#include<stdio.h>
#include<map>

using namespace std;

int main()
{
    //freopen ("HOMO.in","r",stdin);
    map<int,int> myMap;
    map<int,int>::iterator it;
    int n,k,repeated;
    string operation;
    char input[256];

    scanf("%d",&n);
    gets(input);
    repeated=0;
    for(int i=0;i<n;i++){
        fgets(input,7,stdin);
        scanf("%d",&k);
        operation=input;
        fgets(input,3,stdin);
        if(operation=="insert"){
            myMap[k]++;
            if(myMap[k]==2) repeated++;
        }else{
            it=myMap.find(k);
            if(it==myMap.end()){

            }else{
                if(it->second==1){
                    myMap.erase(it);
                }else{
                    it->second--;
                    if(it->second==1) repeated--;
                }
            }
        }
        if(myMap.size()<=1 && repeated==0) printf("neither\n");
        if(myMap.size()==1 && repeated==1) printf("homo\n");
        if(myMap.size()>1 && repeated==0) printf("hetero\n");
        if(myMap.size()>1 && repeated>0) printf("both\n");

    }
    //fclose(stdin);
    return 0;
}
