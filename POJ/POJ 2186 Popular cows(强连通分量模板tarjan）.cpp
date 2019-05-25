#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
const int N=1e4+5;

int cnt,num;
int dfn[N],low[N],fa[N],sze[N],outdeg[N];  //dfn[i]Ϊ��i��dfs��low[i]Ϊ��i�ܻص��������dfs�� 
stack<int>sk;							   //fa[i]��ʾ��i������ǿ��ͨ������� 
vector<int>v[N];

void tarjan(int u){
    dfn[u]=low[u]=++cnt;
    sk.push(u);
    for(int i=0;i<v[u].size();i++){
        int t=v[u][i];
        if(!dfn[t]){                                        //��tδ������
            tarjan(t);
            low[u]=min(low[u],low[t]);
        }
        else if(!fa[t])  low[u]=min(low[u],dfn[t]);         //��t�ѱ����ʣ���t����ջ��
    }
    if(low[u]==dfn[u]){
        num++;
        while(1){
            int t=sk.top();
            sk.pop();
            fa[t]=num;                                      //�������������Щ�㶼��Ϊ��num
            sze[num]++;
            if(t==u) break;
        }
    }
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
    }
    for(int i=1;i<=n;i++){
        if(!fa[i]) tarjan(i);
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<v[i].size();j++){
            int t=v[i][j];
            if(fa[t]!=fa[i]) outdeg[fa[i]]++;
        }
    }
    //����󣬳���Ϊ0�ĵ�ֻ����һ�������򲻷����������0
    int ans=0;
    for(int i=1;i<=num;i++){
        if(!outdeg[i]){
            if(ans>0){
                puts("0");
                return 0;
            }
            ans=sze[i];
        }
    }
    printf("%d\n",ans);
    return 0;
}
