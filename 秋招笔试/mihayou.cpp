#include <bitset>
#include <iostream>
#include <math.h>
#include <unordered_set>
#include <vector>
using namespace std;
#define M 1000000007

int main()
{
    int x = 2019;
    int count = 0;
    while (x > 0) {
        cout << bitset<8 * sizeof(int)>(x) << endl;
        x = x & (x - 1);
        count++;
    }
    cout << count << endl;
    return 0;
}