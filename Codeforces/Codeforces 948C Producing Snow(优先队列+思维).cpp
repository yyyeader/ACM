#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<functional>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N=1e5+5;

LL t[N],sum[N],v[N];                             //sum[i]��t[i]��ǰ׺��

int main(){
    priority_queue<LL,vector<LL>,greater<LL> >q;
    int n,m;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&v[i]);

    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&t[i]);
        sum[i]=t[i]+sum[i-1];
    }
    for(int i=1;i<=n;i++){
        q.push(v[i]+sum[i-1]);                  //����sum[i-1]�������ڼ���ʱ��ǰһ��û�����ڵ�sum[i-1]������
        LL ans=t[i]*q.size();                   //�ȼ���û��һ��ѩ��������t[i]
        while(!q.empty()&&q.top()<=sum[i]){     //�ҵ�����t[i]�ģ�������ֵ�������Ĳ��֣�
            ans+=q.top()-sum[i];
            q.pop();
        }
        printf("%lld%c",ans,i==n?'\n':' ');
    }
    return 0;
}
