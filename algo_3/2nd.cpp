#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,temp;
    cin>>n>>m;
    priority_queue<int,vector<int>, greater<int>> pq;
    for(int i=0;i<m;i++){
        cin>>temp;
        pq.push(temp);
    }
    while(pq.size() != n){
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        pq.push(x+y);
    }
    cout<<pq.top()<<endl;
    return 0;
}
