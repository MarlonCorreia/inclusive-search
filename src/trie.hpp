#include <vector>

using namespace std;

#define CHAR_SIZE 128

class Trie
{
public:
    bool isWord;
    Trie* trieNode[CHAR_SIZE];

    Trie(/* args */);
    ~Trie();

    void addWord(string);
    bool searchTrie(string);
    vector<string> wordsByPrefix(string);
    vector<string> allWordsInTrie();

private:
    vector<string> allWordsFromNode(Trie*&, string);
};