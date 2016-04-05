#include<stdio.h>
long long pow_2[64];
int bsearch_2(int head,int current,int tail,unsigned long long number){
if(current=head||number==pow_2[current])
    return current;
else if(number>pow_2[current])
    return bsearch_2(current,(current+tail)/2,tail,number);
else if(number<pow_2[current])
    return bsearch_2(head,(current+head)/2,current,number);
}

long long pow2(int n){
if(n>=1)
return 2*pow2(n-1);
else
return 1;
}

int main(){
int N ,n ,i ,cnt;
for(i=0;i<64;i++)
    pow_2[i]=pow2(i);
    pow_2[63]--;
unsigned long long t;
int data [1000];
int *current;
scanf("%d",&N);
while(N--){
        cnt =0;
    scanf("%d %lld",&n,&t);
    for(i=0;i<n;i++)
        scanf("%d",data+i);
    for(i=n-1;i>=0;i--)
        if(data[i]==0)
            break;
    if(i>63||pow_2[i]>t){

    while(t){
            i=0;
        while(i<63&&pow_2[i]<=t)
        i++;
        if(t-1>=pow_2[63])
            i++;
        i--;
        t-=pow_2[i];
    if(i==63)
        t--;
        data[i]=data[i]==1?0:1;
    if(i!=0)
        data[i-1]=data[i-1]==1?0:1;
    }
for(i=0;i<n;i++)
    cnt+=data[i];
    printf("%d\n",cnt);
    }
    else
        printf("%d\n",n);
}

return 0;
}
