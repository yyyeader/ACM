#include<iostream>
#include<cstdio>
#include<set>
#include<vector>
using namespace std;
const int N=3e5+5;
vector<int>v[N];
multiset<int>ms;

int main(){
	int n,a,b;
	int arr[N];
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",arr+i);
		ms.insert(arr[i]);
	}
	for(int i=1;i<=n-1;i++){
		scanf("%d %d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int ans=1<<30;
	multiset<int>::iterator it;
	for(int i=1;i<=n;i++){//����n�����У��ҵ���Ҫ�������������� 
		//��������i��ֵ����ms��ɾ�� 
		int temp=arr[i];
		ms.erase(ms.find(arr[i]));
		//�ҵ���i���ڵ����У��ȽϺ���ms��ɾ�� 
		for(int j=0;j<v[i].size();j++){
			int k=v[i][j];
			temp=max(temp,arr[k]+1);
			ms.erase(ms.find(arr[k]));
		}
		//�ȽϾ������2�������������ֵ+2��temp�Ĵ�С����֤ÿ�����ж����Թ��� 
		if(!ms.empty()){
			it=ms.end();
			temp=max(temp,*(--it)+2);
		}
		//��ԭms��ɾ����Ԫ�� 
		ms.insert(arr[i]);
		for(int j=0;j<v[i].size();j++){
			int k=v[i][j];
			ms.insert(arr[k]);
		}
		ans=min(temp,ans);//�ҵ�������������ٵ����� 
	}
	printf("%d\n",ans);
} 
