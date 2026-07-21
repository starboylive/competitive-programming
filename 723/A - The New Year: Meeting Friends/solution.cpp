#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
 
int main() {
    int x[3];
    cin >> x[0] >> x[1] >> x[2];
 
    sort(x, x + 3);
 
    cout << abs(x[0] - x[1]) + abs(x[2] - x[1]);
 
    return 0;
}