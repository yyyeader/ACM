#include<iostream>
#include<string>
#include<map>
const int N=155;
const int INF=1<<30-1;
using namespace std;

int V,E;
int cost[N][N];
int dis[N];
bool used[N];

void dij(int s){
	for(int i=1;i<=V;i++){
		dis[i]=INF;
		used[i]=false;
	}
	dis[s]=0;
	
	while(true){
		int k=-1;
		for(int i=1;i<=V;i++){
			if(!used[i]&&(k==-1||dis[k]>dis[i]))
				k=i;
		}
		if(k==-1) break;
		used[k]=true;
		for(int i=1;i<=V;i++){
			if(dis[i]>dis[k]+cost[k][i])
				dis[i]=dis[k]+cost[k][i];
		}
	}
}

int main(){
	
	while(cin>>E&&E!=-1){
		map<string,int>mp;
		string start,end;
		int num=0;
		cin>>start>>end;
		//提前给起点终点赋好值 
		mp[start]=++num;
		mp[end]=++num;
		for(int i=1;i<N;i++){
			for(int j=1;j<N;j++){
				cost[i][j]=(i==j?0:INF);
			}
		}	
		for(int i=1;i<=E;i++){
			string s1,s2;
			int val;
			cin>>s1>>s2>>val;	
			if(mp.find(s1)==mp.end()){
				mp[s1]=++num;
			}
			if(mp.find(s2)==mp.end()){
				mp[s2]=++num;
			}
			cost[mp[s1]][mp[s2]]=val;
			cost[mp[s2]][mp[s1]]=val;
		}
		V=num;
		dij(mp[start]);
		//特判 
		if(start==end){
			cout<<"0"<<endl;
			continue;
		}
		if(dis[mp[end]]!=INF)
			cout<<dis[mp[end]]<<endl;
		else
			cout<<"-1"<<endl;
	}
} 
