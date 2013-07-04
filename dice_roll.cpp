#include<iostream>
#include<time.h>
#include<string>
#include <stdlib.h>

using namespace std;

int main(){
    srand(time(NULL));
    string input;
    cin>>input;
    for(int j=0;j<atoi(input.substr(0,input.find('d')).c_str());j++)
        cout<<rand()%(atoi(input.substr(input.find('d')+1,input.length()).c_str()))+1<<" ";
    return 0;
}
