#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin>>str;
    int ans = 1;
    int sum = 0,l = str.length();
    for(int i=0;i<l;i++){
        sum += (str.at(i) - '0');
    }
    while(sum > 9){
        int z = sum;
        sum = 0;
        while(z > 0){
            sum += (z%10);
            z/=10;
        }
        ans ++;
    }
    cout<<ans<<endl;
    return 0;
} 
