/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
using namespace std;


long long countLeapYearsUntil(long long year) {
    return year / 4 - year / 100 + year / 400;
}

int main() {
    long long A, B;
    cin >> A >> B;

    long long result = countLeapYearsUntil(B) - countLeapYearsUntil(A - 1);
    
    cout << result << endl;
    return 0;
}


