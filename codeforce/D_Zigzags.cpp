#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 3005;

int n;
int a[N];
vector<int> cnt[N];

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++)cnt[i].clear();
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]].push_back(i);
    }

    for(int i=1;i<=n;i++)sort(cnt[i].begin(),cnt[i].end());

    LL ret = 0;
    for(int j=2;j<=n-2;j++){
        for(int k=j+1;k<=n-1;k++){
        auto &x = cnt[a[k]];
        auto &y = cnt[a[j]];

        LL left = lower_bound(x.begin(),x.end(),j)-x.begin();
        LL right = y.end()-upper_bound(y.begin(),y.end(),k);

        ret += left*right;
        }
    }

    cout<<ret<<'\n';
}

int main(){
    int t;cin>>t;
    while(t--)solve();
}