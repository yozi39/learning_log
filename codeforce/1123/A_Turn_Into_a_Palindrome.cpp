#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;cin>>T;
    while(T--){
        int n;char c;
        cin>>n>>c;

        string s;cin>>s;
        s=" "+s;

        int ret=0;
        for(int i=1;i<=n/2;i++){
            int j=n-i+1;

            if(s[i]==s[j])continue;

            if(s[i]==c || s[j]==c){
                ret++;
            } else {
                ret+=2;
            }
        }

        cout<<ret<<'\n';
    }
}