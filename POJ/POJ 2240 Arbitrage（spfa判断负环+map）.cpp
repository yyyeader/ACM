#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#include<string>
using namespace std;
const int N=35;

int n,m;
int qcnt[N];
bool vis[N];
double rate[N][N],dis[N];

bool spfa(int s){
	memset(vis,false,sizeof(vis));
	memset(dis,0,sizeof(dis));
	memset(qcnt,0,sizeof(qcnt));
	dis[s]=1;
	queue<int>q;
	q.push(s);
	while(!q.empty()){
		int k=q.front();
		q.pop();
		vis[k]=false;
		for(int i=1;i<=n;i++){
			//�ı��ɳ�������ֻҪ��ʹ��������͸��� 
			if(dis[k]*rate[k][i]>dis[i]){
				dis[i]=dis[k]*rate[k][i];
				if(!vis[i]){
					q.push(i);
					qcnt[i]++;
					//��Ӵ���>=n��ʾ����"����"����һȦ����Ļ�������ʵҲ���Ǹ����Ķ������һ���ɳ��������� 
					if(qcnt[i]>=n){
						return true;
					}
					vis[i]=true;
				}
			}
		}
	}
	return false;
}

int main(){
	int cas=0;
	string s1,s2;
	while(cin>>n&&n){
		//map����������֣���ÿ������һ����ֵ������ת��Ϊ��ͨ���·���� 
		map<string,int>mp;
		memset(rate,0,sizeof(rate));
		for(int i=1;i<=n;i++){
			cin>>s1;
			mp[s1]=i;
		}
		cin>>m;
		for(int i=1;i<=m;i++){
			double rt;
			cin>>s1>>rt>>s2;
			rate[mp[s1]][mp[s2]]=rt;
		}
		if(spfa(1))
			cout<<"Case "<<++cas<<": Yes"<<endl;
		else
			cout<<"Case "<<++cas<<": No"<<endl;
	}
	return 0;
}
