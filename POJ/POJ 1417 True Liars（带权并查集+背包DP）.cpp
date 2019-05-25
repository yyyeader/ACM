#include<cstdio>
#include<cmath>
#include<cctype>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<string>
#define LC(a) (a<<1)
#define RC(a) (a<<1|1)
#define MID(a,b) ((a+b)>>1)
using namespace std;
typedef long long LL;
const int N=1500;

int root[N],val[N],num[N],dp[N][N],f[N][2];//f[i][0]、f[i][1]分别记录第i个并查集里两个种类的数量 

int find(int x){
	if(root[x]==x)
		return x;
	int tmp=find(root[x]);
	val[x]=(val[x]+val[root[x]])%2;
	return root[x]=tmp;
}

int main(){
	int m,p1,p2;
	while(~scanf("%d%d%d",&m,&p1,&p2)){
		if(m==0&&p1==0&&p2==0)
			break;
		memset(dp,0,sizeof(dp));
		memset(f,0,sizeof(f));
		memset(val,0,sizeof(val));
		memset(num,0,sizeof(num));
		for(int i=1;i<=p1+p2;i++){
			root[i]=i;
		}
		for(int i=1;i<=m;i++){
			int a,b;
			char s[10];
			scanf("%d%d%s",&a,&b,s);
			int t1=find(a);
			int t2=find(b);
			if(t1!=t2){
				root[t2]=t1;
				if(s[0]=='y')
					val[t2]=(val[a]-val[b]+2)%2;
				if(s[0]=='n')
					val[t2]=(val[a]-val[b]+1+2)%2;
			}
		}
		int cnt=0;
		for(int i=1;i<=p1+p2;i++){
			if(root[i]==i){
				num[++cnt]=i;
				for(int j=1;j<=p1+p2;j++){
					if(find(j)==i){
						if(val[j]==0){
							f[cnt][0]++;
						}
						else{
							f[cnt][1]++;
						}			
					}
				}
			}
		}
		//DP
		dp[0][0]=1;
		for(int i=1;i<=cnt;i++){
			for(int j=p1;j>=0;j--){
				int t=f[i][0];
				if(j-t>=0&&dp[i-1][j-t])
					dp[i][j]+=dp[i-1][j-t];//之前错写成dp[i][j]++ 
				t=f[i][1];
				if(j-t>=0&&dp[i-1][j-t])
					dp[i][j]+=dp[i-1][j-t];
			}
		}
		if(dp[cnt][p1]!=1)
			puts("no");
		else{		
			vector<int> ans;
			ans.clear();
			int tmp=p1;
			//寻找原来DP的路径 
			for(int i=cnt;i>=1;i--){
				for(int j=0;j<=1;j++){
					if(tmp-f[i][j]>=0&&dp[i-1][tmp-f[i][j]]==1){
						for(int k=1;k<=p1+p2;k++){
							if(find(k)==num[i]&&val[k]==j)
								ans.push_back(k);
						}
						tmp-=f[i][j];
						break;//一定要break 
					}
				}
			}
			sort(ans.begin(),ans.end());
			for(int i=0;i<ans.size();i++){
				printf("%d\n",ans[i]); 
			}
			puts("end");
		}
	}
	return 0;
}
