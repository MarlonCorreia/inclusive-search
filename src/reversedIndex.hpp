#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

class ReversedIndex
{
private:
    /* data */
public:
    map<string, set<int>> index;

    ReversedIndex(/* args */);
    ~ReversedIndex();

    void addToindex(string, int);
    bool isIndexed(string, int);
    vector<string> queryIndex(string);

};
