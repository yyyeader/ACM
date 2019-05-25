#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int N=1e5+5;
typedef long long LL;

priority_queue<int,vector<int>,greater<int> >q[N],aq;

int root[N],cost[N],st[N];

int find(int x){
	return root[x]==x?x:root[x]=find(root[x]);
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&cost[i]);
		root[i]=i;
	}
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		int t1=find(a),t2=find(b);
		if(t1!=t2)
			root[t1]=root[t2];
	}
	int cnt=0;
	for(int i=0;i<n;i++){
		if(root[i]==i)
			st[++cnt]=i;
	}
	for(int i=0;i<n;i++){
		int t1=find(i);
		q[t1].push(cost[i]);
	}
	if(cnt==1){
		puts("0");
		return 0;
	}
	LL ans=0;
	//����ÿ�������и�ȡһ������ĵ㣬һ��cnt�� 
	for(int i=1;i<=cnt;i++){
		int t1=st[i];
		ans+=q[t1].top();
		q[t1].pop();
		while(!q[t1].empty()){
			aq.push(q[t1].top());
			q[t1].pop();
		}
	}
	//һ��Ҫ���cnt-1����,��2cnt-2����,ÿ�����϶�ȡ�˱�������ĵ�,���Կ��Դ�����ʣ�����ѡ����С��cnt-2����
	int sum=cnt-2;
	bool flag=true;
	while(sum--){
		if(aq.empty()){
			flag=false;
			break;
		}
		ans+=aq.top();
		aq.pop();
	}
	if(flag)
		printf("%lld\n",ans);
	else
		puts("Impossible");
}
