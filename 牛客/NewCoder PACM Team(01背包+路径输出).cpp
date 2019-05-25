#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define LL long long
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
const int N=38;
const int INF=0x3f3f3f3f;
int dp[N][N][N][N];
bool path[N][N][N][N][N];
  
struct node{
    int p,a,c,m,g;
}a[N];
  
vector<int>idx;
  
int main(){
    memset(dp,0,sizeof(dp));
    memset(path,0,sizeof(path));
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].p>>a[i].a>>a[i].c>>a[i].m>>a[i].g;
        if(a[i].p+a[i].a+a[i].c+a[i].m==0){
            a[i].p=a[i].a=a[i].c=a[i].m=INF;
            idx.push_back(i);
        }
    }
    int P,A,C,M;
    cin>>P>>A>>C>>M;
    int x=-1,y,z,w,ans=0;
    for(int i=1;i<=n;i++){
        for(int j=P;j>=a[i].p;j--){
            for(int k=A;k>=a[i].a;k--){
                for(int t=C;t>=a[i].c;t--){
                    for(int s=M;s>=a[i].m;s--){
                        int pre=dp[j-a[i].p][k-a[i].a][t-a[i].c][s-a[i].m];
                        int res=pre+a[i].g;
                        if(dp[j][k][t][s]<res){
                            path[i][j][k][t][s]=true;
                            dp[j][k][t][s]=res;
                        }
                    }
                }
            }
        }
    }
    for(int i=n;i>=1;i--){
    	if(path[i][P][A][C][M]){
    		idx.push_back(i);
    		P-=a[i].p;
    		A-=a[i].a;
    		C-=a[i].c;
    		M-=a[i].m;
		}
	}
    cout<<idx.size()<<endl;
    for(int i=0;i<idx.size();i++){
        cout<<idx[i]-1<<endl;
    }
    return 0;
}
