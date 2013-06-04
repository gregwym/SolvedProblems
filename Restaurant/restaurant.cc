#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    int tmp;
    while(b != 0) {
        tmp = b; 
        b = a % b;
        a = tmp;
    }
    return a;
}

int numOfSquare(int l, int b) {
    int lbgcd = gcd(l, b);
    return (l * b) / (lbgcd * lbgcd);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T, l, b, i, j;
    cin >> T;
    for(i = 0; i < T; i++) {
        cin >> l;
        cin >> b;
        cout << numOfSquare(l, b) << endl;
    }
    return 0;
}
