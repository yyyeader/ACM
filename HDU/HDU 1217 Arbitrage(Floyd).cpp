#include<iostream>
#include<string>
#include<map>
using namespace std;
const int N=35;
const int INF=1<<30-1;

int V,E;
double val[N][N];

void floyd(){
	for(int k=1;k<=V;k++){
		for(int i=1;i<=V;i++){
			for(int j=1;j<=V;j++){
				if(val[i][j]<val[i][k]*val[k][j])
					val[i][j]=val[i][k]*val[k][j];
			}
		}
	}
}

int main(){
	int cas=0;
	while(cin>>V&&V){
		map<string,int>mp;
		//路径初始化为0,各个点初始化为1 
		for(int i=1;i<=V;i++){
			for(int j=1;j<=V;j++){
				val[i][j]=(i==j?1:0);
			}
		}
		for(int i=1;i<=V;i++){
			string s;
			cin>>s;
			mp[s]=i;
		}
		cin>>E;
		for(int i=1;i<=E;i++){
			string s1,s2;
			double trate;
			cin>>s1>>trate>>s2;
			val[mp[s1]][mp[s2]]=trate;
		}
		floyd();
		bool flag=false;
		//每个点都看一遍是否可以获得利益 
		for(int i=1;i<=V;i++){
			if(val[i][i]>1){
				flag=true;
				break;
			}
		}
		if(flag){
			cout<<"Case "<<++cas<<": Yes"<<endl;
		}
		else{
			cout<<"Case "<<++cas<<": No"<<endl;
		}
	}
}
