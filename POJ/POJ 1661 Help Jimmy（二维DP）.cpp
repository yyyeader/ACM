#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int N=1e3+5;
const int INF=0x3f3f3f3f;

int dp[N][2];//dp[i][0]��ʾ�ߵ���i�����˵���С���ѣ�dp[i][0]��ʾ�ߵ��Ҷ˵���С���� 

struct node{
	int l,r,h;
}a[N];

bool cmp(node a,node b){
	return a.h>b.h;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		memset(dp,0x3f,sizeof(dp));
		int n,x,y,lim,ans=INF;
		scanf("%d%d%d%d",&n,&x,&y,&lim);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].h);
		}
		sort(a+1,a+1+n,cmp);
		a[0].l=a[0].r=x,a[0].h=y;
		dp[0][0]=dp[0][1]=0;
		for(int i=0;i<=n;i++){
			//flag��ʾ��ľ��i��ȥ�Ƿ�����������ľ�� 
			bool flag=true;
			//������
			for(int j=i+1;j<=n;j++){
				//����������ŵ�ľ�� 
				if(a[j].l<=a[i].l&&a[j].r>=a[i].l&&a[i].h-a[j].h<=lim){
					dp[j][0]=min(dp[j][0],a[i].l-a[j].l+dp[i][0]);
					dp[j][1]=min(dp[j][1],a[j].r-a[i].l+dp[i][0]);
					flag=false;
					break;
				}
			}
			//���û������ľ�嵲��,�ж���ظ߶��Ƿ��������,�Ӷ�ȷ���Ƿ����ֱ�����
			if(flag&&a[i].h<=lim){
				ans=min(dp[i][0],ans);
			}
			flag=true;
			//�����ߣ�ͬ�� 
			for(int j=i+1;j<=n;j++){
				if(a[j].r>=a[i].r&&a[j].l<=a[i].r&&a[i].h-a[j].h<=lim){
					dp[j][0]=min(dp[j][0],a[i].r-a[j].l+dp[i][1]);
					dp[j][1]=min(dp[j][1],a[j].r-a[i].r+dp[i][1]);
					flag=false;
					break;
				}
			}
			if(flag&&a[i].h<=lim){
				ans=min(dp[i][1],ans);
			}
		}
		//ֻ�����ˮƽ�ߵ�ʱ�伴�ɣ���Ϊ����������䵽����ĸ߶ȶ���y,�ǲ���ġ�
		printf("%d\n",ans+y);
	}
	return 0;
}
