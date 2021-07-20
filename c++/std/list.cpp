#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<int> list1{5, 4, 2, 1};
    auto itr = list1.begin();
    advance(itr, 2);
    list1.insert(itr, 5);
    // list1.merge(list2);
    // cout << list1.front() << endl;
    // cout << list1.back() << endl;
    // cout << list1.empty() << endl;
    // cout << list1.size() << endl;
    // cout << list1.max_size() << endl;

    // list1.clear();
    // cout
    //     << list1.max_size() << endl;
    // cout << list1.max_size() << endl;
}