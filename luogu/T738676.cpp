#include<bits/stdc++.h>
using namespace std;
#define LL long long
int hui(string s){
    int ok=1;
    for(int i=0;i<s.size()/2;i++){
        if(s[i] != s[s.size()-1-i])ok=0;        
    }
    return ok;
}
int main(){
    LL T,temp;
    cin>>T;
    LL num[T];
    for(int i=0;i<T;i++)
        cin>>num[i];
    long long b=1;
    int ok=0;
    for(int i=0;i<T;i++){
        ok=0;
        b=1;
        while((num[i]-b)>=0){
            temp=num[i]-b;
            if(hui(to_string(temp))==1){
                ok=1;
                break;
            }
            b*=2; 
        }
        if(ok==1){
            cout<<"Yes"<<'\n';
        }
        else{
            cout<<"No"<<'\n';
        }
    }
}