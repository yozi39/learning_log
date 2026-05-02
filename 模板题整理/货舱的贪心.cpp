#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int main(){
    int n;
    cin>>n;
    int a[n+1];
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=abs(a[i]-a[n/2]);
    }
    cout<<ans;
}