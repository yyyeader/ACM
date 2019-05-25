#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N=2e6+5;

LL ans;
int n,len1,len2,idx,root;
char s[N],str[N*2];
int trie[N][27],p[N*2],End[N],hou[N];//cnt[i]��ʾ�Խڵ�iΪ��β���ַ�������Ŀ
                                     //hou[i]��ʾ�ڵ�i֮��(������i)�ĺ�׺���Ĵ���Ŀ

struct node{
    int st,len;
}a[N];

void init(){
    str[0]='$';
    str[1]='#';
    len1--;
    for(int i=1;i<=len1;i++){
        str[i*2]=s[i];
        str[i*2+1]='#';
    }
    len2=len1*2+2;
    str[len2]='@';
}

void manacher(){
    init();
    int id=-1,mx=-1;
    for(int i=1;i<len2;i++){
        if(mx>i) p[i]=min(p[id*2-i],mx-i);
        else p[i]=1;
        while(str[i-p[i]]==str[i+p[i]])
            p[i]++;
        if(i+p[i]>mx){
            mx=i+p[i];
            id=i;
        }
    }
}

//���ַ�����������ֵ�����
void Insert(){
    for(int i=0;i<n;i++){
        int now=root;
        for(int j=a[i].st;j<a[i].st+a[i].len;j++){
            if(!trie[now][s[j]-'a']) trie[now][s[j]-'a']=++idx;
            now=trie[now][s[j]-'a'];
            int mid=((j+1)*2-1+(a[i].st+a[i].len-1)*2+1)/2;//(j+1)*2��s[j+1]��Ӧstr��λ��(j+1)*2-1���Ǳ�Ե��'#',ͬ��(a[i].st+a[i].len-1)*2+1Ҳ��Ӧ��Ե'#'
            if(p[mid]>mid-(j+1)*2+1)
                hou[now]++;
        }
        hou[now]--;                                        //��Ϊ�ַ���ĩβ��"#"Ҳ���һ�����Ĵ��ˣ�����Ҫ����
        End[now]++;
    }
}

//����������ɵĻ��Ĵ���
void Find(){
    for(int i=0;i<n;i++){
        int now=root;
        for(int j=a[i].st+a[i].len-1;j>=a[i].st;j--){
            //ƥ��ʧ�ܣ�û�ж�Ӧ���ַ���
            if(!trie[now][s[j]-'a']){
                now=-1;
                break;
            }
            now=trie[now][s[j]-'a'];
            if(End[now]){                                   //����ٻ��
                int mid=(a[i].st*2-1+(j-1)*2+1)/2;
                if(p[mid]>mid-a[i].st*2+1)
                    ans+=End[now];
            }
        }
        if(now!=-1) ans+=hou[now];                          //�����
    }
}

int main(){
    while(~scanf("%d",&n)){
        idx=0,len1=1,ans=0;
        memset(trie,0,sizeof(trie));
        memset(End,0,sizeof(End));
        memset(hou,0,sizeof(hou));
        for(int i=0;i<n;i++){
            scanf("%d",&a[i].len);
            scanf("%s",s+len1);
            a[i].st=len1;
            len1+=a[i].len;
        }
        manacher();
        Insert();
        Find();
        printf("%lld\n",ans);
    }
    return 0;
}
