#include<bits/stdc++.h>//目标其实是让后面还能接尽量多的区间
using namespace std;   //所以之后的排序应该根据结束时间

const int N=1e6+10;

struct P1803
{
    int a,b,d;
}t[N];

bool cmp(P1803 a,P1803 b){
    // if(a.d!=b.d){
    //     return a.d<b.d;
    // }
    // else{
    //     return a.a>b.a;
    // }
    return a.b < b.b;//结束早的优先考虑
}

int main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int a,b;cin>>t[i].a>>t[i].b;
        t[i].d=t[i].b-t[i].a;
    }
    sort(t+1,t+1+n,cmp);
    int sum=0,last=-1;
    for(int i=1;i<=n;i++){
        if(t[i].a>=last){
            sum++;
            last=t[i].b;
        }
    }
    cout<<sum;
}