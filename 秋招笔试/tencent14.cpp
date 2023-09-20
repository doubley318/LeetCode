#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define M 1000000007
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        // 长度为n的01串(S1,S2,S3...)
        // 求出S1中所有长度为k的子串：s1,s2,s3,s4...
        // S1的校验和是d1=s1^s2^s3^.....
        if (n == k) {
            cout << "0" << endl;
            continue;
        }
        cout << ((1 << (n - k))) % M << endl;
    }
    return 0;
}