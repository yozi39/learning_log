#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=2e5+5;

int n;
LL a[N];

int main(){
    int T;cin>>T;

    while(T--){
        cin>>n;

        for(int i=1;i<=n;i++){
            cin>>a[i];
            a[i]-=i;
        }

        sort(a+1,a+1+n);

        int ans=1,cnt=1;

        for(int i=2;i<=n;i++){
            if(a[i]==a[i-1])continue;

            if(a[i]==a[i-1]+1){
                cnt++;
            } else {
                cnt=1;
            }

            ans=max(ans,cnt);
        }

        cout<<ans<<'\n';
    }
}
//为什么突然想到 b[i]=a[i]-i
// 元素位置 +1
// 元素数值也 +1
// 收获