#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<stack>
#define LL long long
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
const int N=1e5+5;

struct node{
	int l,r;
	node(){}
}a[N];

char str[N];

bool cmp(node a,node b){
	if(a.l>a.r&&b.r>=b.l)
		return true;
	if(a.l<=a.r&&b.r<b.l)
		return false;
	if(a.r>=a.l&&b.r>=b.l)
		return a.l>b.l;
	return a.r<b.r;
}

int main(){
	FAST_IO;
	int T;
	scanf("%d",&T);
	while(T--) {
		int ans=0;
		int n;
		scanf("%d",&n);
		for(int t=1;t<=n;t++){
			scanf("%s",str);
			int len=strlen(str);
			stack<char>sk;
			int l=0,r=0;
			for(int i=0;i<len;i++){
				if(str[i]=='('){
					sk.push(str[i]);
				}
				else if(sk.empty())
					r++;
				else{
					sk.pop();
					ans+=2;
				}
			}
			l=sk.size();
			a[t].l=l,a[t].r=r;
		}
		sort(a+1,a+1+n,cmp);
		string st="";
		for(int i=1;i<=n;i++){
			while(a[i].r>0){
				st+=')';
				a[i].r--;
			}
			while(a[i].l>0){
				st+='(';
				a[i].l--;
			}
		}
		stack<char>sk;
		for(int i=0;i<st.length();i++){
			if(st[i]=='('){
				sk.push(st[i]);
			}
			else if(!sk.empty()){
				sk.pop();
				ans+=2;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

