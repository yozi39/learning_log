#include<bits/stdc++.h>
using namespace std;

struct T621589
{
    int v,amount;
}a[100010];

bool cmp(T621589 a,T621589 b){
    return a.v<b.v;
}

int main(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=m;i++)cin>>a[i].v>>a[i].amount;

    sort(a+1,a+1+m,cmp);
    int need=n;
    long long i=1,ans=0;
    while(need>0){
        if(need>=a[i].amount){
            need-=a[i].amount;
            ans+=a[i].v*a[i].amount;
        }
        else{
            ans+=need*a[i].v;
            break;
        }
        i++;
    }
    cout<<ans;
}