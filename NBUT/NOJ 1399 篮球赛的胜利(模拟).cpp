#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<string>
#include<queue>
#include<set>
#include<map>
#include<vector>
#define lc(x) (x<<1)
#define rc(x) (x<<1|1)
#define LL long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
#define bug cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
#define bugc(_) cout << (#_) << " = " << (_) << endl;
using namespace std;
const double eps=1e-8;
const int N=1e6+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;

int main(){
	int n;
	while(~scanf("%d",&n)){
		if(n==0)
			break;
		int s1=0,s2=0;
		for(int i=1;i<=2*n;i++){
			int a,b,c,d,e,f;
			scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
			if(i%2)
				s1+=a*b+c*d+e*f;
			else
				s2+=a*b+c*d+e*f;
		}
		if(s1>s2)
			printf("acm  is No.1!!\n");
		else if(s1==s2)
		 	printf("i will do better next time\n");
		else
			printf("acm is on the way!\n");
	}
	return 0;
}

