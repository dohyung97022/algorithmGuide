//모든 경우의 수를 센다
//vector에 모든 수를 저장한다.
//vector에서 for loop를 돌면서 특정한 수들의 조합을 생각한다.
//뽑은 카드는 vector에서 뺀다.
//수들의 조합 중 M을 넘어가면 그 숫자를 저장하고
//넘어가지 않으면 뽑고 for loop를 계속 돈다.

//뺀 vector를 저장하는 식으로 한다.

// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;
// // queue<pair<조합하고 남은 덱, 뽑은 카드의 총합>>
// queue<pair<vector<int>, int>> deckSumQue;
// int wantedSum, cardCount, foundClosest;

// int brute()
// {
//     while (deckSumQue.size())
//     {
//         vector<int> deck = deckSumQue.front().first;
//         int sum = deckSumQue.front().second;
//         deckSumQue.pop();

//         for (int i = 0; i < deck.size(); i++)
//         {
//             int card = deck[i];
//             deck.erase(deck.begin() + i);
//             int added = card + sum;
//             //wantedSum보다 처음으로 합이 커지거나 넘어가고 foundClosest 보다 가까우면
//             if (wantedSum <= added && abs(wantedSum - foundClosest) > abs(wantedSum - added))
//             {
//                 foundClosest = added;
//             }
//             // 마지막 카드이며 더 남은 카드가 없다면
//             else if (!deck.size() && abs(wantedSum - foundClosest) > abs(wantedSum - added))
//             {
//                 foundClosest = added;
//             }
//             else
//             {
//                 deckSumQue.push(make_pair(deck, added));
//                 deck.insert(deck.begin() + i, card);
//             }
//         }
//     }
// }

// int main()
// {
//     int card;
//     vector<int> deck;
//     cin >> cardCount >> wantedSum;
//     for (int i = 0; i < cardCount; i++)
//     {
//         cin >> card;
//         deck.push_back(card);
//     }
//     deckSumQue.push(make_pair(deck, 0));
//     brute();
//     cout << foundClosest;
// }

//내가 한 풀이의 문제.
//간결하지가 않다.
//단순하게 생각하자.
//문제 좀 제대로 읽자.
//P의 문제는 for loop을 돈다.

//참고한 풀이
#include <iostream>
using namespace std;
const int MAX_DECK_SIZE = 101;
int cardsArray[MAX_DECK_SIZE];
int main()
{
    int deckSize, target, sum, closest = 0;
    cin >> deckSize >> target;
    for (int i = 0; i < deckSize; i++)
        cin >> cardsArray[i];

    for (int i = 0; i < deckSize - 2; i++)
    {
        for (int j = i + 1; j < deckSize - 1; j++)
        {
            for (int k = j + 1; k < deckSize; k++)
            {
                sum = cardsArray[i] + cardsArray[j] + cardsArray[k];
                if (sum <= target && target - sum < target - closest)
                {
                    closest = sum;
                }
            }
        }
    }
    cout << closest;
}