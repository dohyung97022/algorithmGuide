// // 1이 늘어날 때
// // 전의 숫자의 조합에서 1을 앞 뒤에 붙인다.

// // 전 전의 숫자의 조합에서 00을 앞 뒤에 붙인다.

// // 00 또는 1을 앞의 자리 숫자에만 붙이는 것 만으로 모든 경우의 수를 볼 수 있다?
// // (두가지 경우를 모두 만들어 보고 비교해보자!)
// // []          string           map
// //횟수, 0과 1의 조합의 줄, 줄의 조합(중복 없음)
// //string?
// //중복이 없게? map?

// #include <iostream>
// #include <map>
// using namespace std;

// map<string, bool> tiles[1000001];

// // return의 값이 꼭 int여야 하는가?
// // 재귀적으로 부르려면 int가 아니라 map의 값들을 돌려줘야 하는 것이 아닌가?
// map<string, bool> getTiles(int idx)
// {
//     // 해당 인덱스에서 map의 사이즈가 존재하지 않는다.
//     if (!tiles[idx].size())
//     {
//         // 인덱스가 1인가?
//         if (idx == 1)
//             tiles[idx].insert(make_pair("1", true));

//         // 인덱스가 2인가?
//         else if (idx == 2)
//         {
//             tiles[idx].insert(make_pair("11", true));
//             tiles[idx].insert(make_pair("00", true));
//         }
//         else
//         {
//             // 1칸 전의 인덱스에서 1을 앞, 뒤에 넣고
//             for (auto const &oneFrontValue : getTiles(idx - 1))
//             {
//                 tiles[idx].insert(make_pair("1" + oneFrontValue.first, true));
//                 tiles[idx].insert(make_pair(oneFrontValue.first + "1", true));
//             }
//             // 2칸 전의 인덱스에서 00을 앞 뒤에 넣는다.
//             for (auto const &oneFrontValue : getTiles(idx - 2))
//             {
//                 tiles[idx].insert(make_pair("00" + oneFrontValue.first, true));
//                 tiles[idx].insert(make_pair(oneFrontValue.first + "00", true));
//             }
//         }
//     }
//     return tiles[idx];
// }

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int wantedLen;
//     cin >> wantedLen;
//     // for (auto const &value : getTiles(wantedLen))
//     // {
//     //     cout << value.first << endl;
//     // }
//     cout << getTiles(wantedLen - 1).size() << endl;
//     cout << getTiles(wantedLen - 2).size() << endl;
//     cout << getTiles(wantedLen).size();
// }

// 위의 풀이로 피보나치를 따른다는 것을 알 수 있다.

#include <iostream>
using namespace std;

long long savedFibbo[1000001];
int wantedFibboNum;

// 메모리, 시간제한을 맞추려면 수학적 접근이 필요했다.
long long fibbo()
{
    // if (wantedNum == 1)
    //     savedFibbo[wantedNum] = 1;
    // else if (wantedNum == 2)
    //     savedFibbo[wantedNum] = 2;
    // else if (savedFibbo[wantedNum] == 0)
    //     savedFibbo[wantedNum] = (fibbo(wantedNum - 1) + fibbo(wantedNum - 2) % 15746);
    // return savedFibbo[wantedNum];

    //재귀함수는 너무 깊게 들어가면 오버플로우가 발생한다.
    savedFibbo[1] = 1;
    savedFibbo[2] = 2;
    for (int i = 3; i <= wantedFibboNum; i++)
        savedFibbo[i] = (savedFibbo[i - 1] + savedFibbo[i - 2]) % 15746;
    return savedFibbo[wantedFibboNum];
}

int main()
{
    cin >> wantedFibboNum;
    cout << fibbo();
}