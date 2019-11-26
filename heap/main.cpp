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
void max_heapify(int arr[],int i,int n)
{
    int left = 2*i , right = 2*i+1 , largest ;
    if ( left <= n && arr[left] > arr[i] )
        largest = left ;
    else
        largest = i ;
    if ( right <=n && arr[right]> arr[i] && arr[right]>=arr[left] )
        largest = right ;
    if (largest != i)
    {
        swap(arr[i],arr[largest]);
        max_heapify(arr,largest,n);
    }
}
void build_maxheap()
{
    for (int i=n/2;i>0;--i)
        max_heapify(graph,i,n);
}
/*void heap_sort()
{
    int heap_size = n ;
    build_maxheap();
    for (int i=n;i>=2;--i)
    {
        swap(graph[1],graph[i]);
        heap_size--;
        max_heapify(graph,1,heap_size);
    }
}*/
int main()
{
    init();
    build_maxheap();
    //heap_sort();
    for (int i=1;i<=n;++i) cout << graph[i] << ' ' ;
    return 0;
}
