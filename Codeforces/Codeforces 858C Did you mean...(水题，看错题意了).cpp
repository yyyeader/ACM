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
const int N=5e6+5;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

int flag[300];
//看错题意了，以为只要三个一样就可以看做不存在，结果是只针对于这三个而言不算错，对于接下来的还是要算上它们 
int main(){
	flag['a']=flag['e']=flag['i']=flag['o']=flag['u']=1;
	FAST_IO;
	string str;
	cin>>str;
	int cnt=0;
	for(int i=0;i<str.length();i++){
		if(flag[str[i]])
			cnt=0;
		else{
			cnt++;
			if(cnt>=3){
				if(str[i]==str[i-1]&&str[i-1]==str[i-2]) cnt=2;
				else{
					cnt=1;
					cout<<" ";
				}
			}
		}
		cout<<str[i];
	}
	return 0;
}
