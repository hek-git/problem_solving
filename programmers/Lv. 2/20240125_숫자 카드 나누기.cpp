#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    if (b > a)
        return gcd(b, a);
    else
        return gcd(b, a % b);
}

int validate(vector<int>& array, int n) {
    for (int i = 0; i < array.size(); i++) {
        if (array[i] % n == 0) return 0;
    }
    return n;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int gcd_a, gcd_b;
    gcd_a = arrayA[0];
    gcd_b = arrayB[0];
    for (int i = 1; i < arrayA.size(); i++) gcd_a = gcd(gcd_a, arrayA[i]);
    for (int i = 1; i < arrayB.size(); i++) gcd_b = gcd(gcd_b, arrayB[i]);
    // cout << gcd_a << " " << gcd_b;
    return max(validate(arrayA, gcd_b), validate(arrayB, gcd_a));
}