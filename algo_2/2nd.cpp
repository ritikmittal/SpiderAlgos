#include <bits/stdc++.h>
using namespace std;
int main() {
    long n;
    cin>>n;
    vector<tuple<long,long,long>>query;
    set<int>s;
    long q;
    cin>>q;
    while(q--) {
        long a, b, val;
        cin >> a >> b >> val;
        query.push_back({a, b, val});
        s.insert(b);
    }
    s.insert(n);
    vector<int>points;
    for(auto x:s){
        points.push_back(x);
    }
    sort(points.begin(),points.end());
    int N=points.size();
    vector<int>value_added(N,0);
    for(auto c:query)
    {
        int l=get<0>(c);
        int r=get<1>(c);
        int val=get<2>(c);
        int lidx=lower_bound(points.begin(),points.end(),l)-points.begin();
        int ridx=upper_bound(points.begin(),points.end(),r)-points.begin();
        value_added[lidx]+=val;
        if(ridx<N)
            value_added[ridx]-=val;
    }
    for(int i=1;i<N;i++){
        value_added[i]+=value_added[i-1];
    }
    for(int i=0;i<N;i++){
        points[i]+=value_added[i];
    }
    cout<<* max_element(points.begin(),points.end())<<endl;
    return 0;
}
