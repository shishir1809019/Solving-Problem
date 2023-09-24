#include<bits/stdc++.h>
using namespace std;

#define ll long long

bool isValid(ll dis, vector<int> &v, int cows){
    int lastPos = v[0];
    int cnt = 1;

    for(int i = 1; i<v.size(); i++){
        int pos = v[i];
        if(pos-lastPos < dis) continue;

        cnt++;
        lastPos = pos;
    }
    return cnt >= cows;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, c; cin>>n>>c;
        vector<int> v(n);

        for(int i = 0; i<n; i++) cin>>v[i];
        sort(v.begin(), v.end());

        ll ans = -1, low = 1, high = v.back(); // ans = highest x that is valid

        while(high>=low)
        {
            ll mid = (low+high)/2;
            if(isValid(mid, v, c)){
                ans = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        // ans!=-1?ans=n-ans+1:0;
        cout<<ans<<endl;
    }
    return 0;
}