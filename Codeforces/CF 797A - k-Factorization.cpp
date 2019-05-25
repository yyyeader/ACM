#include<iostream>
#include<cstdio>
#include<vector> 
using namespace std;
vector<int>v;

int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	int d=2;
	while(k&&n>=d){//n>=d因为要保证n是够除的，否则说明不能分解成k个因数 
		if(k==1){//k=1时，最后一个因数就是除剩下的那个 
			v.push_back(n);
			k--;
			break;
		}
		if(n%d==0){//n能被d除掉 
			n/=d;
			k--;
			v.push_back(d);
		}
		else//如果n不能被d除掉,说明n里所有d都已经除完了，那d的值就要增加 
			d++;
	}
	if(k)//凑不够k个 
		printf("-1\n");
	else{
		for(int i=0;i<v.size();i++)
			printf("%d ",v[i]);
		printf("\n");
	} 
} 
