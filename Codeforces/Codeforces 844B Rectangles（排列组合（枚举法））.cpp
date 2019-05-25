#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N=60;

int a[N][N];

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	LL ans=0;
	for(int i=1;i<=n;i++){
		int cnt=0;//��¼1�ĳ��ִ��� 
		for(int j=1;j<=m;j++){
			if(a[i][j]==1) 
				cnt++;
		}
		ans+=(1LL<<cnt)-1;//��ȥȫ����ȡ�Ŀ���
		ans+=(1LL<<(m-cnt))-1;
	}
	for(int j=1;j<=m;j++){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i][j]==1)
				cnt++;
		}
		ans+=(1LL<<cnt)-1;
		ans+=(1LL<<(n-cnt))-1;
	}
	//ȥ���ظ����� 
	ans-=n*m;
	printf("%lld\n",ans);
	return 0;
}
