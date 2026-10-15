#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=3e5+5;

int n,x;
int a[N];

int main(){
    int T;cin>>T;
    while(T--){
        cin>>n>>x;
        for(int i=1;i<=n;i++)cin>>a[i];

        vector<int> p;
        int tmp=x;
        for(int i=2;1LL*i*i<=tmp;i++){
            if(tmp%i==0){
                p.push_back(i);
                while(tmp%i==0)tmp/=i;
            }
        }
        if(tmp>1)p.push_back(tmp);

        LL ret=0;
        for(auto v:p){
            LL sum=0;
            for(int i=1;i<=n;i++){
                if(a[i]%v==0){
                    sum+=a[i];
                }
            }
            ret=max(ret,sum);
        }

        cout<<ret<<'\n';
    }
}