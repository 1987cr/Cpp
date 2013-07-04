#include<iostream>
#include<string>

using namespace std;

string longest(string input){
    int start,charAtIndex,substrLength,maxSubstrLength;
    char charA,charB;
    bool dif;
    string substr;
    maxSubstrLength=0;
    for(start=0;start<input.length()-2;start++){
        charAtIndex=start;
        substrLength=2;
        dif=true;        
        charA=input[charAtIndex];
        charAtIndex++;
        while(input[charAtIndex]==charA){
            charAtIndex++;
            substrLength++;
        }
        if(charAtIndex<input.length()){
            charB=input[charAtIndex];
            charAtIndex++;       
            while(dif){
                if(input[charAtIndex]==charA || input[charAtIndex]==charB) substrLength++;
                else dif=false;
                charAtIndex++;
            }
        }
        if(substrLength>maxSubstrLength){
            maxSubstrLength=substrLength;
            substr=input.substr(start,substrLength);
        }
        if(maxSubstrLength>(input.length()-(start+1))) break;
    }
    return substr;
}

int main(){
    string input;
    cin>>input;    
    cout<<longest(input)<<endl;
    system("PAUSE");
    return 0;
}
