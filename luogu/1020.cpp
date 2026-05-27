#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

int dp[N],cnt=1;
vector<int> a,tail;

int main(){
    int tmp;
    while(cin >> tmp){
        a.push_back(tmp);
    }
    int len=a.size();

    int pos=0,ans=0;

    for(int i=0;i<len;i++){//下降子序列
        if(pos==0 || a[i]<=dp[pos]){
            pos++;
            dp[pos]=a[i];//pos1~n,pos有元素
        }
        else{
            int left=1,right=pos;
            while(left<right){
                int mid=(left+right)/2;
                if(a[i]>dp[mid]){
                    right=mid;
                }
                else{
                    left=mid+1;
                }
            }
            dp[right]=a[i];
        }
    }

    for(int i=0;i<len;i++){
        int x=a[i];

        int left=0,right=tail.size();

        while(left<right){
            int mid=(left+right)/2;

            if(tail[mid]>=x){
                right=mid;
            }
            else{
                left=mid+1;
            }
        }

        if(left==tail.size()){
            tail.push_back(x);
        }
        else{
            tail[left]=x;
        }
    }

    cout<<pos<<'\n'<<tail.size();
    return 0;
}