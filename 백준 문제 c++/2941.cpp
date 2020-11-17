#include <iostream>
using namespace std;
int main()
{
    string croatia;
    cin >> croatia;
    int alphCount = 0;
    for (int i = 0; i < croatia.length(); i++)
    {
        string threeLetters = croatia.substr(i, 3);
        string twoLetters = croatia.substr(i, 2);
        if (threeLetters == "dz=")
        {
            alphCount++;
            i = i + 2;
        }
        else if (twoLetters == "c=" || twoLetters == "c-" || twoLetters == "d-" || twoLetters == "lj" ||
                 twoLetters == "nj" || twoLetters == "s=" || twoLetters == "z=")
        {
            alphCount++;
            i++;
        }
        else
        {
            alphCount++;
        }
    }
    cout << alphCount;
}