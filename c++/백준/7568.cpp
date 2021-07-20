#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> allWeightHeight;
int peopleLen, weight, height, compairWeight, compairHeight, massRank;

int main()
{
    cin >> peopleLen;
    while (peopleLen--)
    {
        cin >> weight >> height;
        allWeightHeight.push_back(make_pair(weight, height));
    }

    for (int i = 0; i < allWeightHeight.size(); i++)
    {
        massRank = 1;
        weight = allWeightHeight[i].first;
        height = allWeightHeight[i].second;
        for (int j = 0; j < allWeightHeight.size(); j++)
        {
            if (i != j)
            {
                compairWeight = allWeightHeight[j].first;
                compairHeight = allWeightHeight[j].second;
                if (weight < compairWeight && height < compairHeight)
                {
                    massRank++;
                }
            }
        }
        cout << massRank << " ";
    }
}