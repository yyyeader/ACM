#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e2+5;

int ans,n;
char mp[N][N];

bool judge(int row,int col){
    for(int i=row;i>=0;i--){
        if(mp[i][col]=='O') return false;
        if(mp[i][col]=='X') break;
    }
    for(int i=col;i>=0;i--){
        if(mp[row][i]=='O') return false;
        if(mp[row][i]=='X') break;
    }
    return true;
}

//posΪ��ǰλ�ã�numΪ����
void dfs(int pos,int num){
    if(pos==n*n){
        if(num>ans)
            ans=num;
        return;
    }
    int row=pos/n;
    int col=pos%n;
    if(mp[row][col]=='.'&&judge(row,col)){
        mp[row][col]='O';       //��ʾ��(row,col)��������
        dfs(pos+1,num+1);
        mp[row][col]='.';
    }
    dfs(pos+1,num);
}

int main(){
    while(~scanf("%d",&n)&&n){
        for(int i=0;i<n;i++){
            scanf("%s",&mp[i]);
        }
        ans=0;
        dfs(0,0);
        printf("%d\n",ans);
    }
    return 0;
}
