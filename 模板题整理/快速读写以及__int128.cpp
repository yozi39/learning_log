#include<bits/stdc++.h>
using namespace std;
//类型__int128 不能常规读入写出所以要用快速读写的方式来完成对他的赋值
//缺点: 不通用,只能是linux系列下的GCC系列编译器
//      不方便
//      空间大,速度慢容易MLE

//如果确保评测在linux上可以用getchar_unlocked()代替getchar()加速
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

inline void print(long long x){
    if(x<0){
        putchar('-');
        x=-x;
    }

    if(x>9)print(x/10);
    putchar(x%10+'0');
}

int main(){
    int n=read();
    long long sum=0;
    for(int i=1;i<=n;i++){
        int tmp=read();
        sum+=tmp;
    }
    print(sum);
}