#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 2e5 + 5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

int n,k;
LL a[N],b[N];
vector<double> tmp;

bool check(double x){
    for(int i=1;i<=n;i++){
        tmp.push_back(a[i]-x*b[i]);
    }
    sort(tmp.begin(),tmp.end(),greater<double>());
    double ret = 0;
    for(int i=0;i<tmp.size()-k;i++){
        ret += tmp[i];
    }
    return ret >= 0;
}

int main(){
    while (cin>>n>>k,(n || k)){
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)cin>>b[i];
        
        double l = 0,r=1;
        while(r-l>1e-6){
            tmp.clear();
            double mid = (l+r)/2;
            if(check(mid))l = mid;
            else r = mid;
        }
        cout<<(LL)(l*100+0.5)<<qp;
    }
}