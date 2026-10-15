#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 1e3 + 5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

LL a,b;
LL path[N],ret[N],limit=1e7;
bool flag;

LL gcd(LL a,LL b){
    return b==0?a:gcd(b,a%b);
}

void dfs(int pos,int depth,LL a,LL b){
    if(pos+1==depth){
        LL l=4*b/(a*a)+1,
            r=min(2*limit/a,limit*limit/b);

        for(LL k=l;k<=r;k++){
            LL d=k*k*a*a-4*k*b;
            LL t=sqrt(d);

            if(t==0 || t*t!=d || (k*a-t)%2!=0) continue;

            LL x=(k*a-t)/2,
               y=(k*a+t)/2;

            if(x<=path[pos-1] || y>limit) continue;

            path[pos]=x;
            path[pos+1]=y;

            if(!flag || path[depth]<ret[depth]){
                for(int i=1;i<=depth;i++){
                    ret[i]=path[i];
                }
                limit=ret[depth];
            }

            flag=true;
        }
        return;
    }

    LL l=max(b/a,path[pos-1]);

    LL r=((depth-pos+1)*b-1)/a;

    r=min(r,limit);

    for(LL t=l+1;t<=r;t++){
        LL up=a*t-b,
           down=b*t;

        LL d=gcd(up,down);

        path[pos]=t;
        dfs(pos+1,depth,up/d,down/d);
    }
}

int main(){
    cin>>a>>b;

    LL d=gcd(a,b);
    a/=d;
    b/=d;

    if(a==1){
        cout<<b<<qp;
        return 0;
    }

    for(int depth=1;;depth++){
        dfs(1,depth,a,b);

        if(flag){
            for(int i=1;i<=depth;i++){
                cout<<ret[i]<<' ';
            }
            break;
        }
    }
}