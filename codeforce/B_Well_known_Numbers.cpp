#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 2e5 + 5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

int s,k,pos;
LL pre[N];
vector<LL> ret;

int main(){
    cin>>s>>k;
    pre[1] = 1;
    pos = 1;
    while(pre[pos] < s){
        pos++;
        for(int j=max(1,pos-k);j<pos;j++){
            pre[pos] += pre[j];
        }
    }

    for(int i=pos;i>=1;i--){
        if(pre[i] <= s){
            s -= pre[i];
            ret.push_back(pre[i]);
        }
    }
    if(ret.size()==1)ret.push_back(0);

    cout<<ret.size()<<qp;
    for(auto v:ret){
        cout<<v<<' ';
    }
}