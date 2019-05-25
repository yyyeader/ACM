//这题让我学会了，以后复杂的输出格式全用cin，用scanf疯狂错泪奔- -、、、 
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int root[30];
struct node{
	int a,b,value;
}a[1005];

int find(int n){
	int temp=n;
	while(n!=root[n]){
		n=root[n]; 
	}
	root[temp]=n;
	return n;
}

bool cmp(node a,node b){
	return a.value<b.value;
}

int main(){
	int n,i,j,cnt,count,val,ans;
	char c,tc,temp;
	while(cin>>n&&n){
		ans=count=0;
		memset(a,0,sizeof(a));
		for(i=1;i<=28;i++){
			root[i]=i;
		}
		for(i=1;i<=n-1;i++){
			cin>>c>>cnt;
			for(j=1;j<=cnt;j++){
				cin>>tc>>val;
				a[count].a=c-'A'+1;
				a[count].b=tc-'A'+1;
				a[count].value=val;
				count++;
			}
		}
		sort(a,a+count,cmp);

		for(i=0;i<count;i++){
			int t1=find(a[i].a);
			int t2=find(a[i].b);
			if(t1!=t2){
				root[t1]=t2;
				ans+=a[i].value;
			}
		}
		printf("%d\n",ans);	
	}
} 
