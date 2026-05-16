#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    while(m--){
        int q;
        cin>>q;
        int left=1;
        int right=n;
        while(left<right){
            int mid=(left+right)/2;
            if(a[mid]>=q){
                right=mid;
            }
            else{
                left=mid+1;
            }
        }
        if(a[right] != q){
            cout<<-1<<' ';
        }
        else{
            cout<<right<<' ';
        }
    }
}