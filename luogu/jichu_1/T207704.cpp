#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    int pan[n][n];
    int left=0,up=0,count=1;
    for(int j=0;j<n;j++){
        for(int i=left;i<n;i++){
            pan[i][up]=count;
        }
        for(int i=up;i<n;i++){
            pan[left][i]=count;
        }
        count++;
        up++;
        left++;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<pan[j][i]<<" ";
        }
        cout<<'\n';
    }
}