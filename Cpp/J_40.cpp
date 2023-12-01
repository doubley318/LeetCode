#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> getLeastNumbers(vector<int> &arr, int k)
    {
        int l = 0, r = arr.size() - 1;
        int i = l, j = r;
        while (i != k)
        {
            i = l, j = r;
            while (i < j)
            {
                while (i < j && arr[i] <= arr[j])
                    j--;
                swap(arr[i], arr[j]);
                while (i < j && arr[i] <= arr[j])
                    i++;
                swap(arr[i], arr[j]);
            }
            if (i < k)
            {
                l = i + 1;
            }
            else if (i > k)
            {
                r = i - 1;
            }
        }
        return vector<int>(arr.begin(), arr.begin() + k);
    }
};

int main()
{
    vector<int> nums = {0, 1, 1, 2, 4, 4, 1, 3, 3, 2};
    Solution so;
    vector<int> res = so.getLeastNumbers(nums, 6);
    return 0;
}