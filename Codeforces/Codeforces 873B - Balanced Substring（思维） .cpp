#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N=1e5+5;
int Min[2*N];//Min[i]��ʾǰ׺��Ϊi����ʼλ��

int main(){
	memset(Min,0x3f,sizeof(Min));
	int n,sum=N,ans=0;//sum=N��ֹ�±�Ϊ��
	char ch;
	scanf("%d",&n);
	getchar();
	Min[sum]=0;
	for(int i=1;i<=n;i++){
		scanf("%c",&ch);
		if(ch=='1')
		 	sum++;
		else
			sum--;
		Min[sum]=min(Min[sum],i);
		ans=max(ans,i-Min[sum]);
	}
	printf("%d\n",ans);
	return 0;
}
