#include <bits/stdc++.h>

#define maxn 10000

using namespace std;

int graph[maxn],length;

int n ;
int out[maxn];
void init()
{
    cin >> n ;
    for (int i=1;i<=n;++i)
    {
        cin >> graph[i] ;
    }
    length = 0;
}
void max_heapify(int a[],int i,int n)
{
    int left = 2*i,right = 2*i+1;
    int largest;
    if (left<=n && a[left]>a[i])
    {
        largest=left;
    }
    else largest = i;
    if (right<=n && a[right]>a[i]&&a[left]<a[right]) largest = right ;
    if (largest!=i)
    {
        swap(a[i],a[largest]);
        max_heapify(a,largest,n);
    }
}
void increase_val(int a[],int i,int val)
{
    if (val < a[i]) return ;
    a[i] = val ;
    while (i>1 && a[i/2]<a[i])
    {
        swap(a[i/2],a[i]);
        i=i/2 ;
    }
}
void insert_val(int val,int a[])
{
    ++length;
    a[length] = -1 ;
    increase_val(a,length,val);
}
void extract_max(int a[])
{
    if (length==0) return;
    a[1]=a[length];
    length=length-1;
    max_heapify(a,1,length);
}
int main()
{
    memset(out,0,sizeof(out));
    init();
    for (int i=1;i<=n;++i)
    {
        insert_val(graph[i],out);
    }
    extract_max(out);
    extract_max(out);
    extract_max(out);
    for (int i=1;i<=length;++i) cout << out[i] << ' ';
    return 0;
}
