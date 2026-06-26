//p5091
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=1e8+5;

LL a,c;
string b;

//求一个欧拉就用试除法
LL get_phi(LL x){
    LL ret = x;
    for(int i=2;i<=x/i;i++){
        if(x%i==0){
            ret=ret/i*(i-1);//欧拉公式的定理
            while(x%i==0) x/=i;
        }
    }
    if(x>1) ret=ret/x*(x-1);
    return ret;
}

LL calc(string& x,LL p){
    int ret=0;
    bool flag=false;
    for(auto y:x){
        ret=10*ret+(y-'0');
        if(ret>=p){
            flag=true;
            ret%=p;
        }
    }
    if(flag)ret+=p;
    return ret;
}

LL qpow(LL a,LL b,LL c){
    LL ret=1;
    while (a)
    {
        if(a&1)ret = ret * b % c;
        a >>= 1;
        b = b*b % c;
    }
    return ret;
}

int main(){
    cin>>a>>c>>b;
    
    LL phi=get_phi(c);
    LL b_num=calc(b,phi);
    cout<<qpow(b_num,a,c);
}