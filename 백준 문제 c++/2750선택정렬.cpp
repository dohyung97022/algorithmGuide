#include <iostream>
using namespace std;
int main()
{
    int testCase = 0;
    cin >> testCase;
    int numArray[testCase];
    for (int i = 0; i < testCase; i++)
    {
        cin >> numArray[i];
    }
    for (int i = 0; i < testCase; i++)
    {
        int lowestIndex = i;
        for (int j = i; j < testCase; j++)
        {
            if (numArray[j] < numArray[lowestIndex])
            {
                lowestIndex = j;
            }
        }
        swap(numArray[i], numArray[lowestIndex]);
    }
    for (auto const &var : numArray)
    {
        cout << var << endl;
    }
}