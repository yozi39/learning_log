/*
    双指针模板题
*/
#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e6+10;
int a[MAXN];

int main(){
    int T;
    cin>>T;
    while(T--){
        unordered_map<int,int> hex;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        int left=1,right=1;//初始化指针
        int cnt=0,max=0;
        while(right<=n){
            if(hex[a[right]]==0){//a[right]是记录值而不是right
                hex[a[right]]++;
                right++;
                cnt++;
            }//进窗口
            else{
                hex[a[left]]--;
                left++;
                cnt--;
            }
            if(cnt>max)max=cnt;
        }
        cout<<max<<'\n';
    }
}