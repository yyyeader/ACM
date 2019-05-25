#include<stdio.h>
int count=0,line[10],n;
void search(int x){	//递归搜索可行解 
	int i,j,ok;
	if(x==n+1) {//当x=n时，说明每一行的皇后都不冲突，即为可行解 
	  	for(i=1;i<n+1;i++){
	  		if(i!=n)
			  printf("%d ",line[i]);
			 else
			  printf("%d\n",line[i]);
		}
		count++;
		return;
	}
		for(i=1;i<=n;i++)
		{
			ok=1;
			line[x]=i;//尝试把第x行的皇后放在i列上
			for(j=1;j<x;j++)//检验是否与面已放好冲突前的皇后
			{
				if(line[x]==line[j]||x-line[x]==j-line[j]||x+line[x]==j+line[j])
				{
					ok=0;
					break;//跳出最内层循环如果冲突，停止搜索，返回上一级递归回溯。
				}
			}
			if(ok==1)
				search(x+1);
		}
}
int main(){
	scanf("%d",&n);
	search(1);
	printf("%d\n",count);
}
