#include<bits/stdc++.h>
using namespace std;

const int N=55,P=1e9+7;
int m[N];

int main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>m[i];
    sort(m+1,m+n+1);
    
    int cnt=0;
    long long ans=1;
    for(int i=1;i<=n;i++){
        if(cnt<m[i]){
            ans = ans*(m[i]-cnt)%P;
        }
        else{
            cout<<0;
            return 0;
        }
        cnt++;
    }
    cout<<ans;
}