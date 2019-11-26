#include <bits/stdc++.h>

using namespace std;
int pos[10000],adj[10000],connect[10000],u[100000],v[100000],deg[100000],m,r[10000],l[10000],somien=0;
int soluong=0;
bool dau[100000];
void adjlist()
{
    for (int i=1;i<=n;++i)
    {
        pos[i]=pos[i-1]+deg[i];
    }
    for (int i=1;i<=m;++i)
    {
        adj[pos[u[i]]]=v[i];
        pos[u[i]]--;
        adj[pos[v[i]]]=u[i];
        pos[v[i]]--;
    }
    pos[n+1]=2*m;
}
void dfs(int start)
{
    dau[start]=true;
    ++soluong;
    connect[soluong]=start;
    r[somien]++;
    for (int i=pos[start]+1;i<=pos[start+1];++i)
    {
        if (dau[adj[i]]==false)
        {
            dfs(adj[i]);
        }
    }
}
int main()
{
    int n;
    cin >> n >> m;
    for (int i=1;i<=m;++i)
    {
        cin >> u[i] >> v[i];
        ++deg[u[i]];++deg[v[i]];
    }
    adjlist();
    memset(dau,false,sizeof (dau));
    for (int i=1;i<=n;++i)
    {
        if (dau[i]==false)
        {
            somien++;
            l[somien] = r[somien-1]+1;
            r[somien]=l[somien]-1;
            dfs(i);
        }
    }
    cout <<somien << endl;
    for (int i=1;i<=somien;i++)
    {
        for (int j=l[i];j<=r[i];j++)
        {
            cout << connect[j]<<' ';
        }
        cout <<endl;
    }

}




