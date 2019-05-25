#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
const int N=505;
const double eps = 1e-9;

int n,mod;
int dp[N][N],cost[N][N];

struct P
{
    double x, y;
    P(double x=0, double y=0):x(x), y(y) {}
    double add(double a, double b){
        if(fabs(a+b)<eps*(fabs(a)+fabs(b))) return 0;
        return a+b;
    }
    P operator + (P p){
        return P(add(x, p.x), add(y, p.y));
    }
    P operator - (P p){
        return P(add(x, -p.x), add(y, -p.y));
    }
    P operator *(double d){
        return P(x*d, y*d);
    }
    double dot(P p){                 //点积
        return add(x*p.x, y*p.y);
    }
    double det(P p){                 //差积
        return add(x*p.y, -y*p.x);
    }
}ps[N];

double dist(P a, P b){
    return sqrt((b-a).dot(b-a));
}

bool cmp_x(const P& p, const P& q){
    if(p.x!=q.x) return p.x < q.x;
    return p.y < q.y;
}

vector<P> convex_hull(P *ps, int n){
    sort(ps,ps+n,cmp_x);
    int k = 0;          //凸包顶点数
    vector<P> qs(n*2);
    //构造凸包的下侧
    for(int i=0; i<n; i++)
    {
        while(k>1 && (qs[k-1]-qs[k-2]).det(ps[i]-qs[k-1])<=0) k--;
        qs[k++] = ps[i];
    }
    //构造凸包的上侧
    for(int i=n-2,t=k; i>=0; i--)
    {
        while(k>t && (qs[k-1]-qs[k-2]).det(ps[i]-qs[k-1])<=0) k--;
        qs[k++] = ps[i];
    }
    qs.resize(k-1);
    return qs;
}

int getcost(P p1,P p2){
    return abs((int)p1.x+(int)p2.x)*abs((int)p1.y+(int)p2.y)%mod;
}

int main(){
    while(~scanf("%d%d",&n,&mod)){
        for(int i=0;i<n;i++){
            scanf("%lf%lf",&ps[i].x,&ps[i].y);
        }
        vector<P>tp;
        tp=convex_hull(ps,n);
        if(tp.size()<n){
            puts("I can't cut.");
            continue;
        }
        //注意，用获得的凸包做DP，即使用tp做DP,保证凸包上的点的顺序
        memset(cost,0,sizeof(cost));
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=i+2;j<n;j++){
                cost[i][j]=getcost(tp[i],tp[j]);
            }
        }
        for(int len=3;len<n;len++){
            for(int i=0;i+len<n;i++){
                int j=i+len;
                dp[i][j]=INF;
                for(int k=i+1;k<=j-1;k++){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+cost[i][k]+cost[k][j]);
                }
            }
        }
        printf("%d\n",dp[0][n-1]);
    }
    return 0;
}
