//https://ac.nowcoder.com/acm/problem/14662
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 1e4 + 5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

int n,k;
LL c[N],v[N];

bool check(int x){
    priority_queue<LL> heap;
    for(int i=1;i<=n;i++){
        heap.push(v[i]-x*c[i]);
    }
    LL ret = 0;
    for(int i=1;i<=k;i++){
        LL x = heap.top();heap.pop();
        ret += x;
    }
    return ret>=0;
}

void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>c[i]>>v[i];
    }
    int l = 0,r = 1e8;
    while (l<r){
        int mid = (l+r+1)/2;
        if(check(mid)){
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    cout<<l<<qp;
}

int main(){
    int t;cin>>t;
    while (t--)
    {
        solve();
    }
}