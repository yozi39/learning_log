#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    int T;cin>>T;

    while(T--){
        LL a,b,c;cin>>a>>b>>c;

        cout<<max(abs(a-b),a+c-b)<<'\n';
    }
}