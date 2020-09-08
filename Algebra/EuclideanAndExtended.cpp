#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
    while(b!=0){
        a = a%b;
        int c = a; // swapping a & b
        a = b;
        b = c;
    }
    return a;
}

int extendedEuclidean(int a, int b, int *x, int *y){
    if(b == 0){
        *x = 1;
        *y = 0;
        return a;
    }
    int x1, y1;
    int d = extendedEuclidean(b, a%b, &x1, &y1);
    *x = y1;
    *y = x1 - y1*(a/b);
    return d;
}
int main(){
    // a should be the larger of two numbers
    cout<<gcd(100, 20);
    int x, y;
    int d = extendedEuclidean(100, 20, &x, &y);
    cout<<d<<" "<<x<<" "<<y<<" ";
    //time complexity is log(min(a, b))

}