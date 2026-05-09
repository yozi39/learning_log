#include<bits/stdc++.h>
using namespace std;

const int N=3e7+10;
long long n,a[N];
long long ans[N];

void abcd(){
    stack<int> st;
    for(int i=n;i>=1;i--){
        while(st.size() && a[st.top()]<=a[i])st.pop();
        if(st.size())ans[i]=st.top();

        st.push(i);
    }
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];

    abcd();

    for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
}