#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll binaryExponentiation(ll a, ll b){
    ll res = 1;
    while(b!=0){
        if(b&1)
        res = res*a;
        a *= a;
        b >>= 1;
    }
    return res;
}
ll binaryExponentiationWithMod(ll a, ll b, ll m){
    ll res = 1;
    while(b != 0){
        if(b&1)
        res = res * a%m;
        a = a * a%m;
        b >>= 1;
    }
    return res;
}
int main(){
    cout<<binaryExponentiation(6, 10)<<endl;
    cout<<binaryExponentiationWithMod(6, 10, 5);
    return 0;
}