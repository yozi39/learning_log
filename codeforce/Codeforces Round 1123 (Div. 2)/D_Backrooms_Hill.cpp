#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 2e5 + 5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

struct node{
    int n;
    bool st=0;
};

bool cmp(const node& a,const node& b){
    return a.n<b.n;
}

int main(){
    int T;cin>>T;
    while(T--){
        int n;cin>>n;
        node a[N];

        for(int i=1;i<=n;i++){
            cin>>a[i].n;
            if(i%2) a[i].st=1;
        }

        sort(a+1,a+n+1,cmp);

        int tmp=0;
        bool flag=true;

        for(int i=n;i>=1;i--){
            if(a[i].st) tmp++;
            else tmp--;

            if(abs(tmp)>1){
                flag=false;
                break;
            }
        }

        cout<<(flag?"YES":"NO")<<qp;
    }
}