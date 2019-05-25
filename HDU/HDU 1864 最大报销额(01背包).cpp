#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=105;
const int M=3e6+5;
int v[N],dp[M];

int main(){
	double q;
	int n;
	while(~scanf("%lf%d",&q,&n)){
		if(n==0)
			break;
		int cnt=0;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			int t;
			double A=0,B=0,C=0;	
			bool flag=true;
			scanf("%d",&t);
			while(t--){
				double val;
				char ch;
				getchar();
				scanf("%c:%lf",&ch,&val);
				if(val>600||(ch!='A'&&ch!='B'&&ch!='C'))
					flag=false;
				if(ch=='A')	A+=val;
				if(ch=='B') B+=val;
				if(ch=='C') C+=val;
			}
			if(A+B+C<=1000&&A<=600&&B<=600&&C<=600&&flag)
				v[++cnt]=(A+B+C)*100;
		}
		int lim=q*100;
		for(int i=1;i<=cnt;i++){
			for(int j=lim;j>=v[i];j--)
				dp[j]=max(dp[j],dp[j-v[i]]+v[i]);
		}
		printf("%.2f\n",1.0*dp[lim]/100);
	}
	return 0;
}

