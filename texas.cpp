#include "mylib.h"

// 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K, A
vector<int> RANKS = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 1};
// Spade, Heart, Diamond, Club
vector<char> SUITS = {'s', 'h', 'd', 'c'};

int main()
{
    vector<pair<int, char>> hands(2);
    cout << "Please enter your hand" << endl;
    cout << "2, 3, 4, 5, 6, 7, 8, 9, 10,  J,  Q,  K, A" << endl;
    cout << "2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 1" << endl;
    cout << "Spade, Heart, Diamond, Club" << endl;
    cout << "    s,     h,       d,    c" << endl;
    int ranks;
    char suits;
    for (int i = 0; i < 2; i++)
    {
        cin >> ranks >> suits;
        hands[i].first = ranks;
        hands[i].second = suits;
    }
    int pot, in;
    cout << "Please enter the pot and the bet" << endl;
    cin >> pot >> in;

    vector<pair<int, char>> river(5);
    cout << "Please enter river card" << endl;

    // the first round
    for (int i = 0; i < 3; i++)
    {
        cin >> ranks >> suits;
        river[i].first = ranks;
        river[i].second = suits;
    }

    // Card Probability
    // 

    // Mathematical Expectation

    return 0;
}