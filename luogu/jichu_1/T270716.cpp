#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> record(510);
    string temp;
    cin>>temp;
    while(temp != "0"){
        record.push_back(temp);
        cin>>temp;
    }
    int end=record.size();
    for(int i=0;i<end;i++){
        for(int j=i+1;j<record.size();j++){
            if(record[i] == record[j]){
                record[j]='#';
            }
        }
    }
    for(int i=0;i<end;i++){
        if(record[i] != "#")cout<<record[i];
        else{
            continue;
        }
    }
}