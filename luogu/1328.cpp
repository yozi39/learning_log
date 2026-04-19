#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,NA,NB;
    cin>>N>>NA>>NB;
    int scoreA=0,scoreB=0;
    int queA[NA],queB[NB];
    for(int i=0;i<NA;i++)cin>>queA[i];
    for(int i=0;i<NB;i++)cin>>queB[i];
    int posA=0,posB=0;
    for(int i=0;i<N;i++){
        posA=i%NA;
        posB=i%NB;
        if(queA[posA] == 4 || queB[posB] == 4){
            if(queA[posA] == 4){
                if(queB[posB] == 0 || queB[posB] == 1){
                    scoreA++;
                }
                else if(queB[posB] == 3 || queB[posB] == 2){
                    scoreB++;
                }
            }
            else if(queB[posB] == 4){
                if(queA[posA] == 0 || queA[posA] == 1){
                    scoreB++;
                }
                else if(queA[posA] == 3 || queA[posA] == 2){
                    scoreA++;
                }
            }
        }
        else{
            if(queA[posA] == queB[posB]) continue;

            if(queA[posA] == 0){
                if(queB[posB] == 2 || queB[posB] == 3) scoreA++;
                else scoreB++;
            }
            else if(queA[posA] == 1){
                if(queB[posB] == 0 || queB[posB] == 3) scoreA++;
                else scoreB++;
            }
            else if(queA[posA] == 2){
                if(queB[posB] == 1) scoreA++;
                else scoreB++;
            }
            else if(queA[posA] == 3){
                if(queB[posB] == 2) scoreA++;
                else scoreB++;
            }
        }
    }
    cout<<scoreA<<' '<<scoreB;
}
//0<1<2<3  0,1<4<3,2 
/*
    直接
    开个表格查询!!!
    int win[5][5] = {
        {0,0,1,1,0},
        {1,0,0,1,0},
        {0,1,0,0,1},
        {0,0,1,0,1},
        {1,1,0,0,0}
    };

*/