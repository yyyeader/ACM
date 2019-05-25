#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
const int N=2e4+5;			//������
const int M=1e5+5;			//������

struct node{
    int id,to;
    node(int id,int to):id(id),to(to){}
};
vector<node>v[N];
stack<int>sk;
int cnt,num;
int low[N],dfn[N],fa[M],mp[M];
//fa[i]Ϊ��i���������ĵ�˫��ͨ�������
//mp[i]Ϊ���Ϊi�ĵ�˫��ͨ����������С�ı��
//һ��ע��fa��mp�ķ�Χ�Ǳ����ķ�ΧM,���ǵ�����ΧN
void tarjan(int u,int f){
    low[u]=dfn[u]=++cnt;
    for(int i=0;i<v[u].size();i++){
        int t=v[u][i].to;
        int id=v[u][i].id;
        if(t==f) continue;
        if(!dfn[t]){	 	//����
            sk.push(id);	//����ջ
            tarjan(t,u);
            low[u]=min(low[u],low[t]);
            if(dfn[u]<=low[t]){
                num++;
                while(!sk.empty()){
                    int cur=sk.top();
                    sk.pop();
                    fa[cur]=num;                //��cur���䵽num��
                    if(mp[num]==0||mp[num]>cur)
                        mp[num]=cur;
                    if(cur==id) break;
                }
            }
        }
        else if(dfn[t]<dfn[u]){//�ر�
            low[u]=min(low[u],dfn[t]);
            sk.push(id);	//����ջ
        }
    }
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);;
    for(int i=1;i<=m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(node(i,b));
        v[b].push_back(node(i,a));
    }
    tarjan(1,-1);
    printf("%d\n",num);
    for(int i=1;i<=m;i++){
        printf("%d%c",mp[fa[i]],i==m?'\n':' ');
    }
    return 0;
}
