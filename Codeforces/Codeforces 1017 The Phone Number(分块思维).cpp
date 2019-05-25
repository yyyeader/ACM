#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#define LL long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
#define bug cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
using namespace std;
const int N=1e6+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;

int main(){
	int n;
	while(cin>>n){
		//��n�ֿ�,��ÿһ�鵹��,��lenΪ�鳤��,����len+n/len��С�����ݷֿ�֪ʶ,len=sqrt(n)��� 
		int len=sqrt(n); 
		if(n==1){ 
			cout<<1<<endl;
			continue;
		} 
		if(n%len){
			for(int i=n%len;i>=1;i--){
				cout<<i<<" ";
			}
		}
		for(int i=1+n%len;i<=n;i+=len){
			for(int j=i+len-1;j>=i;j--){
				cout<<j<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}

