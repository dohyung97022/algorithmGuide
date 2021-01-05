// 내 풀이...
// //내림차순으로 정리한다.
// //중앙값, 범위는 내림차순을 활용
// //최빈값은 수들이 연속적으로 나타나는 정도를 저장하여
// //전의 빈도와 비교를 하며
// //더 큰 값을 최빈값으로 저장한다.

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <cstring>
// using namespace std;
// int main()
// {
//     int NumLen;
//     cin >> NumLen;
//     vector<int> NumVec;
//     for (int i = 0; i < NumLen; i++)
//     {
//         int input;
//         cin >> input;
//         NumVec.push_back(input);
//     }
//     sort(NumVec.begin(), NumVec.end(), less<int>());

//     vector<int> mostShown;
//     int mostShownCount = 0;

//     int checking = NumVec[0];
//     int shownCount = 0;
//     for (int i = 0; i < NumVec.size(); i++)
//     {

//         if (NumVec[i] == checking && i < NumVec.size())
//             shownCount++;
//         else
//         {
//             if (shownCount > mostShownCount)
//             {
//                 mostShownCount = shownCount;
//                 mostShown.clear();
//                 mostShown.push_back(checking);
//                 cout << "A mostShown.size() " << mostShown.size() << endl;
//             }
//             else if (shownCount == mostShownCount)
//             {
//                 mostShown.push_back(checking);
//                 cout << "B mostShown.size() " << mostShown.size() << endl;
//             }
//             checking = NumVec[i];
//             shownCount = 1;
//         }
//         cout << "checking " << checking << endl;
//         cout << "shownCount " << shownCount << endl;
//         cout << "mostShownCount " << mostShownCount << endl;
//     }
//     cout << "mostShown.size() " << mostShown.size() << endl;
//     if (mostShown.size() > 1)
//         cout
//             << mostShown[1];
//     else
//         cout << mostShown[0];
// }

// 기억할 점
// //vector는 clear가 존재한다.
// greater의 반대는 lesser가 아니라 less 이다.?!?
// sort는 algorithm(s)에 있다.

// 50분 경과, 실패...

// 남의 풀이....
// 아래 사람에게서 배울 점
// count를 vector에 넣는 것은 죄가 아니다.
// 범위가 4000같이 주어지면 고려해보자.
// 오히려 for loop을 돌면서 전 값과 비교하는 것이 더 복잡하게 만들었다.
// 이 사람은 물음표 연산자를 잘 활용하는 것 같다.

// temp = i <= 0 ? abs(i) : i + 4000; 의 해석
// -4000 에서 4000까지 돌면서
// 0보다 작거나 같으면 -의 값을 +로 바꾸고
// 0보다 크면 4000까지의 값을 더해서
// 0부터 8000까지의 범위를 돈다.

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, temp, mean, mode = 0, min, max = 0;
    bool isSecond = false;
    cin >> N;
    vector<int> vec(N);
    vector<int> vec2(8001, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> vec[i];
        mean += vec[i];
        temp = (vec[i] <= 0) ? abs(vec[i]) : vec[i] + 4000;
        vec2[temp]++;
        if (vec2[temp] > max)
            max = vec2[temp];
    }
    sort(vec.begin(), vec.end());

    for (int i = -4000; i < 4001; i++)
    {
        temp = i <= 0 ? abs(i) : i + 4000;
        if (vec2[temp] == max)
        {
            mode = i;
            if (isSecond)
                break;
            isSecond = true;
        }
    }

    cout << round(mean / (double)N) << '\n';
    cout << vec[round(N / 2)] << '\n';
    cout << mode << '\n';
    min = vec[0];
    max = vec[vec.size() - 1];
    cout << max - min << '\n';
}

// 또 다른 사람의 풀이...
// 이사람은 pair로 빈도수를 아예 저장하였다.

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>

using namespace std;

//sort 기준
bool comp(const pair<int, int> &p1, const pair<int, int> &p2)
{

    if (p1.second == p2.second)
    {                               //빈도수가 같으면
        return p1.first < p2.first; //숫자(key)작은게 앞으로
    }
    return p1.second > p2.second; //다르면 빈도수가 큰게 앞으로
}

int main(void)
{
    //입력 1
    int n;
    cin >> n;

    vector<int> v;
    int key;
    double sum = 0; //산술평균용

    //입력 2
    for (int i = 0; i < n; i++)
    {
        cin >> key;
        v.push_back(key);

        sum += key;
    }

    //오름차순으로 정렬.
    sort(v.begin(), v.end());

    //산술평균 출력.
    //내림함수를 이용하여 반올림.
    cout << (int)floor((sum / n) + 0.5) << endl;

    //중앙값.
    cout << v[n / 2] << endl;

    //최빈값.
    vector<pair<int, int>> st; //key 와 빈도수를 저장할 pair형 vector.
    vector<int>::size_type i;

    for (i = 0; i < v.size(); i++)
    {
        if (st.empty())
        {
            st.push_back(pair<int, int>(v[i], 1));
            continue;
        }

        if (st.back().first == v[i])
        { //같은게 있다면

            pair<int, int> tmp = st.back();
            tmp.second++;      //하나 증가
            st.pop_back();     //기존것 없애고
            st.push_back(tmp); //새로운 것 다시 삽입
        }
        else
        {
            st.push_back(pair<int, int>(v[i], 1));
        }
    }

    //빈도수가 높고, 숫자(key)가 낮은 순으로 정렬
    sort(st.begin(), st.end(), comp);

    if (st[0].second == st[1].second)
    {
        cout << st[1].first << endl;
    }
    else
    {
        cout << st[0].first << endl;
    }

    //범위.
    cout << v.back() - v.front() << endl;

    return 0;
}