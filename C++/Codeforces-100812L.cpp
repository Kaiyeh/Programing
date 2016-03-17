#include<stdio.h>
long long my_abs(long long *num){
return *num>0?*num:(-*num);
}

int main(){
long long N,M;
scanf("%I64d  %I64d",&N,&M);
long long o_N,o_M;
long long cr_n_n=1,cr_n_m=0,cr_m_n=0,cr_m_m=1;
long long tmp;
if(N==1&&M==1){
    printf("1");
    return 0;
}
else if(N==1||M==1){
    printf("2");
    return 0;
}
o_N=N;
o_M=M;
while(N!=0&&M!=0){
    if(N>M){
        tmp=N/M;
        cr_n_n-=(cr_m_n*tmp);
        cr_n_m-=(cr_m_m*tmp);
        N%=M;
    }
    else{
        tmp=M/N;
        cr_m_n-=(cr_n_n*tmp);
        cr_m_m-=(cr_n_m*tmp);
        M%=N;
    }
}
if(N==0){
if(M!=1){
    printf("%I64d",o_N*(o_M/M));
}
else{
    if(my_abs(&cr_m_n)*o_N>my_abs(&cr_m_m)*o_M)
        printf("%I64d",my_abs(&cr_m_n)*o_N);
    else
        printf("%I64d",my_abs(&cr_m_m)*o_M);
}
}
else{
if(N!=1){
    printf("%I64d",o_N*(o_M/N));
}
else{
    if(my_abs(&cr_n_n)*o_N>my_abs(&cr_n_m)*o_M)
        printf("%I64d",my_abs(&cr_n_n)*o_N);
    else
        printf("%I64d",my_abs(&cr_n_m)*o_M);
}
}
return 0;
}
