#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
const int N=205;

map<char,int>mp;
vector<int>v[N];
int n;
int link[N];
bool vis[N];
char adm[N][5],eve[N][5];

int scmp(char *s1,char *s2){
    return mp[s1[0]]+mp[s1[1]]-(mp[s2[0]]+mp[s2[1]]);
}

bool dfs(int u){
	for(int i=0;i<v[u].size();i++){
		int t=v[u][i];
		if(!vis[t]){
			vis[t]=true;
			if(link[t]==-1||dfs(link[t])){
				link[t]=u;
				return true;
			}
		}
	}
	return false;
}

int max_match(){
	memset(link,-1,sizeof(link));
	int ans=0;
	for(int i=1;i<=n;i++){
		memset(vis,false,sizeof(vis));
		if(dfs(i)) ans++;
	}
	return ans;
}

int main(){
    for(int i=2;i<=9;i++){
        mp[char(i+'0')]=i*10;
    }
    mp['T']=100;
    mp['J']=110;
    mp['Q']=120;
    mp['K']=130;
    mp['A']=140;
    mp['C']=1;
    mp['D']=2;
    mp['S']=3;
    mp['H']=4;
    int t;
    while(~scanf("%d",&t)){
        while(t--){
            scanf("%d",&n);
            for(int i=0;i<N;i++) v[i].clear();
            for(int i=1;i<=n;i++){
                scanf("%s",adm[i]);
            }
            for(int i=1;i<=n;i++){
                scanf("%s",eve[i]);
            }
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(scmp(eve[i],adm[j])>0){
                        v[i].push_back(j+n);
                    }
                }
            }
            printf("%d\n",max_match());
        }
    }
    return 0;
}
