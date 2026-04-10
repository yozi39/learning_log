#include<bits/stdc++.h>
using namespace std;
int main(){
    string name[110],sos[110];
    int cnt[110]={0};
    int n,ans=0;
    cin>>n;
    for(int i=1;i<n+1;i++){
        cin>>name[i]>>sos[i];
    }
     for(int i = 1; i <= n; i++){ 
        int len = sos[i].length();
        for(int j = 0; j + 2 < len; j++){ 
            if(sos[i].substr(j,3)=="sos"){
                cnt[i]++;
            }
        }
        
        if(cnt[i] > ans){ 
            ans = cnt[i];
        } 
    }
    for(int i=1;i<=n;i++){
        if(cnt[i]==ans){
            cout<<name[i]<<' ';
        }
    }
    cout<<'\n'<<ans;
}