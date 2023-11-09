#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class MedianFinder
{
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, less<int>> left;
    priority_queue<int, vector<int>, greater<int>> right;
    MedianFinder(){};

    void addNum(int num)
    {
        left.push(num);
        if (left.size() > right.size())
        {
            right.push(left.top());
            left.pop();
        }
        if (left.size() != 0 && left.top() > right.top())
        {
            right.push(left.top());
            left.push(right.top());
            left.pop();
            right.pop();
        }
    }

    double findMedian()
    {
        if (right.size() > left.size())
            return right.top();
        return (left.top() + right.top()) / 2.0;
    }
};

int main()
{

    return 0;
}