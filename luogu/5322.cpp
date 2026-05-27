#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=105,M=2e4+10;
int s,n,m;
vector<int> op[N];      //一个玩家(修正模型,一个城堡代表一组)代表一个小组,分组背包
LL f[N][M];

// LL score(int x,int k){//x当前哪个城池,k当前派兵
//     LL cnt=0;
//     for(auto v:op[x]){
//         if(k>v*2)cnt++;
//     }
//     return cnt*x;
// }

int main(){
    cin>>s>>n>>m;
    for(int i=1;i<=s;i++){
        for(int j=1;j<=n;j++){
            int tmp;cin>>tmp;
            op[j].push_back(tmp*2+1);//直接存储要多少兵力
        }
    }

    for(int i=1;i<=n;i++)sort(op[i].begin(),op[i].end());

    int cnt;
    for(int i=1;i<=n;i++){
        for(int j=m;j>=0;j--){
            cnt=0;
            f[i][j]=f[i-1][j];

            for(int cnt=0;cnt<s;cnt++){
                int k=op[i][cnt];

                if(k>j) break;

                f[i][j]=max(f[i][j],f[i-1][j-k]+1LL*i*(cnt+1));
            }
        }
    }

    cout<<f[n][m];
}