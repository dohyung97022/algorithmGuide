#include <bits/stdc++.h>
using namespace std;

void printFloatVector(vector<float> &fv)
{
    for (auto const &val : fv)
    {
        cout << val << "; ";
    }
    cout << endl;
}

int main()
{
    vector<float> heapVec1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    make_heap(heapVec1.begin(), heapVec1.end());
    printFloatVector(heapVec1);
    heapVec1.push_back(8.88);
    push_heap(heapVec1.begin(), heapVec1.end());
    printFloatVector(heapVec1);
    pop_heap(heapVec1.begin(), heapVec1.end());
    heapVec1.pop_back();
    printFloatVector(heapVec1);
}

// make_heap
// push_heap
// pop_heap