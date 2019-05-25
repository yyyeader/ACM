#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e2+5;
const int INF=0x3f3f3f3f;

int n,m;
int mp[N][N];

int cal(int k){
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            //����λ�����ͬΪ0��1,˵��������λ�ô���ͬһ������
            //Ϊ��ʹ���Ϊ����ͼ������ɾ�����������бߣ����رߣ�
            if((1&(k>>i))==(1&(k>>j))) ans+=mp[i][j];
        }
    }
    return ans;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        memset(mp,0,sizeof(mp));
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            mp[a][b]++;mp[b][a]++;
        }
        int ans=INF;
        //ע������
        if(n==0||m==0) ans=0;
        //����ö��n������״̬��Ϊ0����Ϊ1)
        for(int i=1;i<(1<<n);i++){
            ans=min(ans,cal(i));
        }
        printf("%d\n",ans);
    }
    return 0;
}
