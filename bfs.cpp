#include <bits/stdc++.h>

using namespace std;
int pos[10000],adj[10000],hangdoi[10000],u[100000],v[100000],deg[100000],m,n;
bool dau[100000];
void adjlist()
{
    for (int i=1;i<=n;i++)
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
void bfs(int start)
{
    int le,ri,u;
    hangdoi[1]=start;
    le=1;ri=1;
    while (le<=ri)
    {
        u=hangdoi[le];
        le++;
        dau[u]=true;
        for (int i=pos[u]+1;i<=pos[u+1];++i)
        {
            if (dau[adj[i]]==false)
            {
                ri++;
                hangdoi[ri]=adj[i];
            }
        }
    }
}
void bfsearch(int start)
{
    int le,ri,u;
    hangdoi[1]=start;
    le=1;ri=1;
    while (le<=ri)
    {
        u=hangdoi[le];
        le++;
        dau[u]=true;
        for (int i=pos[u]+1;i<=pos[u+1];++i)
        {
            if (dau[adj[i]]==false)
            {
                ri++;
                hangdoi[ri]=adj[i];
            }
        }
    }
    for (int i=1;i<=ri;++i)
    {
        cout << hangdoi[i] <<' ';
    }
    cout << endl;
}
int main()
{
    int n,somien=0;
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
            bfs(i);
        }
    }
    cout <<somien << endl;
    memset(dau,false,sizeof (dau));
    for (int i=1;i<=n;++i)
    {
        if (dau[i]==false)
        {
            bfsearch(i);
        }
    }
}



