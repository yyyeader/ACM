#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int>ii;
vector<ii>e; 
const int N=1e2+5;
int n,ans=0;
struct node{
	int count;//����ܴ��ݵ���Ϣ���� 
	int flag;//�Ƿ񱻴��ݵ���Ϣ 
	int num;//��� 
}a[N];

bool cmp(node a,node b){
	return a.count>b.count;
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].count;
		a[i].flag=0;
		a[i].num=i;
	}
	if(a[1].count==0)
		cout<<"-1"<<endl;
	else{
		sort(a+2,a+n+1,cmp);//���˵�һ����������ѧ�����ܴ�����Ϣ���Ӵ�С����,Ҫ��֤�ȴ�����Ϣ�����ѧ��; 
		a[1].flag=1;
		for(int i=1;i<=n;i++){
			if(ans>=n-1)
				break;
			if(a[i].flag){
				int pos=i+1;
				while(a[i].count){
					if(!a[pos].flag){
						e.push_back(ii(a[i].num,a[pos].num));//��������ѧ��ѧ�� 
						a[pos].flag=1;
						a[i].count--;
						ans++;
						if(ans>=n-1)
							break;
					}
					pos++;
				}
			}
		}
		if(ans>=n-1){
			cout<<ans<<endl;
			for(int i=0;i<e.size();i++){
				cout<<e[i].first<<" "<<e[i].second<<endl;
			}
		}
		else
			cout<<"-1"<<endl;
	}
	
}
