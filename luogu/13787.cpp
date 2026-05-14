#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=5010;

int n,m;
int d[N][N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        d[x1][y1]++;
        d[x2+1][y1]--;
        d[x1][y2+1]--;
        d[x2+1][y2+1]++;
    }
    LL ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            d[i][j]=d[i][j]+d[i-1][j]+d[i][j-1]-d[i-1][j-1];
            ans+=((i+j)^d[i][j]);
        }
    }
    cout<<ans;
}