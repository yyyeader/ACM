#include<bits/stdc++.h>
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
const int N=1e6+5;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

int dp[N];
stack<int>sk;

int main(){
	FAST_IO;
	string str;
	cin>>str;
	int len=0,cnt=0;
	for(int i=0;i<str.length();i++){
		if(str[i]=='(')
			sk.push(i);
		else{
			if(!sk.empty()){
				int t=sk.top();
				sk.pop();
				dp[i]=dp[t-1]+i-t+1;
				if(dp[i]>len){
					len=dp[i];
					cnt=1;
				}
				else if(dp[i]==len) 
					cnt++;
			}
		}
	}
	if(len==0)
		cout<<"0 1"<<endl;
	else
		cout<<len<<" "<<cnt<<endl;
	return 0;
}

