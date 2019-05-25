#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=2e6+5;

int len1,len2,ans;
int s[N],str[N],p[N];

void init(){
	str[0]=-2;
	str[1]=-1;
	for(int i=1;i<=len1;i++){
		str[i<<1]=s[i];
		str[i<<1|1]=-1;
	}
	len2=(len1<<1)+2;
	str[len2]=-3;
}

void manacher(){
    init();
	int id=-1,mx=-1;
	for(int i=1;i<len2;i++){
		if(mx>i) p[i]=min(p[id*2-i],mx-i);
		else p[i]=1;
		while(str[i+p[i]]==str[i-p[i]]){
		    //判断相邻数字是否满足不降（要跳过中间插入的数字，所以+2）
            if(p[i]>1){
                if(str[i-p[i]]>str[i-p[i]+2])
                    break;
            }
            p[i]++;
		}
		if(i+p[i]>mx){
			mx=p[i]+i;
			id=i;
			ans=max(p[i]-1,ans);
		}
	}
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&len1);
		for(int i=1;i<=len1;i++){
			scanf("%d",&s[i]);
		}
		ans=0;
		manacher();
		printf("%d\n",ans);
	}
	return 0;
}
