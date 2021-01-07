#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

vector<tuple<int, int, string>> users;

bool userSort(tuple<int, int, string> &userA, tuple<int, int, string> &userB)
{
    if (get<1>(userA) != get<1>(userB))
        return get<1>(userA) < get<1>(userB);

    else
        return get<0>(userA) < get<0>(userB);
}

int main()
{
    int userLen, age;
    string name;
    cin >> userLen;
    for (int i = 0; i < userLen; i++)
    {
        cin >> age >> name;
        users.push_back(make_tuple(i, age, name));
    }
    sort(users.begin(), users.end(), userSort);
    for (auto const &val : users)
    {
        cout << get<1>(val) << " " << get<2>(val) << "\n";
    }
}

// tuple을 가져오는것 반드시 기억하자
// get<0>(tup1);
// get<1>(tup1);
// get<2>(tup1);