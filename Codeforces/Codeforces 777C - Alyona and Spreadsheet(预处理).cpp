#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;
const int N=1e5+5;

int main(){
	int m,n,q,x;
	scanf("%d %d",&m,&n);
	vector<vector<int> >v(m),dp(m);//dp预处理当前列当前位置的连续长度
	vector<int>a(m+1);//a预处理当前行最大连续数 
	for(int i=0;i<m;i++){
		v[i].resize(n);
		dp[i].resize(n);
	}
	
	for(int i=0;i<m;i++){
		int mtmp=0;
		for(int j=0;j<n;j++){
			scanf("%d",&x);
			v[i][j]=x;
			if(i==0)
				dp[i][j]=1;
			else{
				if(v[i][j]>=v[i-1][j])
					dp[i][j]=dp[i-1][j]+1;
				else
					dp[i][j]=1;
			}
			mtmp=max(mtmp,dp[i][j]);
		}
		a[i]=mtmp;
	}
	
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int l,r;
		bool sign=false;
		scanf("%d %d",&l,&r);		
		if(a[r-1]>r-l)
			sign=true;
		if(sign){
			printf("Yes\n");
		}
				
		else{
			printf("No\n");
		}
	}
}
