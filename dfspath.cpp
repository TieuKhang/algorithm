#include <bits/stdc++.h>
using namespace std;
#define maxn 10001
int s,t,n,m,soluong=0,nho=maxn;
int pos[maxn],adj[maxn],deg[maxn],u[maxn],v[maxn],d[maxn],trace[maxn],res,a[maxn];
bool dau[maxn];
void qsort(int le,int ri)
{
    int i,j,x;
    i=le;j=ri;x=adj[(le+ri)/2];
    while (i<=j)
    {
        while (adj[i]<x) i++;
        while (adj[j]>x) j--;
        if (i<=j)
        {
            swap(adj[i++],adj[j--]);
        }
    }
    if (i<ri) qsort(i,ri);
    if (le<j) qsort(le,j);
}
void buildadjlist()
{
    for (int i=1;i<=n;++i)
    {
        pos[i]=pos[i-1]+deg[i];
    }
    for (int i=1;i<=m;i++)

    {
        adj[pos[u[i]]]=v[i];
        pos[u[i]]--;
    }
    pos[n+1]=m+1;
}
void dfs(int start)
{
    dau[start]=true;
    for  (int i=pos[start]+1;i<=pos[start+1];i++)
    {
        if (dau[adj[i]]==false)
        {
            d[adj[i]]=d[start]+1;
            trace[adj[i]]=start;
            dfs(adj[i]);
        }
    }
}
int main()
{
    cin >>  n >> m >> s >> t;
    for (int i=1;i<=m;++i)
    {
        cin >> u[i] >> v[i];
        ++deg[u[i]];
    }
    memset(dau,false,sizeof(dau));
    buildadjlist();
    for (int i=1;i<=n;++i)
    {
        qsort(pos[i]+1,pos[i+1]);
    }
    trace[s]=-1;
    dfs(s);
    while (t!=-1)
    {
        ++res;
        a[res]=t;
        t=trace[t];
    }
    for (int i=res;i>=1;--i)
    {
        cout << a[i] <<' ';
    }
    return 0;
}

