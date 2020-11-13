#include <vector>
using namespace std;
long long sum(std::vector<int> &a){
    long long ttl = 0;
    for (const int i : a){
        ttl += i;
    }
    return ttl;
}

