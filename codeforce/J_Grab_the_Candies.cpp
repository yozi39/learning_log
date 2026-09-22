#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=0;

int main(){
    int T;cin>>T;
    while(T--){
        int n;cin>>n;
        int sum1=0,sum2=0;
        int a[n+5];
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]%2){
                sum1+=a[i];
            } else {
                sum2+=a[i];
            }
        }

        if(sum1<sum2){
            cout<<"YES\n";
        } else {
            cout<<"NO\n";
        }
    }
}