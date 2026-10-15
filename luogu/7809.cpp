#include <bits/stdc++.h>
using namespace std;

const int N=1e6+5;

int n,m;
int st[N][25];
int f[N],g[N],h[N];
int a[N];
int lg[N];

inline int read(){
    int ret=0,flag=1;
    char ch=getchar();

    while(ch<'0' || ch>'9'){
        if(ch=='-'){
            flag=-1;
        }
        ch=getchar();
    }

    while(ch>='0' && ch<='9'){
        ret=10*ret+ch-'0';
        ch=getchar();
    }

    return ret*flag;
}

inline void print(int x){
    if(x>9) print(x/10);
    putchar(x%10+'0');
}

void init(){
    lg[0]=-1;

    for(int i=1;i<=n;i++){
        lg[i]=lg[i>>1]+1;
        st[i][0]=g[i]-f[i-1];
    }

    for(int j=1;j<=lg[n];j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            st[i][j]=max(
                st[i][j-1],
                st[i+(1<<(j-1))][j-1]
            );
        }
    }
}

int main(){

    n=read();
    m=read();

    for(int i=1;i<=n;i++){
        a[i]=read();

        f[i]=f[i-1]+(a[i]==1);
        g[i]=g[i-1]+(a[i]==0);
        h[i]=h[i-1]+(a[i]==1 && a[i-1]==0);
    }

    init();

    while(m--){
        int op=read();
        int x=read();
        int y=read();

        if(op==1){
            int k=lg[y-x+1];

            int mx=max(
                st[x][k],
                st[y-(1<<k)+1][k]
            );

            print(mx+f[y]-g[x-1]);
            putchar('\n');

        }else{
            print(h[y]==h[x] ? 1 : 2);
            putchar('\n');
        }
    }
}