#include<iostream>
#include<string>
#include<map>
#include<queue>
using namespace std;
const int N=35;
const int INF=1<<30-1;
struct edge{
	int from,to;
	double rate;
}eg[N*N];

int V,E;
double d[N];

bool bellman_ford(int s){
	for(int i=1;i<=V;i++){
		d[i]=0;
	}
	d[s]=1.0;//��ʼ����Ϊ1 
	
	for(int i=1;i<=V;i++){
		for(int j=1;j<=E;j++){
			edge e=eg[j];
			//�������жϻ᲻���� 
			if(d[e.to]<d[e.from]*e.rate){
				d[e.to]=d[e.from]*e.rate;
				if(i==V) return true;//�뵱��d[s]>1.0 
			}
		}
	}
	return false; 
}

int main(){
	int cas=0;
	while(cin>>V&&V){
		map<string,int>mp;
		string s;
		for(int i=1;i<=V;i++){
			cin>>s;
			mp[s]=i;
		}
		cin>>E;
		for(int i=1;i<=E;i++){
			string s1,s2;
			double rate;
			cin>>s1>>rate>>s2;
			eg[i].from=mp[s1];
			eg[i].to=mp[s2];
			eg[i].rate=rate;
		}
		bool flag=false;
		//��ÿ�ֻ��Ҷ�����һ�� 
		for(int i=1;i<=V;i++){
			flag=bellman_ford(i);
			if(flag){	
				cout<<"Case "<<++cas<<": Yes"<<endl;
				break;
			}
		}
		if(!flag)
			cout<<"Case "<<++cas<<": No"<<endl;
	}
	return 0;
}
