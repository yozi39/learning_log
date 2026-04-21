#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++)cin>>a[i];
    int now,j;
    for(int i=1;i<=n;i++){
        now=a[i];
        for(j=i-1;j>=1;j--){
            if(now<a[j]){
                a[j+1]=a[j];
            }
            else break;
            
        }
        a[j+1]=now;
    }
    for(int i=1;i<=n;i++)
        cout<<a[i]<<' ';
}