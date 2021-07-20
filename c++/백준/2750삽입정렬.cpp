#include <iostream>
using namespace std;
int main()
{
    int caseNumber = 0;
    cin >> caseNumber;
    int numArray[caseNumber];
    for (int i = 0; i < caseNumber; i++)
    {
        cin >> numArray[i];
    }
    for (int i = 0; i < caseNumber; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (numArray[j] < numArray[j - 1])
            {
                swap(numArray[j], numArray[j - 1]);
            }
        }
    }
    for (auto const &val : numArray)
    {
        cout << val << endl;
    }
}