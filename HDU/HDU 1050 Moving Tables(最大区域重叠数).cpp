#include<stdio.h>
#include<string.h>
int main(){
	int count[205]; 
	int q,n,end,start,area1,area2,max;
	scanf("%d",&q);
	while(q--){
		scanf("%d",&n);
		memset(count,0,sizeof(count));
		for(int i=1;i<=n;i++){
			scanf("%d %d",&start,&end);
			if(start>end){//���ܳ��ִ�ŷ�����С�ŷ�������� 
				int temp=start;
				start=end;
				end=temp;
			}
			area1=(start+1)/2;
			area2=(end+1)/2;
			/*����count�����¼���ص����Σ�
			   �����������ģ�2,4,6,8,10������
                             1,3,5,7,9������
                1��2���ڵ�һ���Σ�4��3���ڵڶ����Ρ����� 
			*/ 
			for(int j=area1;j<=area2;j++){
				count[j]++;
			}
		}
		max=0;
		for(int i=1;i<=200;i++){//�ص������ģ����Ǳ��뾭�������Σ��𰸼�Ϊ����ص���*10 
			if(count[i]>max)
				max=count[i];
		}
		printf("%d\n",max*10);
	}
}
