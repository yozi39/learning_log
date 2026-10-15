#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 3e5 + 5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

int a[N];

int main(){
    int T;cin>>T;
    while(T--){
        int n,x;cin>>n>>x;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        vector<int> p;

        for(int i=2;1ll*i*i<=x;i++){
            if(x%i == 0){
                p.push_back(i);
                while(x%i==0){
                    x/=i;
                }
            }
        }
        if(x>1)p.push_back(x);
        
        LL ret = 0;
        for(auto xp:p){
            LL sum=0;
            for(int i=1;i<=n;i++){
                if(a[i]%xp==0){
                    sum+=a[i];
                }
            }
            ret = max(ret,sum);
        }

        cout<<ret<<qp;
    }
}