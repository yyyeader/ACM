#include<cstdio>
#include<queue>
#include<map>
#include<cstring>
#include<string>
using namespace std;


int main(){
	int T;
	scanf("%d",&T);
	int cas=0;
	while(T--){
		char s1[105],s2[105],s3[205],res[205];
		int len;
		scanf("%d",&len);
		scanf("%s%s%s",s1+1,s2+1,res+1);
		map<string,int>mp;
		int ans=0;
		while(1){
			ans++;
			for(int i=1;i<=2*len;i++){
				if(i%2)
					s3[i]=s2[(i+1)/2];
				else
					s3[i]=s1[i/2];
			}
			s3[2*len+1]='\0';
			for(int i=1;i<=2*len;i++){
				if(i<=len)
					s1[i]=s3[i];
				else
					s2[i-len]=s3[i];
			}
			if(strcmp(res+1,s3+1)==0)
				break;
			if(mp.find(s3)==mp.end())
				mp[s3]=1;
			else{
				ans=-1;
				break;
			}		
		} 
		printf("%d %d\n",++cas,ans);
	}
	return 0;
} 
