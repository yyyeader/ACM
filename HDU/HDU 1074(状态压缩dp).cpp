#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;

const int inf = 1<<30;

struct node{
    string name;
    int dead,cost;
} a[50];

struct kode{
    int time,score,pre,now;
} dp[1<<15];

void print(int n){
	if(n){
		print(dp[n].pre);
		cout<<a[dp[n].now].name<<endl;
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	
    int t,i,j,s,n,end;
    cin >> t;
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        cin >> n;
        for(i = 0; i<n; i++)
            cin >> a[i].name >> a[i].dead >> a[i].cost;
        end = 1<<n;
        for(s = 1; s<end; s++)//s��1��2^15
        {
            dp[s].score = inf;//���״̬�¿۵��ķ�����ʼ��Ϊ����� 
            for(i = n-1; i>=0; i--)
            {
                int tem = 1<<i;
                if(s & tem)
                {
                    int past = s-tem;//��һ��״̬�����λ��Ϊ0����s-temʹ�����λ��Ϊ0 
                    int st = dp[past].time+a[i].cost-a[i].dead;//����һ��Ҫ�۵��ķ��� 
                    if(st<0)//С��0˵��û�е������޼����۷� 
                        st = 0;
                    //������״̬��Ҫ�۵��ķ�����С���ǾͰ�����ϴ����λ�õ�״̬����Ϊ���ڵ�״̬ 
                    if(st+dp[past].score<dp[s].score)
                    {
                        dp[s].score = st+dp[past].score;
                        dp[s].now = i;
                        dp[s].pre = past;
                        dp[s].time = dp[past].time+a[i].cost;
                    }
                }
            }
        }
        int tem=end-1;
        cout << dp[tem].score << endl;
        print(tem);
    }
    return 0;
}

