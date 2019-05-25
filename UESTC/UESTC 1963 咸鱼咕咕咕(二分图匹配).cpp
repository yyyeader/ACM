#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int N=5e3+50;		//��󶥵���

int n,m;                //nΪ��������mΪ����
int link[N];            //link[y]=x,��y��xƥ��
bool vis[N];
char mp[105][105];
int idx[105][105],idy[105][105];
vector<int>v[N];

//��dfsѰ������·
bool can(int u){
    for(int i=0;i<v[u].size();i++){
        int t=v[u][i];
        if(!vis[t]){
            vis[t]=true;
            if(link[t]==-1||can(link[t])){ //���t��δ��ƥ�䣬����link[t]��x�����ҵ������ܹ�����ĵ�,���t���ø�uƥ��
                link[t]=u;
                return true;
            }
        }
    }
    return false;
}
//�������ƥ����
int max_match(){
    memset(link,-1,sizeof(link));
    int ans=0;
    for(int i=1;i<N;i++){
        memset(vis,false,sizeof(vis));
        if(can(i))
            ans++;
    }
    return ans;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",mp[i]+1);
	}
	int cnt,sum=0;
	for(int i=1;i<=n;i++){
		bool flag=false;
		cnt=0; 
		for(int j=1;j<=m;j++){	
			if(mp[i][j]=='o'){
				if(flag)
					cnt++,flag=false;
				idx[i][j]=i+cnt*n;
				sum++;
			}
			if(mp[i][j]=='+')
				flag=true;
		}
	}
	for(int j=1;j<=m;j++){
		bool flag=false;
		cnt=0;
		for(int i=1;i<=n;i++){
			if(mp[i][j]=='o'){
				if(flag)
					cnt++,flag=false;
				idy[i][j]=j+cnt*m;
			}
			if(mp[i][j]=='+')
				flag=true;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mp[i][j]=='o')
				v[idx[i][j]].push_back(idy[i][j]);
		}
	}
	cout<<sum-max_match()<<endl;
	return 0;
}
