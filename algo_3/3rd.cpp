#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    bitset<100003> b;
    b.reset();
    int k = 0;
    for(int i=2;i<=n;i++){
        if(! b[i]){
            b[i] = true;
            for(int j=(i*i); j<=n;j+=i){
                b[j] = true;
            }
            k ++;
        }
    }
    cout<<k*(k+1)/2<<endl;
    return 0;
} 
