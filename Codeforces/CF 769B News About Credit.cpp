#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int>ii;
vector<ii>e; 
const int N=1e2+5;
int n,ans=0;
struct node{
	int count;//最多能传递的信息数量 
	int flag;//是否被传递到信息 
	int num;//序号 
}a[N];

bool cmp(node a,node b){
	return a.count>b.count;
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].count;
		a[i].flag=0;
		a[i].num=i;
	}
	if(a[1].count==0)
		cout<<"-1"<<endl;
	else{
		sort(a+2,a+n+1,cmp);//除了第一个，把其他学生按能传递信息数从大到小排列,要保证先传给信息数多的学生; 
		a[1].flag=1;
		for(int i=1;i<=n;i++){
			if(ans>=n-1)
				break;
			if(a[i].flag){
				int pos=i+1;
				while(a[i].count){
					if(!a[pos].flag){
						e.push_back(ii(a[i].num,a[pos].num));//存下两个学生学号 
						a[pos].flag=1;
						a[i].count--;
						ans++;
						if(ans>=n-1)
							break;
					}
					pos++;
				}
			}
		}
		if(ans>=n-1){
			cout<<ans<<endl;
			for(int i=0;i<e.size();i++){
				cout<<e[i].first<<" "<<e[i].second<<endl;
			}
		}
		else
			cout<<"-1"<<endl;
	}
	
}
