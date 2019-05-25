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

int main(){
	FAST_IO;
	string str;
	cin>>str;
	int ans=0;
	//如果有三个一样的如'aaa'只需修改中间的如'aba'即可 
	for(int i=0;i<(int)str.length()-2;i++){
		if(str[i]==str[i+1]&&str[i+1]==str[i+2]){
			if(str[i]=='z')
				str[i+1]-=1;
			else
				str[i+1]+=1; 
		}
	}
	//按顺序遍历，相同的就修改成不同的即可 
	for(int i=0;i<(int)str.length()-1;i++){
		if(str[i]==str[i+1]){
			for(char j='a';j<='z';j++){
				if(i!=0){
					if(j!=str[i-1]&&j!=str[i+1]){
						str[i]=j;
						break;
					}	
				}
				else{
					if(j!=str[i+1]){
						str[i]=j;
						break;
					}
				}
			}
		}
	}
	cout<<str<<endl;
	return 0;
}

