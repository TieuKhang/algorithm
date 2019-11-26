#include <bits/stdc++.h>

using namespace std;

#define maxn 1010

vector < int > graph[maxn],cost[maxn] ;

int n,m ,n1,n2,dist[maxn] ,val;

bool vis[maxn];

typedef pair<int,int> pp ;

void init()
{
    cin >> n >> m ;
    for (int i=1;i<=m;++i)
    {
        cin >> n1 >> n2 >> val ;
        graph[n1].push_back(n2);
        cost[n1].push_back(val);
        graph[n2].push_back(n1);
        cost[n2].push_back(val);
    }
    memset(vis,false,sizeof(vis));
    for (int i=1;i<=n;++i) dist[i] = INT_MAX ;
}

priority_queue < pp,vector<pp>,greater<pp> > qu ;
void dijkstra(int node )
{
    dist[node] = 0 ;
    qu.push(make_pair(0,node));
    while (!qu.empty())
    {
        pair<int,int> dd = qu.top();
        qu.pop();
        int curdist = dd.first ; int curnode = dd.second ;
        if ( vis[curnode] == false ) vis[curnode] = true ;
        for (int i=0;i<graph[curnode].size();++i)
        {
            int u = graph[curnode][i];
            if ( vis[u] == false )
            {
                int newdist = dist[curnode] + cost[curnode][i] ;
                if (newdist < dist[u] )
                {
                    dist[u] = newdist ;
                    qu.push(make_pair(newdist,u));
                }
            }
        }
    }
}
void print()
{
    dijkstra(1);
    for (int i=1;i<=n;++i) cout << dist[i] << ' ' ;
}
int main()
{
    init();
    print();
    return 0;
}
