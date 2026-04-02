#include<stdio.h>
#include<math.h>

// int main(){
//     double v=299792458;
//     double t=5;
//     printf("光的路程是：%.2lf",t*v);
//     return 0;
// }

int main(){
    double l = 10;
    double g = 9.8;
    double t = sqrt(2*l/g);
    printf("物体从%lf下落的",l);
    printf("时间是%.2lf",t);
    return 0;
}