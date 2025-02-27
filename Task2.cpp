#include <bits/stdc++.h>
using namespace std;

bool ratio_cmp(const pair<int, int> &a, const pair<int, int> &b) {
    return (double)a.first / a.second < (double)b.first / b.second;
}

int main()
{
    int n,k;cin>>n>>k;
    vector<pair<int,int>>v(n);
    for (int i = 0; i < n; i++)
    {
        int price,weight;cin>>price>>weight;
        v[i]={price,weight};
    }
    sort(v.rbegin(),v.rend(),ratio_cmp);
    double ans=0;
    for (int i = 0; i < n; i++)
    {
        // cout<<v[i].first<<" "<<v[i].second<<endl;
        if(k>v[i].second) {
            ans+=v[i].first;
            k-=v[i].second;
        }
        else{
            ans+=((double)v[i].first / v[i].second) * k;
            k=0;
        }
    }
    cout<<ans<<endl;

    
    return 0;
} 