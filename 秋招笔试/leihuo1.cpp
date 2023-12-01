#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string ta, tb;
    cin >> ta >> tb;
    unordered_map<string, int> mpteam;
    mpteam[ta] = 0;
    mpteam[tb] = 0;
    unordered_map<string, int> mpman;
    string MVP_name = "";
    int MVP_score = 0;
    while (n--) {
        string team, name;
        int score;
        cin >> name >> team >> score;
        mpteam[team] += score;
        mpman[name] += score;
        if (MVP_score < mpman[name]) {
            MVP_score = mpman[name];
            MVP_name = name;
        }
    }
    if (mpteam[ta] < mpteam[tb]) {
        cout << tb << endl;
    } else if (mpteam[ta] == mpteam[tb]) {
        cout << "ended in a draw" << endl;
    } else {
        cout << ta << endl;
    }
    cout << MVP_name << endl;
    return 0;
}