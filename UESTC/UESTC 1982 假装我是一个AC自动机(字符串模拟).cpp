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
#define per(i,a,b) for(int i=a;i>=b;i--)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
#define bug cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
using namespace std;
const int N=1e6+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;

string ans[N];
string str;
//注意没有';'的情况 
int main(){
	cin>>str;
	int cur=1;
	rep(i,0,str.length()-1){
		char ch=str[i];
		if(str[i]==';')
			cur++;
		else if(str[i]=='#')
			ans[cur]="";
		else if(str[i]=='@'){
			int k=0;
			while(str[i+1]!='@'){
				k=k*10+str[i+1]-'0';
				i++;
			}
			i++;
			ans[cur]+=ans[cur-k];
		}
		else ans[cur]+=str[i];
	} 
	rep(i,1,cur){ 
		cout<<ans[i]<<endl;
	}
	return 0;
}

