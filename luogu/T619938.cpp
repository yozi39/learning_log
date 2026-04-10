#include<bits/stdc++.h>
using namespace std;
int main(){
    string S;
    int count=0;
    getline(cin,S);
    for(int i=0;i<S.length();i++){
        if(S[i] != ' '){
            if(count%2==0 && S[i] >= 'a'){
                S[i] -= 32;
            }

            else if(count%2 == 1 && S[i] <='Z'){
                S[i] +=32;
            }
            count++;
        }
        else if(S[i] == ' ') count=0;
    }
    cout<<S;
}