#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define CLR(arr,val) memset(arr,val,sizeof(arr))
using namespace std;
const int M=5e5+5;

struct Tire{
	Tire *next[26];
	int flag;
	Tire(){
		for(int i=0;i<26;i++)
			next[i]=NULL;
		flag=-1;
	}
};
int degree[M],fa[M],color;

int Insert(char *str,Tire *&root){//要插入的字符串str
	Tire *p=root;
	for(int i=0;str[i]!='\0';i++){
		int k=str[i]-'a';
		if(p->next[k]==NULL)
			p->next[k]=new Tire;
		p=p->next[k];
	}
	if(p->flag==-1)
		p->flag=++color;
	return p->flag;
}

void del(Tire *root){			//动态建树后要释放内存
    for(int i=0;i<26;i++)
        if(root->next[i])
            del(root->next[i]);
    delete(root);
}

int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

int main(){
	char str1[20],str2[20];
	Tire *root=new Tire;
	for(int i=1;i<M;i++){
		fa[i]=i;
	}
	while(~scanf("%s%s",str1,str2)){
		int u,v;
		u=Insert(str1,root);
		v=Insert(str2,root);
		degree[u]++;	
		degree[v]++;
		if(find(u)!=find(v))
			fa[find(u)]=find(v);
	}
	del(root);
	bool flag=true;
	int cnt1=0,cnt2=0,chu,ru;
	for(int i=1;i<=color;i++){
		if(find(i)==i)
			cnt1++;
		if(degree[i]%2==1)
			cnt2++;
	}
	//注意有字符串为0的情况,还有这是无向图 
	if((cnt1==1||cnt1==0)&&(cnt2==0||cnt2==2))
		puts("Possible");
	else
		puts("Impossible");
	return 0;
}
