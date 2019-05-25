#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
#define LL long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
#define bug cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
using namespace std;
const int N=1e6+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;

int idx[N];//idx[i]记录第i个括号所匹配的括号位置 

int main(){
	int n,k;
	string s;
	cin>>n>>k>>s;
	stack<int>sk;
	rep(i,0,s.length()-1){
		if(s[i]=='(')
			sk.push(i);
		else{
			int t=sk.top();sk.pop();
			idx[i]=t;	
			idx[t]=i;
		}
	}
	rep(i,0,s.length()-1){
		if(k==0) break;
		if(s[i]=='('){
			if(idx[i]-i+1<=k){
				k-=idx[i]-i+1;
				int t=idx[i];
				while(i<=t){
					cout<<s[i];
					i++;
				}
				i--;//注意，否则会跳过下一个括号,如6 4 (()())这组样例 
			}		
		}
	}
	return 0;
}

