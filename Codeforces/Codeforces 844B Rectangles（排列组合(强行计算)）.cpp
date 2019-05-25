#include<iostream>
#include<cstdio>
#include<cstdio>
#include<algorithm> 
using namespace std;
typedef unsigned long long LL;
const int N=60;

LL cal_res[N][N],res[N];//cal_res[i][j]��ʾcal(i,j)��res[i]��ʾC(i,2)~C(i,i)(i>=2)���������
int a[N][N];

LL cal(int n,int r){
	LL ans=1,lim=n-r,l=1;
	for(int i=n;i>lim;i--){
		ans*=i;
		while(r>=l&&ans%r==0){
			ans/=r;
			r--;
		}
		while(l<=r&&ans%l==0){
			ans/=l;
			l++;
		}
	}
	return ans;
}

int main(){
	LL sum=0;
	for(int i=1;i<=50;i++){
		cal_res[i][0]=1;
		for(int j=1;j<=i/2;j++){
			cal_res[i][j]=cal(i,j);
		}
		for(int j=i/2+1;j<=i;j++){
			cal_res[i][j]=cal_res[i][i-j];		
		}
	}
	for(int i=1;i<=50;i++){
		LL sum=0;
		for(int j=1;j<=i;j++){
			sum+=cal_res[i][j];	
		}
		res[i]=sum;
	}
	int n,m;
	LL ans=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	//����ͳ�� 
	for(int i=1;i<=n;i++){
		int zero=0,one=0;
		for(int j=1;j<=m;j++){
			if(a[i][j]==1)
				one++;
			else
				zero++;
		}
		ans+=res[zero]+res[one];
	}
	//����ͳ��
	for(int j=1;j<=m;j++){
		int zero=0,one=0;
		for(int i=1;i<=n;i++){
			if(a[i][j]==1)
				one++;
			else
				zero++;
		}
		ans+=res[zero]+res[one];
	}
	//��Ϊ������0����1�ڱ����к��е�ʱ���ظ���,Ҫ��ȥ�ظ����� 
	ans-=n*m;
	printf("%llu\n",ans); 
	return 0;
}

