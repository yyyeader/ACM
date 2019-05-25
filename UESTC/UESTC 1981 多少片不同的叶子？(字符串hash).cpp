#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define ULL unsigned long long
using namespace std;
const int N=1e5+5;
const LL mod=1e9+7;
const LL p=131;

int len;
ULL H[N];
vector<ULL>v;
char str[N];

void cal_hash(){
	H[0]=0;
	for(int i=1;i<=len;i++)
		H[i]=(H[i-1]*p%mod+str[i])%mod;
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",str+1);
		len=strlen(str+1);
		cal_hash();
		v.push_back(H[len]);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	printf("%d\n",v.size());
	return 0;
}
