#include<stdio.h>
int sorted[100001];
long long counter;
void merge(int start1,int end1,int start2,int end2){
    int tmp[end2-start1+1];
    int i=start1,j=start2,count=0;
    while(i<=end1||j<=end2){
        if(i>end1){
            tmp[count]=sorted[j];
            j++;
        }
        else if(j>end2){
            tmp[count]=sorted[i];
            i++;
        }
        else{
            if(sorted[i]<=sorted[j])
                tmp[count]=sorted[i],i++;
            else
                tmp[count]=sorted[j],counter+=(j-start1-count),j++;
        }
            count++;
    }
i=0;
while(start1<=end1){
    sorted[start1]=tmp[i];
    i++;
    start1++;
}
while(start2<=end2){
    sorted[start2]=tmp[i];
    i++;
    start2++;
}
}

void merge_sort(int start,int end){
if(end>start){
    merge_sort(start,(start+end)/2);
    merge_sort(((start+end)/2)+1,end);
    merge(start,(start+end)/2,((start+end)/2)+1,end);
}
}

int main(){
int i=0,n,N;
scanf("%d",&N);
while(N--){
scanf("%d",&n);
for(i=0;i<n;i++)
scanf("%d",sorted+i);
counter=0;
merge_sort(0,n-1);
printf("%lld\n",counter);
}
return 0;
}
