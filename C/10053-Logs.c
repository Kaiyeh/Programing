#include<stdio.h>
#define MOD 100000007
long long my_pow(long long a,int b){
if(b==2)
    return a*a;
else if(b==1)
    return a;
else if(b%2==0)
    return my_pow((a*a)%MOD,b/2);
else
    return (a*(my_pow((a*a)%MOD,b/2)%MOD))%MOD;
}
int main(){
int T,N;
scanf("%d",&T);
while(T--){
    scanf("%d",&N);
    printf("%lld\n",(my_pow(3,N)-1));
}
}
