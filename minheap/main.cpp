#include <bits/stdc++.h>

#define maxn 10000

using namespace std;

int graph[maxn];

int n ;

void init()
{
    cin >> n ;
    for (int i=1;i<=n;++i)
    {
        cin >> graph[i] ;
    }
}
void min_heapify(int a[],int i,int n)
{
    int left = 2*i , right = 2*i+1 , smallest ;
    if (left <= n && a[left]<a[i])
        smallest = left ;
    else
        smallest = i ;
    if (right<=n && a[right]<a[i] && a[right]<=a[left])
        smallest = right ;
    if (smallest != i )
    {
        swap(a[smallest],a[i]);
        min_heapify(a,smallest,n);
    }
}
void build_minheap()
{
    for (int i=n/2;i>=1;--i)
        min_heapify(graph,i,n);
}
int main()
{
    init();
    build_minheap();
    //heap_sort();
    for (int i=1;i<=n;++i) cout << graph[i] << ' ' ;
    return 0;
}
