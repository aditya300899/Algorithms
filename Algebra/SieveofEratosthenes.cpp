#include<bits/stdc++.h>
using namespace std;
void sieve(int n){
    vector<int> p(n+1, 1);
    p[0] = 0;
    p[1] = 0;
    for(int i = 2; i*i <= n; i++){
        if(p[i] == 1){
            for(int j = i*2; j <= n; j+=i){
                p[j] = 0;
            }
        }
    }
    for(int i = 0; i <= n; i++){
        if(p[i])
        cout<<i<<" ";
    }
}
//when size of n is of the order of 1e7
void sieveWithLinearTime(int n){
    vector<int> pr;
    vector<int> lp(n+1, 0);
    for(int i = 2; i <= n; i++){
        if(lp[i] == 0){
            lp[i] = i;
            pr.push_back(i);
        }
        for(int j = 0; j < pr.size() && i*pr[j] <=n && pr[j]<=lp[i]; j++){
            lp[i*pr[j]] = pr[j];
        }
    }
    for(auto x:pr)
    cout<<x<<" ";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    //find prime factors till n
    int n;
    cin>>n;
    // sieve(n);
    sieveWithLinearTime(n);
    return 0;
}