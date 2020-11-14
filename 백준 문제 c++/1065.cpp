//N을 for loop으로 돈다. (1~N까지, N포함)
//d(n)에서 n이 한수인지 알아주는 func
//vector<int>에서 각 자리의 수를 저장한다.
//for loop을 vector에서 돌면서 각 자리의 수가 등차를 이루는지 확인
//전부 등차를 이룬다면 한수, true를 리턴
//true 라면 ncount를 ++하여 한수의 갯수를 count한다.

#include <iostream>
#include <vector>
using namespace std;
bool isHanSoo(int n)
{
    vector<int> indexPlacedSingleDigets;
    int i = 0;
    do
    {
        indexPlacedSingleDigets.push_back(n % 10);
        i++;
    } while ((n /= 10) != 0);
    if (i <= 1)
        return true;
    // 1212 len 4
    //2 1 2 1
    //0 1 2 3
    int dngCha = indexPlacedSingleDigets[0] - indexPlacedSingleDigets[1];
    for (int i = 1; i < indexPlacedSingleDigets.size(); i++)
    {
        if (dngCha != indexPlacedSingleDigets[i - 1] - indexPlacedSingleDigets[i])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int N, hanSooCount = 0;
    cin >> N;
    for (int n = 1; n <= N; n++)
    {
        if (isHanSoo(n) == true)
        {
            hanSooCount++;
        }
    }
    cout << hanSooCount;
}
