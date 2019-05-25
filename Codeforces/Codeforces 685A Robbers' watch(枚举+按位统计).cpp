#include<bits/stdc++.h>
#define lc(a) (a<<1)
#define rc(a) (a<<1|1)
#define MID(a,b) ((a+b)>>1)
#define fin(name)  freopen(name,"r",stdin)
#define fout(name) freopen(name,"w",stdout)
#define clr(arr,val) memset(arr,val,sizeof(arr))
#define _for(i,start,end) for(int i=start;i<=end;i++)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
typedef long long LL;
const int N=105;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

int used[7];

int main(){
	FAST_IO;
	int n,m;
	cin>>n>>m;
	
	int len1=0,len2=0;
	//зЂвтвЊ-1 
	for(int i=n-1;i!=0;i/=7)
		len1++;
	if(len1==0) len1++;
	for(int i=m-1;i!=0;i/=7)
		len2++;
	if(len2==0) len2++;
	LL ans=0;
	if(len1+len2<=7){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				memset(used,0,sizeof(used));
				bool flag=true;
				for(int k=1,tmp=i;k<=len1;k++){
					used[tmp%7]++;
					tmp/=7;
				}
				for(int k=1,tmp=j;k<=len2;k++){
					used[tmp%7]++;
					tmp/=7;
				}
				
				for(int k=0;k<7;k++){
					if(used[k]>1)
						flag=false;
				}
				ans+=flag;
			}
		}
	}
	
	cout<<ans<<endl;
	return 0;
}

