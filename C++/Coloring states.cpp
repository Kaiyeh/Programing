#include<stdio.h>
#include<iostream>
long long pow_2[64];
long long pow2(int n){
if(n>=1)
return 2*pow2(n-1);
else
return 1;
}
int test_fuc(unsigned long long t,const int *data,const int n){
    int i;
    int datas[n];
    for(i=0;i<n;i++)
        datas[i]=*(data+i);
while(t){
            i=0;
        while(i<63&&pow_2[i]<=t)
        i++;
        i--;
        if(t-1>=pow_2[63])
            i++;
        t-=pow_2[i];
    if(i==63)
        t--;
        datas[i]=datas[i]==1?0:1;
    if(i!=0)
        datas[i-1]=datas[i-1]==1?0:1;
    }
int cnt= 0;
for(i=0;i<n;i++)
    cnt+=datas[i];
return cnt;

}
int main(){
int data [1000];
int N, n, i, cnt, tst;
for(i=0;i<64;i++)
    pow_2[i]=pow2(i);
    pow_2[63]--;
unsigned long long t;
unsigned long long sum;
scanf("%d",&N);
while(N--){
        tst=1;
    std::cin >> n >> t;
    for(i=0;i<n;i++)
        scanf("%d",data+i);

    for(i=n-1;i>=0;i--)
        if(data[i]==0)
            break;
            cnt=i;
            if(i<64){
                    sum=0;
                int tmp[n];
                for(i=0;i<n;i++)
                    tmp[i]=data[i];
                i=cnt;

                while(i>=0&&t+1>=sum){
                    sum+=pow_2[i];
                    tmp[i]=tmp[i]==1?0:1;
                    if(i!=0)
                    tmp[i-1]=tmp[i-1]==1?0:1;
                    while(i>=0&&tmp[i])
                        i--;
                }
                    if(n!=test_fuc(sum,data,n))
                        sum--;
                    if(t>=sum)
                        tst=0;
            }
    if(cnt>63||tst)
        printf("%d\n",test_fuc(t,data,n));
    else
        printf("%d\n",n);
}
return 0;
}
