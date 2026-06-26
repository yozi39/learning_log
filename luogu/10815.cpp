#include<bits/stdc++.h>
using namespace std;
//如果确保评测在linux上可以用getchar_unlocked()代替getchar()加速

//一直报错好难看注释起来了
inline int read(){
    // int ret=0,flag=1;
    // char ch=getchar_unlocked();

    // while(ch<'0' || ch>'9'){
    //     if(ch=='-'){
    //         flag=-1;
    //     }
    //     ch=getchar_unlocked();
    // }

    // while(ch>='0' && ch<='9'){
    //     ret=10*ret+ch-'0';
    //     ch=getchar_unlocked();
    // }

    // return ret*flag;
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