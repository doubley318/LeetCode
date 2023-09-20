#include <iostream>
using namespace std;

int main()
{
    int HourNow, MinNow, SecNow;
    int HourClock, MinClock, SecClock;
    cin >> HourNow >> MinNow >> SecNow;
    cin >> HourClock >> MinClock >> SecClock;
    int HourDist, MinDist, SecDist;
    SecClock = SecClock + 60 - SecNow;
    MinClock = MinClock + 59 - MinNow;
    HourClock = HourClock + 23 - HourNow;
    if (SecClock >= 60) {
        MinClock += 1;
        SecClock = SecClock - 60;
    }
    if (MinClock >= 60) {
        HourClock += 1;
        MinClock = MinClock - 60;
    }
    if (HourClock >= 24) {
        HourClock -= 24;
    }
    cout << HourClock << ":" << MinClock << ":" << SecClock << endl;
    return 0;
}