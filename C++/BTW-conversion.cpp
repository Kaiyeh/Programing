#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
int main(){
using namespace std;
int index;
int n,i,tmp,length,cnt;
char c;
while(1){
string tail;
do{
scanf("%d%c",&n,&c);
    tail.append((int)n,(char)c);
c=getchar();
if(c=='\n')
    break;
ungetc(c,stdin);
}while(1);
cout << tail << endl;
cout << tail.length() << endl;
scanf(" %d",&index);
if(index==0)
    break;
index--;
length=tail.length();
tmp=length;
string head=tail;
string ori=tail;
sort(head.begin(),head.end());
ori[length-1]=tail[index];
while(--length){
        cnt=1;
    for(i=index-1;i>=0;i--)
        if(tail[i]==ori[length])
            cnt++;
    for(i=0;cnt;i++)
        if(head[i]==ori[length])
            cnt--;
    index=i-1;
    ori[length-1]=tail[index];
}
length=tmp;
for(i=1;i<=length;i++)
    head[i-1]=tail[length-i];
string enc[length];
for(i=0;i<length;i++){
    enc[i].assign(head,i,length-i);
    enc[i].append(head,0,i);
}
sort(enc,enc+length);
tmp=0;
c=enc[0][length-1];
string ans;
for(i=0;i<length;i++){
    if(enc[i][length-1]==c)
        tmp++;
    else{
        ans.append(1,(char)(tmp-'0'));
        ans.append(1,(char)enc[i-1][length-1]);
    }
}
ans.append(1,(char)(tmp-'0'));
ans.append(1,(char)enc[i-1][length-1]);

}
return 0;

//1p2s1m1i1p1i2s2i
//5




}
