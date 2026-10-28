#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 3e5+5;
int n,m;
vector<int> pan[N];

void solve(){
    cin>>n>>m;
    vector<LL> cnt(m+1,0);
    LL count = 0;
    for(int i=1;i<=n;i++){
        pan[i].assign(m+1,0);
        for(int j=1;j<=m;j++){
            cin>>pan[i][j];
            if(pan[i][j]){
                cnt[j]++;
                count++;
            }
        }
    }

    vector<char> op;
    LL cur = 0,need = count/2;
    int pos = 1;
    while(pos<=m && cur+cnt[pos]<=need){
        cur += cnt[pos];
        op.push_back('R');
        pos++;
    }

    if(pos<=m){
        int posj = 1;
        LL diff = cnt[pos]-(need-cur);
        // 从上方排除 diff 个1，下面留下 need-cur 个1
        while(diff>0 && posj<=n){
            if(pan[posj][pos])diff--;
            op.push_back('D');
            posj++;
        }
        op.push_back('R');
        for(int i=posj;i<=n;i++)op.push_back('D');
        for(int j=pos+1;j<=m;j++)op.push_back('R');
    } else {
        for(int i=1;i<=n;i++)op.push_back('D');
    }

    cout<<need*(count-need)<<'\n';
    for(auto v:op)cout<<v;
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--)solve();
}