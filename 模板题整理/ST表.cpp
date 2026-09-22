//P3865
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=1e5+5;

int n,m;
LL f[N][25];

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

inline void print(LL x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    
    if(x>9) print(x/10);
    putchar(x%10+'0');
}

void init(){
    for(int j=1;j<=log2(n);j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            f[i][j] = max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
        }
    }
}

LL RMQ(int l,int r){
    int k=log2(r-l+1);
    return max(f[l][k],f[r-(1<<k)+1][k]);
}

int main(){
    n=read();
    m=read();
    
    for(int i=1;i<=n;i++) f[i][0]=read();

    init();

    while(m--){
        int l=read(),r=read();
        print(RMQ(l,r));
        putchar('\n');
    }
}