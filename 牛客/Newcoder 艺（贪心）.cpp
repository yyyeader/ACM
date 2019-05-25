/*
����Ȼ��̰�ģ�ÿ��ʱ��ѡ���ֵ�Ƚϴ�Ľ�Ŀ����
����ʵ�������е��鷳�������ʵ�ֺ��������ѧϰһ�¡� 
��Ŀ����:https://www.nowcoder.com/acm/contest/86/I 
*/ 
#include<cstdio>
#include<cmath>
#include<cctype>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<string>
#define lc(a) (a<<1)
#define rc(a) (a<<1|1)
#define MID(a,b) ((a+b)>>1)
#define fin(name)  freopen(name,"r",stdin)
#define fout(name) freopen(name,"w",stdout)
#define clr(arr,val) memset(arr,val,sizeof(arr))
#define _for(i,start,end) for(int i=start;i<=end;i++)  
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
typedef long long LL;
const int N=5e6+5;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

struct node{
	LL st,val;
	bool operator <(const node &b)const{
		return st<b.st;
	}
}a[N],b[N];

int main(){
	FAST_IO;
	LL n,m,t;
	cin>>n>>m>>t;
	for(int i=1;i<=n;i++){
		cin>>a[i].st>>a[i].val;
	}
	for(int i=1;i<=m;i++){
		cin>>b[i].st>>b[i].val;
	}
	a[n+1].st=b[m+1].st=t;
	sort(a+1,a+1+n);
	sort(b+1,b+1+m);
	
	LL ans=0,now=0,i=0,j=0;
	while(now<t){
		LL val=max(a[i].val,b[j].val);
		LL pre=now;
		if(a[i+1].st<b[j+1].st){
			now=a[i+1].st;
			i++;
		}
		else{
			now=b[j+1].st;
			j++;
		}
		//��val<=0����ѡ�����ʱ�䲻������
		if(val>0)
			ans+=val*(now-pre);
	}
	cout<<ans<<endl;
	return 0;
}
