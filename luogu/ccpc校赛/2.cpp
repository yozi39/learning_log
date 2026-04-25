// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int n,m,cnt=1,count=0;
//     int plant[n+1];
//     cin>>n>>m;
//     int pan[n+1][m+2];
//     for(int i=1;i<=n;i++){
//         count=0;
//         for(int j=1;j<=m;j++){
//             cin>>pan[i][j];
//             if(pan[i][j]==1){
//                 count++;
//             }
//         }
//         plant[i]=count;
//     }
//     int q;
//     cin>>q;
//     int r[q+1];
//     int t[q+1];
//     int h[q+1];
//     int max_hp[n+1];
//     for(int i=1;i<=q;q++){
//         cin>>r[i]>>t[i]>>h[i];
//         int temp=r[i];
//         max_hp[i]=h[i];
//     }
//     bool ok=true;
//     int locate=m+1;
//     double time[n+1];
//     for(int i=1;i<=n;i++){
//         time[i]=(double)(max_hp[i]/plant[i]);     
//     }
//     sort(t+1,t+n+1);
//     while(ok){
//         locate--;
//         for(int i=1;i<n;i++){
//             if(locate == plant[i]){
//                 pan[i][locate]=0;
//             }
//             else{
//                 for(int z=locate;z>=0;z--){
//                     if(i==0){
//                         swap(pan[i][locate],pan[i][z]);
//                     }
//                 }
//             }
//         }
//         if(locate<=0)ok=false;
//         if(cnt>time[n+1]-1){
//             ok=false;
//         }
//         cnt++;
//     }
//     if(cnt>time[n+1]-1){
//         cout<<"You eat the zombie's brain!";
//     }
//     else{
//         cout<<"Zombies eat your brain!";
//     }
// }

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    int pan[105][105]={0};
    int plant[105]={0};
    for(int i=1;i<=n;i++){
        int count=0;
        for(int j=1;j<=m;j++){
            cin>>pan[i][j];
            if(pan[i][j]==1) count++;
        }
        plant[i]=count;
    }
    int q;
    cin>>q;
    int r[105],t[105],h[105];
    for(int i=1;i<=q;i++){
        cin>>r[i]>>t[i]>>h[i];
    }
    int hp[105]={0};
    int locate[105]={0};
    bool alive[105]={0};
    int dead=0;
    int cnt=0;
    while(true){
        cnt++;
        for(int i=1;i<=q;i++){
            if(t[i]==cnt){
                alive[i]=true;
                hp[i]=h[i];
                locate[i]=m+1;
            }
        }
        bool lose=false;
        for(int i=1;i<=q;i++){
            if(alive[i]){
                locate[i]--;
                if(locate[i]<=0) lose=true;
            }
        }
        int leftz[105];
        memset(leftz,0,sizeof(leftz));
        for(int i=1;i<=q;i++){
            if(alive[i]){
                int row=r[i];
                if(leftz[row]==0 || locate[i]<locate[leftz[row]]){
                    leftz[row]=i;
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(leftz[i]!=0){
                hp[leftz[i]]-=plant[i];
            }
        }
        for(int i=1;i<=q;i++){
            if(alive[i] && hp[i]<=0){
                alive[i]=false;
                dead++;
            }
        }
        for(int i=1;i<=q;i++){
            if(!alive[i]) continue;
            int row=r[i];
            int col=locate[i];
            if(col>=1 && col<=m && pan[row][col]==1){
                int L=col;
                while(L>1 && pan[row][L-1]==1) L--;
                for(int j=L;j<=col;j++) pan[row][j]=0;
                if(L==1){
                    plant[row]--;
                }
                for(int j=max(1,L-1);j<=col-1;j++){
                    pan[row][j]=1;
                }
            }
        }
        if(lose){
            cout<<cnt<<"\n";
            cout<<"Zombies eat your brain!";
            return 0;
        }
        if(dead==q){
            cout<<cnt<<"\n";
            cout<<"You eat the zombie's brain!";
            return 0;
        }
    }
}