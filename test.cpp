#include "mylib.h"
int main()
{
    string s = "sdhiaj";
    if (s.find_first_of("k") == string::npos)
        cout << "nofind" << endl;
    return 0;
}