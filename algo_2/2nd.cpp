#include <bits/stdc++.h>
#define int long long

using namespace std;
int32_t main()
{
    int n;
    cin>>n;
    map<int,int> mp;
    vector<int>q1, q2, val;
    set<int> temp;
    int a,b,c;
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>a>>b>>c;
        q1.push_back(a);
        q2.push_back(b);
        val.push_back(c);
        temp.insert(a);
        temp.insert(b);
    }
    temp.insert(n);

    int ind = 1;
    for(int el: temp){
        mp[el] = ind;
        ind++;
    }
    int sz = temp.size() + 5;
    int *bit = new int[sz]{0};
    int sum = 0;
    int i = 1;
    for(int num : temp){
        int k = i;
        int upd = (num - sum);
        while(k < sz){
            bit[k] += upd;
            k += (k&(-k));
        }
        sum = num;
        i++;
    }
    for(int i=0;i<q1.size();i++){
        int k = mp[q1[i]];
        while( k < sz){
            bit[k] += val[i];
            k += (k&(-k));
        }
        k = mp[q2[i]] + 1 ;
        while( k < sz){
            bit[k] -= val[i];
            k += (k&(-k));
        }
    }
    int max = n;
    for(int i=0;i<sz;i++){
        int tem = 0;
        int k = i;
        while(k > 0){
            tem += bit[k];
            k -= (k&(-k));
        }
        if(max < tem) {
            max = tem;
        }
    }
    cout<<max<<endl;
    return 0;
}
