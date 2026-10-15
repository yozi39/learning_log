#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=18;
const double eps = 1e-7;

int n,m;
double x[N],y[N];

int g[N*N*N],cnt;
int f[1<<N];

bool zero(double x){
    return fabs(x) <= eps;
}

int main(){
    int T;cin>>T;
    while(T--){
        cin>>n>>m;
        memset(g,0,sizeof g);
        memset(f,0x3f,sizeof f);
        for(int i=0;i<n;i++){
            cin>>x[i]>>y[i];
        }

        for(int i=0;i<n;i++){
            g[++cnt] |= (1<<i);
            for(int j=i+1;j<n;j++){
                double x1 = x[i],y1 = y[i];
                double x2 = x[j],y2 = y[j];
                if(zero(x1-x2))continue;

                double a = (y1*x2-y2*x1)/(x1*x1*x2 - x2*x2*x1);
                if(a > -eps)continue;

                double b = y1/x1 - a*x1;

                cnt++;
                for(int k=0;k<n;k++){
                    if(zero(a*x[k]*x[k] + b*x[k] - y[k]))
                        g[cnt] |= (1<<k);
                }
            }
        }

        f[0] = 0;
        for(int st = 0;st<(1<<n)-1;st++){
            for(int i=1;i<=cnt;i++){
                f[st | g[i]] = min(f[st | g[i]] , f[st] + 1);
            }
        }
        cout<<f[(1<<n)-1]<<'\n';
    }
}