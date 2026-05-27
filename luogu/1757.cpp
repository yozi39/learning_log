#include<bits/stdc++.h>//P1757
using namespace std;
typedef pair<int,int> PII;

const int N=1010;
int n,m,cnt;
int f[N][N];//在i组 j承重 的最大价值
vector<PII> g[N];//前面是w 后面是v


int main(){
    cin>>m>>n;
    for(int i=1;i<=n;i++){
        int a,b,c;cin>>a>>b>>c;
        cnt=max(c,cnt);//找组数
        g[c].push_back({a,b});
    }

    for(int i=1;i<=cnt;i++){
        for(int j=m;j>=0;j--){
            
            f[i][j]=f[i-1][j];

            for(auto& v:g[i]){
                if(j>=v.first){
                    f[i][j]=max(f[i][j],f[i-1][j-v.first]+v.second);
                }
            }
        }
    }
    cout<<f[cnt][m];
}