#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n+1];
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    int ave=sum/n;
    for(int i=1;i<=n;i++){
        a[i]-=ave;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(a[i] != 0){
            a[i+1]+=a[i];
            ans++;
        }
    }
    cout<<ans;
}