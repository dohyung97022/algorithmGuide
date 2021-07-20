//1425

//
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int testCase;
    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {
        int amount, location;
        cin >> amount >> location;
        queue<int> deck;
        int sortedDeck[amount];
        for (int j = 0; j < amount; j++)
        {
            int x;
            cin >> x;
            deck.push(x);
            sortedDeck[j] = x;
        }
        sort(sortedDeck, sortedDeck + amount, greater<int>());
        int count = 1;
        for (auto const &val : sortedDeck)
        {
            while (deck.front() != val)
            {
                deck.push(deck.front());
                deck.pop();
                location--;
                if (location == -1)
                {
                    location = deck.size() - 1;
                }
            }
            if (location == 0)
            {
                cout << count << "\n";
                break;
            }
            deck.pop();
            location--;
            count++;
        }
    }
}