#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=5e5+5;

int n,m,head,tail;
int dp[N],sum[N],q[N];//qΪ��Ҫά���Ķ��� 

// dp[i]= min{ dp[j]+M+(sum[i]-sum[j])^2 }
int getDP(int i,int j){
    return dp[j]+m+(sum[i]-sum[j])*(sum[i]-sum[j]);
}

//yj-yk
int getUP(int j,int k){ 
    return dp[j]+sum[j]*sum[j]-(dp[k]+sum[k]*sum[k]);
}

//xj-xk
int getDOWN(int j,int k){
	return 2*(sum[j]-sum[k]);
}

int main(){
	while(~scanf("%d%d",&n,&m)){
		dp[0]=sum[0]=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&sum[i]);
			sum[i]+=sum[i-1];
		}
		head=tail=0;
		q[tail++]=0;
		for(int i=1;i<=n;i++){
			//����Ԫ������������ʱ,ά��g(k,j)=(yj-yk/xj-xk)<sum[i]��ע���ĸΪ0����ֱ�ӱȽ�б�� 
			while(head+1<tail&&!(getUP(q[head],q[head+1])<sum[i]*getDOWN(q[head],q[head+1]))){
				head++;//�൱����̭q[head]Ҳ����k
			}
			dp[i]=getDP(i,q[head]);
			//����Ԫ������������ʱ,ά��g(k,j)<g(j,i)
			while(head+1<tail&&!(getUP(q[tail-1],i)*getDOWN(q[tail-2],q[tail-1])>getUP(q[tail-2],q[tail-1])*getDOWN(q[tail-1],i))){
				tail--;
			}
			q[tail++]=i;
		}
		printf("%d\n",dp[n]);
	}
	return 0;
}
