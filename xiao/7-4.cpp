#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int cnt1=0,cnt2=0;
    int num[n+1];
    for(int i=1;i<=n;i++){
        cin>>num[i];
        if(num[i] %2==0)cnt2++;
        else cnt1++;
    }
    cout<<cnt1<<" "<<cnt2;
}