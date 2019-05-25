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
	for(int i=1;i<=n;i++){//遍历n家银行，找到需要最少能量的银行 
		//存下银行i的值后，在ms中删除 
		int temp=arr[i];
		ms.erase(ms.find(arr[i]));
		//找到跟i相邻的银行，比较后，在ms中删除 
		for(int j=0;j<v[i].size();j++){
			int k=v[i][j];
			temp=max(temp,arr[k]+1);
			ms.erase(ms.find(arr[k]));
		}
		//比较距离大于2的银行能量最大值+2和temp的大小，保证每个银行都可以攻击 
		if(!ms.empty()){
			it=ms.end();
			temp=max(temp,*(--it)+2);
		}
		//还原ms中删除的元素 
		ms.insert(arr[i]);
		for(int j=0;j<v[i].size();j++){
			int k=v[i][j];
			ms.insert(arr[k]);
		}
		ans=min(temp,ans);//找到所有情况中最少的能量 
	}
	printf("%d\n",ans);
} 
