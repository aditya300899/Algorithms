#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
ll mod  = 1e9+7;
int blocksize;
int sum = 0;
struct query
{
    int l, r;
    query(int l, int r){
        this->l = l; this->r = r;
    }
    bool operator< (query other){
        return make_pair(l/blocksize, r) < make_pair(other.l/blocksize, other.r);
    };
};
void add(int x){
    sum += x;
}
void remove(int x){
    sum -= x;
}
int get_answer(){
    return sum;
}
void MosAlgo(){
    // executing sum in a range for l to r
    int n; 
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    cin>>v[i];
    int q;
    cin>>q;
    vector<query> vq;
    for(int i = 0; i < q; i++){
        int templ, tempr;
        cin>>templ>>tempr;
        templ--; tempr--;
        vq.push_back(query(templ, tempr));
    }
    blocksize = (int) ((int) sqrt(n)* (int) sqrt(n)==n)? (int) sqrt(n): (int) sqrt(n)+1;
    assert(blocksize!=0);
    sort(vq.begin(), vq.end());
    int curl = 0, curr = -1;
    for (int i = 0; i < q; i++)
    {
        int left = vq[i].l, right = vq[i].r;
        while(curr < right){
            curr++;
            add(v[curr]);
        }
        while(curr > right){
            remove(v[curr]);
            curr--;
        }
        while(curl < left){
            remove(v[curl]);
            curl++;
        }
        while(curl > left){
            curl--;
            add(v[curl]);
        }
        cout<<get_answer()<<endl;
    }
}
void sqrt_decomposition(){
    int n;
    cin>>n;
    vector<int> v(n);   
    for(int i = 0; i < n; i++)
        cin>>v[i];
    int block_size = ((int) sqrt(n) * (int) sqrt(n) == n)?(int) sqrt(n): sqrt(n)+1;
    int blocks = (n+block_size-1)/block_size;
    vector<int> blocksum(blocks, 0);
    int temp = 0;
    for(int i = 0; i < n; i++)
    blocksum[i/block_size] += v[i];
    int q;
    cin>>q;
    vector<int> ansq;
    while(q--){//now for queries
        int l, r;
        cin>>l>>r; // considering 1 based indexing in the question
        l--; r--;
        int ans = 0;
        int lblock = l/block_size, rblock = r/block_size;
        if(lblock == rblock){
            // when both are in the same block
            for(int i = l; i <= r; i++)
            ans+=v[i];
        }else
        {
            for(int i = l; i < (1+lblock)*block_size; i++)
            ans+=v[i];
            for(int i = lblock+1; i < rblock; i++)
            ans+=blocksum[i];
            for(int i = (rblock)*block_size; i <= r; i++)
            ans+=v[i];
        }
        ansq.push_back(ans);
    }
    for(int x:ansq){
        cout<<x<<"\n";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    // finding the sum of elements in the range [l,r] inclusive of l and r
    // sqrt_decomposition();
    MosAlgo();
    return 0;
}   
/*
11
2 1 3 5 4 2 1 6 9 3 4
3
2 10
4 5
1 2
*/