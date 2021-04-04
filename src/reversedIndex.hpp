#include <string>
#include <vector>
#include <map>

using namespace std;

class ReversedIndex
{
private:
    /* data */
public:
    map<int, vector<string>> index;

    ReversedIndex(/* args */);
    ~ReversedIndex();

    void addToindex(string, int);
    bool isIndexed(string, int);
    vector<string> queryIndex(string);

};
