#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<string>
#include<queue>
#include<set>
#include<map>
#include<vector>
#define lc(x) (x<<1)
#define rc(x) (x<<1|1)
#define LL long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
#define bug cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
#define bugc(_) cout << (#_) << " = " << (_) << endl;
using namespace std;
const double eps=1e-8;
const int N=1e6+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;

struct node{
	LL x,y,level;
}a[N],p[N][2];//p[i][0]��p[i][1]�ֱ��¼��i������/���µĵ�

LL dp[N][2];//dp[i][0]��dp[i][1]�ֱ��ʾ������/���¶˵㵽���i��ʱ�����¾��� 

//���㼶����ͬ����ֳ����Ϻ����µ� 
bool cmp(node x,node y){
	if(x.level!=y.level)
		return x.level<y.level;
	else if(x.x!=y.x)
		return x.x<y.x;
	else return x.y>y.y;
}

LL dis(node x,node y){
	return abs(x.x-y.x)+abs(x.y-y.y);
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&a[i].x,&a[i].y);
		a[i].level=max(a[i].x,a[i].y);
	}
	a[0]=node{0,0,0};
	sort(a+1,a+1+n,cmp);
	int cnt=0;
	p[0][0]=a[0];
	for(int i=0;i<=n;i++){
		if(a[i].level!=a[i-1].level){
			p[cnt][1]=a[i-1];
			cnt++;
			p[cnt][0]=a[i];
		}
	}
	p[cnt][1]=a[n];
	memset(dp,INF,sizeof(dp));
	dp[0][0]=dp[0][1]=0;
	for(int i=1;i<=cnt;i++){
		dp[i][1]=min(dp[i][1],dp[i-1][0]+dis(p[i][0],p[i-1][0]));//lv(i-1)��˵�->lv(i)��˵�->lv(i)�Ҷ˵� 
		dp[i][1]=min(dp[i][1],dp[i-1][1]+dis(p[i][0],p[i-1][1]));//lv(i-1)�Ҷ˵�->lv(i)��˵�->lv(i)�Ҷ˵� 
		dp[i][0]=min(dp[i][0],dp[i-1][0]+dis(p[i][1],p[i-1][0]));//lv(i-1)��˵�->lv(i)�Ҷ˵�->lv(i)��˵� 
		dp[i][0]=min(dp[i][0],dp[i-1][1]+dis(p[i][1],p[i-1][1]));//lv(i-1)�Ҷ˵�->lv(i)�Ҷ˵�->lv(i)��˵� 
		dp[i][0]+=dis(p[i][0],p[i][1]);
		dp[i][1]+=dis(p[i][0],p[i][1]);
	}
	printf("%lld\n",min(dp[cnt][0],dp[cnt][1]));
	return 0;
}

