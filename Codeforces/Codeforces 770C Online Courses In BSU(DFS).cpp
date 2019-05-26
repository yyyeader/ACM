#include<iostream>
#include<vector>
using namespace std;
const int N=1e5+5;
vector<int>v[N],e;
int a[N],tmp[N],sta[N],ans=0,count=0;

bool search(int n){
	int sign;
	for(int i=0;i<v[n].size();i++){
		if(tmp[v[n][i]]){
			if(sta[v[n][i]])
				return false;	
			sta[v[n][i]]=1;
			bool sign=search(v[n][i]);
			if(!sign)
				return false;
		}			
	}
	tmp[n]=0;
	sta[n]=0;
	e.push_back(n);
	count++;
	return true;
}

int main(){
	int m,n;
	int sign=1;
	scanf("%d %d",&m,&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++){
		int q,x;
		tmp[i]=1;
		scanf("%d",&q);
		for(int j=1;j<=q;j++){
			scanf("%d",&x);
			v[i].push_back(x);
		}	
	}
	
	for(int i=1;i<=n;i++){
		if(tmp[a[i]]){
			sign=search(a[i]);
			if(!sign)
				break;	
		}
	}
	if(sign){
		printf("%d\n",count);
		for(int i=0;i<e.size();i++){
			printf("%d ",e[i]);
		}
		printf("\n");
	}
	else{
		printf("-1\n");
	}
}
