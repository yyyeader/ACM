#include<iostream>
#include<cstring>
#include<algorithm>
#include<stdio.h>
using namespace std;
const int N=1e5+5;

int q[N],head,tail;
long long sum[N];

double Slope(int k,int j){
	return double(sum[j]-sum[k])/(j-k);
}
// ‰»ÎÕ‚π“ 
const int BUF=25000000;
char Buf[BUF],*buf=Buf;
template <class T>
inline void read(T &a){
	for(a=0;*buf<48;buf++);
	while(*buf>47)
		a=a*10+*buf++-48;
}

int main(){
	int n,k;
	int tot=fread(Buf,1,BUF,stdin);
	while(1){
        if(buf-Buf+1>=tot)break;
        read(n),read(k);
		for(int i=1;i<=n;i++){
			read(sum[i]);
			sum[i]+=sum[i-1];
		}
		double ans=0;
		head=tail=0;
		q[tail++]=0;
		for(int i=k;i<=n;i++){
			while(head+1<tail&&Slope(q[head],i)<=Slope(q[head+1],i)){
				head++;
			}
			ans=max(ans,Slope(q[head],i));
			int j=i-k+1;
			while(head+1<tail&&Slope(q[tail-2],q[tail-1])>=Slope(q[tail-1],j)){
				tail--;
			}
			q[tail++]=j;
		}
		printf("%.2f\n",ans);
	}
	return 0;
}
