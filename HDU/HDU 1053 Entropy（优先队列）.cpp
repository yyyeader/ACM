#include<iostream>
#include<cstdio> 
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

char s[1005];
int mp[100];

int main(){
	while(~scanf("%s",s)){
		if(strcmp(s,"END")==0) break;
		memset(mp,0,sizeof(mp));
		int len=strlen(s);
		sort(s,s+len);
		s[len+1]='#';
		priority_queue<int,vector<int>,greater<int> >q;
		int cnt=1,idx=0;
		for(int i=1;i<=len;i++){
			if(s[i]!=s[i-1]){
				mp[idx++]=cnt;
				cnt=0;
			}
			cnt++;
		}
		for(int i=0;i<idx;i++) q.push(mp[i]);
		int sum=0;
		while(q.size()>1){
			int a=q.top();q.pop();
			int b=q.top();q.pop();
			a+=b;
			sum+=a;
			q.push(a);
		}
		if(sum==0) sum=len;
		printf("%d %d %.1f\n",len*8,sum,len*8.0/sum);
	}
	return 0;
}
