#include <bits/stdc++.h>
using namespace std;
int main() {
    int query;
    cin>>query;
    while(query -- ){
        string str;
        cin>>str;
        int answer=0;
        int right=0;
        int left=0;
        for(int i=0;i<str.length();i++){
            if(str[i]=='>')
                left++;
            else if(str[i]=='<')
                right++;
            if(left>right)
                break;
            else if(left==right){
                answer=max(answer,i+1);
            }
        }
        cout<<answer<<endl;
    }
    return 0;
}
