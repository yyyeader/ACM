#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1e4+5;
bool prime[N];
int cnt[N];
int ans[N];

void is_prime(void){
	for(int i=2;i<N;i++)
		prime[i]=true;
	for(int i=2;i*i<N;i++){
		if(prime[i]){
			for(int j=i*i;j<N;j+=i){
				prime[j]=false;
			}
		}
	}
}
//万进制高精度乘法 
void Mul(int a[],int num)
{
    for(int i=0; i<1000; i++)
        a[i] = a[i]*num;
    for(int i=0; i<1000; i++)
    {
        a[i+1] += a[i]/10000;
        a[i] = a[i]%10000;
    }
}

void Puts(int a[]){
	int pos=1000;
	while(pos>=0&&ans[pos]==0) 
		pos--;
	printf("%d",ans[pos--]);
	while(pos>=0)
		printf("%04d",ans[pos--]);
	printf("\n");	
}

int main(){
	is_prime();
	int T;
	scanf("%d",&T);
	int cas=0;
	while(T--){
		memset(cnt,0,sizeof(cnt));
		memset(ans,0,sizeof(ans));
		int n;
		scanf("%d",&n);
		while(n--){
			int x;
			scanf("%d",&x);
			int d=2,count=0;
			//把数字进行素因子分解,用cnt[]记录每种素因子出现的最大次数 
			while(d<=x){ 
				if(x%d==0&&prime[d]){
					x/=d;
					count++;
					cnt[d]=max(count,cnt[d]);
				}
				else{
					d++;
					count=0;
				}		
			}
		}
		//用高精度乘法,把素因子按对应次数乘起来
		ans[0]=1;
		for(int i=1;i<N;i++){
			if(cnt[i]){
				int t=1;
				while(cnt[i]--)
					t*=i;
				Mul(ans,t); 
			}
		}
		//输出
		printf("Case %d: ",++cas);
		Puts(ans);
	}
} 
