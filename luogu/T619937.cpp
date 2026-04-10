#include<bits/stdc++.h>
using namespace std;
int main(){
    string input;
    cin>>input;
    int len=input.length();
    for(int i=0;i<len;i++){
        switch (input[i])
        {
        case 'A':
            input[i] = 'T';
            break;
        case 'T':
            input[i] = 'A';
            break;
        case 'G':
            input[i] = 'C';
            break;
        case 'C':
            input[i] = 'G';
            break;
        default:
            break;
        }
    }
    cout<<input;
}