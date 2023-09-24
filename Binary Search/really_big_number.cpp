#include<bits/stdc++.h>
using namespace std;

#define ll long long

int getSOD(ll x){
    int sumOfDigit = 0;
    while(x){
        int lastDigit = x%10;
        sumOfDigit += lastDigit;
        x/=10;
    }
    return sumOfDigit;
}

bool isValid(ll x, ll s){
    int sodx = getSOD(x);
    return (x-sodx) >= s;
}

int main()
{
    ll n, s;
    cin>>n>>s;
    ll ans = -1, low = 0, high = n;

    while(high>=low)
    {
        ll mid = (low+high)/2;
        if(isValid(mid, s)){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
   (ans!=-1)? ans = n-ans+1 : ans = 0;
   cout<<ans<<endl;
}