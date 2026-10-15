#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 2e5 + 5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

int cnt[105];

int main(){
    int T;cin>>T;
    while(T--){
        int n;cin>>n;
        memset(cnt,0,sizeof cnt);
        for(int i=1;i<=n;i++){
            int x;cin>>x;
            cnt[x]++;   
        }

        for(int k=1;k<=n;k++){
            for(int i=100;i>0;i--){
                if(cnt[i]>=k){
                    cout<<i<<' ';
                }
            }
        }
        cout<<qp;
    }
}