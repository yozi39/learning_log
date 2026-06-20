#include<bits/stdc++.h>
using namespace std;

const int N=100010;
int n;
int a[N],f[N];

int main(){
    cin>>n;for(int i=1;i<=n;i++)cin>>a[i];

    int cnt=1;
    for(int i=1;i<=n;i++){
        if(cnt==1 || f[cnt-1]<a[i]){
            f[cnt++]=a[i];
        }
        
        else{
            int left=1,right=cnt-1;
            while(left<right){
                int mid=(left+right)/2;
                if(f[mid]>=a[i])right=mid;
                else{
                    left=mid+1;
                }
            }
            f[left]=a[i];
        }
    }
    cout<<cnt-1;
}