#include<bits/stdc++.h>
using namespace std;
int main(){
    int s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    if(s1<425 && (s2<60 || s3<60 || s4<60)){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}