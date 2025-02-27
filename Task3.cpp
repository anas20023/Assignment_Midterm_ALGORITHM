#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin>>n;
    vector<pair<int,int>>a(n);
    for (int i = 0; i < n; i++)
    {
        int st,ed;cin>>st>>ed;
        a[i]={st,ed};
    }
    sort(a.begin(),a.end(),[&](const pair<int,int>a,const pair<int,int>b){
        return a.second<b.second;
    });
    vector<pair<int,int>>ans;
    int prev=a[0].second;
    ans.push_back({a[0].first,a[0].second});
    for (int i = 1; i < n; i++)
    {
        //cout<<a[i].first<<" "<<a[i].second<<endl;
        if(a[i].first>prev){
            ans.push_back({a[i].first,a[i].second});
            prev=a[i].second;
        }
    }
    for(auto i:ans){
        cout<<i.first<<" "<<i.second<<endl;
    }
    
    
    return 0;
}