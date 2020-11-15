#include <iostream>
using namespace std;
int main()
{
    int highestCount = 0;
    int count = 0;
    int highestIndex;
    bool doubleHighest = false;
    string lower = "abcdefghijklmnopqrstuvwxyz";
    string higher = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string input;
    cin >> input;
    for (int i = 0; i < lower.length(); i++)
    {

        for (int i2 = 0; i2 < input.length(); i2++)
        {

            if (input[i2] == lower[i] || input[i2] == higher[i])
            {
                count++;
            }
        }
        if (count > highestCount)
        {
            highestCount = count;

            highestIndex = i;

            doubleHighest = false;
        }
        else if (count == highestCount)
        {
            doubleHighest = true;
        }
        count = 0;
    }
    if (doubleHighest == true)
    {
        cout << "?";
    }
    else
    {
        cout << higher[highestIndex];
    }
}