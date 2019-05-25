#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
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
const int N=1e6+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;

struct node{
	int id,st,cost;
};

queue<node>q;

int main(){
	FAST_IO;
	int n;
	cin>>n; 
	rep(i,1,n) {
		int op,a,b,t;
		cin>>op;
		if(op==1){
			cin>>t>>a>>b;
			q.push(node{a,t,b});
		}
		if(op==2){
			cin>>t;
			while(!q.empty()){
				node tk=q.front();
				if(tk.st+tk.cost<=t)
					q.pop();
				else break;
			}
			if(!q.empty())
				q.pop();
		}
		if(op==3){
			cin>>t;
			while(!q.empty()){
				node tk=q.front();
				if(tk.st+tk.cost<=t)
					q.pop();
				else break;
			}
			if(q.empty())
				cout<<-1<<endl;
			else
				cout<<q.front().id<<endl;
		}
	}
	return 0;
}

