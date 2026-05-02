#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;

struct T638476
{
    int h,f;
}apple[N];

bool cmp(T638476 a,T638476 b){
    return a.f<b.f;
}

int main(){
    int n,s;cin>>n>>s;
    int a,b;cin>>a>>b;
    for(int i=1;i<=n;i++)cin>>apple[i].h>>apple[i].f;
    sort(apple+1,apple+1+n,cmp);

    int ans=0;
    for(int i=1;i<=n;i++){
        if(s>=apple[i].f && (a+b)>=apple[i].h){
            ans++;
            s-=apple[i].f;
        }
    }
    cout<<ans;
}