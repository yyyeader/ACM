#include<stdio.h>
#include<string.h>
const int N=500005;
int a[N],res[N];
int find(int n,int l,int r){
	int mid;
	while(l<=r){
		mid=(l+r)/2;
		if(res[mid]<n)
			l=mid+1;
		else
			r=mid-1;
	}
	return l;
}
int main(){
	int n,from,to,i,pos,ans,num=1;
	while(~scanf("%d",&n)){
		ans=1;
		memset(res,0,sizeof(res));
		memset(a,0,sizeof(a));
		for(i=1;i<=n;i++){
			scanf("%d %d",&from,&to);
			a[from]=to;
		}
		res[1]=a[1];
		for(i=2;i<=n;i++){
			pos=find(a[i],1,ans);
			res[pos]=a[i];
			if(pos>ans)
				ans++;
		}
		if(ans==1)
			printf("Case %d:\nMy king, at most %d road can be built.\n\n",num++,ans);
		else
			printf("Case %d:\nMy king, at most %d roads can be built.\n\n",num++,ans);
	}
}
