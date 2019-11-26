#include <bits/stdc++.h>
using namespace std;
#define maxn 10001
int s,t,n,m,soluong=0,nho=maxn;
int pos[maxn],adj[maxn],deg[maxn],u[maxn],v[maxn],d[maxn],trace[maxn],res,a[maxn],hangdoi[maxn];
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
void bfs(int start)
{
    int le,ri,us;
    le=1;ri=1;
    trace[start]=-1;
    hangdoi[1]=start;
    while (le<=ri)
    {
        us=hangdoi[le];
        le++;
        dau[us]=true;
        for  (int i=pos[us]+1;i<=pos[us+1];++i)
        {
            if (dau[adj[i]]==false)
            {
                ri++;
                hangdoi[ri]=adj[i];
                d[adj[i]]=d[us]+1;
                trace[adj[i]]=us;
                if (adj[i]==t) return;
            }
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
    for (int i=1;i<=n;++i)
    {
        qsort(pos[i]+1,pos[i+1]);
    }
    memset(dau,false,sizeof(dau));
    buildadjlist();
    bfs(s);
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



