#include<iostream>
#include<cstring>
using namespace std;
const int N=100005;
const int INF=1<<30;

struct edge{
    int from,to,cost;
}es[N];//边 

int d[N];//出发点到i的最短距离 
int V,E;//顶点数、边数

//求解从顶点s出发到所有点的最短距离 
void shortest_path(int s){
    for(int i=1;i<=V;i++) d[i]=INF;
    d[s]=0;
    while(true){
        bool update=false;
        for(int i=1;i<=E;i++){
            edge e=es[i];
            if(d[e.from]!=INF&&d[e.to]>d[e.from]+e.cost){
                d[e.to]=d[e.from]+e.cost;
                update=true;
            }
			//为无向图时,是双向的 
            /*if(d[e.to]!=INF&&d[e.from]>d[e.to]+e.cost){
                d[e.from]=d[e.to]+e.cost;
                update=true;
            }
            */
        }
        if(!update) break;
    }
}
//如果返回true则存在负圈
bool find_negative_loop(){
	memset(d,0,sizeof(d));
	
	for(int i=1;i<=V;i++){
		for(int j=1;j<=E;j++){
			edge e=es[j];
			if(d[e.to]>d[e.from]+e.cost){
				d[e.to]=d[e.from]+e.cost;
				
				//如果第V次仍更新了,则存在负圈
				if(i==V) return true; 
			}
			//为无向图时,是双向的 
            /*if(d[e.from]>d[e.to]+e.cost){
                d[e.from]=d[e.to]+e.cost;
                
                if(i==V) return true; 
            }
            */
		}
	}
	return false;
} 

int main(){
    int n,m;
    while(cin>>V>>E&&(V||E)){
        for(int i=1;i<=E;i++){
            cin>>es[i].from>>es[i].to>>es[i].cost;
        }
        shortest_path(1);
        cout<<d[V]<<endl;
    } 
} 
