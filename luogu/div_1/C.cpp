#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int sumA=0,sumB=0;
    vector<char> ans;
    int tmp;
    for(int i=0;i<n;i++){
        cin>>tmp;
        if(sumA > sumB){
            sumB+=tmp;
            ans.push_back('B');
        }
        else if(sumB >= sumA){
            sumA+=tmp;
            ans.push_back('A');
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
    }
}