#include<stdio.h>
int main(){
    int M,N;
    scanf("%d %d",&M,&N);
    int word,memory[M],mem=0;
    int count=0,status=0,used=0;
    int pos=0;
    for(int i=0;i<N;i++){
        scanf("%d",&word);
        if(mem<M){
            for(int j=0;j<used;j++){
                if(word== memory[j]){
                    status = 1;
                    break;
                }
            }
        }
        if(!status){
            count++;
            if (used < M) {
                memory[used] = word;
                used++;
            }
            else {
                memory[pos] = word;
                pos = (pos + 1) % M;
            }
        }
        status=0;
    }
    printf("%d",count);
}