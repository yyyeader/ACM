#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
const int N=15;
const int M=3e3+5;

int w;
LL dp[N][M];
bool can[M][M];//can[i][j]记录当前行为状态i上一行为状态j是否合理 

bool check1(int x){
	for(int i=0;i<w;i++){
		int t1=(1<<i);
		int t2=(1<<(i+1));
		if(t1&x){
			if(!(t2&x)||i==w-1)
				return false;
			i++;
		}
	}
	return true;
}

bool check2(int x,int y){
	for(int i=0;i<w;i++){
		int t1=(1<<i);
		if(!(t1&y)&&!(t1&x))
			return false;
		if(!(t1&y)&&(t1&x))
			x-=t1;
	}
	if(check1(x))
		return true;
	return false;
}

//作上下两行是否合理判断的预处理  
void get(){
	int lim=(1<<w);
	for(int i=0;i<lim;i++){
		for(int j=0;j<lim;j++){
			if(check2(i,j))
				can[i][j]=true;
		}
	}
}

int main(){
	int h;
	while(cin>>h>>w){
		if(h==0&&w==0) break;
		if(h<w)
			swap(h,w);
		memset(dp,0,sizeof(dp));
		memset(can,false,sizeof(can));
		if(h*w%2){
			cout<<0<<endl;
			continue;
		}
		if(h==1){
			cout<<1<<endl;
			continue;
		}
		get();
		
		int lim=(1<<w);
		for(int i=0;i<h;i++){
			if(i==0){
				for(int j=0;j<lim;j++){
					if(check1(j))
						dp[i][j]=1;
				}
				continue;
			}
			for(int j=0;j<lim;j++){
				for(int k=0;k<lim;k++){
					if(can[j][k]){
						dp[i][j]+=dp[i-1][k];
					}
				}
			}
		}
		cout<<dp[h-1][lim-1]<<endl;
	}
	return 0;
}

