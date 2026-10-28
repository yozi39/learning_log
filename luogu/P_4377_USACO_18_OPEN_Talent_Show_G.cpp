#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 250 + 5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

int n,W;
LL w[N],t[N];
vector<pair<double,LL>> tmp;
double f[N][1005];

bool check(double x){
    const double NEG = -1e100;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            f[i][j] = NEG;
        }
    }
    f[0][0] = 0;

    for(int i=1;i<=n;i++){
        double z = t[i]-x*w[i];
        for(int j=0;j<=W;j++){
            if(f[i-1][j] == NEG)continue;
            f[i][j] = max(f[i][j],f[i-1][j]);

            int nj = min((LL)W,j+w[i]);
            f[i][nj] = max(f[i][nj],f[i-1][j]+z);
        }
    }

    return f[n][W]>=0;
}

int main(){
    cin>>n>>W;
    for(int i=1;i<=n;i++){
        cin>>w[i]>>t[i];
    }

    double l=0,r=1e3;
    while(r-l>1e-6){
        tmp.clear();
        double mid = (l+r)/2;
        if(check(mid)){
            l = mid;
        } else {
            r = mid;
        }
    }

    cout<<(LL)(1000*l+1e-6);
}