#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<map>
#include<algorithm>
#include<queue>
#include<vector>
#define LL long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
#define bug cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
using namespace std;

struct node1{
	int val;
	string str;
	bool operator <(const node1 &b)const{
		return val==b.val?str>b.str:val>b.val;
	}
};

struct node2{
	int val;
	string str;
	bool operator <(const node2 &b)const{
		return val==b.val?str<b.str:val<b.val;
	}
};
map<string,bool>mp1;
map<string,int>mp2;
priority_queue<node1>q1;
priority_queue<node2>q2;

int main(){
	FAST_IO;
	int n;
	cin>>n;
	rep(i,1,n){
		int op,y;
		string x;
		cin>>op;
		if(op==1){
			cin>>x>>y;
			//若x已存在，则不合法
			if(mp1.find(x)!=mp1.end()&&mp1[x]) continue;
			mp1[x]=true;
			mp2[x]=y;
			q1.push(node1{y,x});
			q2.push(node2{y,x});
		}
		if(op==2){
			cin>>x;
			//若x不存在，则不合法 
			if(mp1.find(x)==mp1.end()||!mp1[x]) continue;
			mp1[x]=false;
		}
		if(op==3){
			cin>>x>>y;
			//若x不存在，则不合法 
			if(mp1.find(x)==mp1.end()||!mp1[x]) continue;
			mp2[x]=y;
			q1.push(node1{y,x});
			q2.push(node2{y,x});
		}
		if(op==4){
			cin>>y;
			if(y==1){
				while(!q1.empty()){
					node1 t=q1.top();
					//删除不合法对象 
					if(!mp1[t.str]||mp2[t.str]!=t.val){
						q1.pop();
						continue;
					}
					cout<<t.str<<endl;
					break;
				}
			}
			if(y==2){
				while(!q2.empty()){
					node2 t=q2.top(); 
					if(!mp1[t.str]||mp2[t.str]!=t.val){
						q2.pop();
						continue;
					}
					cout<<t.str<<endl;
					break;
				}
			}
		}
	}
	return 0;
}

