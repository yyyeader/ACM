#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
const int N=205;

map<char,int>mp;
int n;
int adm[N],eve[N];
bool vis[N];
char ch[5];

int main(){
    for(int i=2;i<=9;i++){
        mp[char(i+'0')]=i*10;
    }
    mp['T']=100;
    mp['J']=110;
    mp['Q']=120;
    mp['K']=130;
    mp['A']=140;
    mp['C']=1;
    mp['D']=2;
    mp['S']=3;
    mp['H']=4;
    int t;
    while(~scanf("%d",&t)){
        while(t--){
            scanf("%d",&n);
            memset(vis,false,sizeof(vis));
            for(int i=1;i<=n;i++){
                scanf("%s",ch);
                adm[i]=mp[ch[0]]+mp[ch[1]];
            }
            for(int i=1;i<=n;i++){
                scanf("%s",ch);
                eve[i]=mp[ch[0]]+mp[ch[1]];
            }
            int ans=0;
            sort(eve+1,eve+1+n);
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(!vis[j]&&eve[j]>adm[i]){
                        vis[j]=true;
                        ans++;
                        break;
                    }
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
