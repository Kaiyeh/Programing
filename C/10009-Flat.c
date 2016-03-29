#include<stdio.h>
int data[100000],usage[100000];
long long sum;
int main(){
    int T,n,w,m,i,count,j,x,be,af,flag,max=0;
scanf("%d",&T);
while(T--){
        sum=0;
        max=0;
    scanf("%d %d %d",&n,&w,&m);
    for(i=0;i<n;++i){
        scanf("%d",data+i);
        sum+=data[i];
        if(data[i]>max)
            max=data[i];
    }
///Test
count=0;
i=0;
while(count<m&&i<n){
if(data[i]>0){
    count++;
    i+=w;
}
else{
    i++;
}
}
if(i<n)
    printf("-1\n");
else{
///min
be=sum/(m*w);
af=max;
x=(be+af)/2;
flag=1;
do{
    for(i=0;i<n;i++)
        usage[i]=0;
count=0;
i=0;
    while(usage[i]==data[i]&&i<n)
        ++i;


while(count<m&&i<n){
    for(j=0;j<w&&i+j<n;++j)
        usage[i+j]=(usage[i+j]+x>=data[i+j]?data[i+j]:usage[i+j]+x);
    ++count;
    while(usage[i]==data[i]&&i<n)
        ++i;
}


if(x==be){
    if(i<n){
        printf("%d\n",x+1);
        flag=0;
    }
    else{
        printf("%d\n",x);
        flag=0;
    }
}

if(i<n){
    be=x;
    x=(x+af)/2;
}
else{
    af=x;
    x=(x+be)/2;
}

}while(flag);
}

}
}
