#include <iostream>
#include <fstream>
#include <vector>

#define C_SIZE 128

class Trie
{

public:
    bool isWord;
    std::string full_word;
    Trie* trieNode[C_SIZE];

    Trie()
    {
        this->isWord = false;

        for (int i=0; i < C_SIZE; i++){
            this->trieNode[i] = nullptr;
        }
    }

    void addWord(std::string);
    std::string searchTrie(std::string);
    std::vector<std::string> wordsByPrefix(std::string);
    std::vector<std::string> allWordsInTrie();

private:
    std::vector<std::string> allWordsFromNode(Trie*&);
};

void Trie::addWord(std::string word)
{
    Trie* cur = this;

    for(int i=0; i < word.length(); i++){
        if (cur->trieNode[word[i]] == nullptr){
            cur->trieNode[word[i]] = new Trie();
        }

        cur = cur->trieNode[word[i]];
    }

    cur->isWord = true;
    cur->full_word = word;
}

std::string Trie::searchTrie(std::string word)
{
    Trie* cur = this;

    for(std::string::iterator letter= word.begin(); letter != word.end(); letter++){
        if (cur->trieNode[*letter] == nullptr){
            return "Not Found";
        }

        cur = cur->trieNode[*letter];
    }
    return cur->full_word;
}

std::vector<std::string> Trie::wordsByPrefix(std::string prefix){
    Trie* cur = this;
    std::vector<std::string> words;

    for(int i=0; i< prefix.length(); i++){
        if (cur->trieNode[prefix[i]] == nullptr){
            return words;
        }

        cur = cur->trieNode[prefix[i]];
    } 

    words = allWordsFromNode(cur);
    if (cur->isWord){
        words.push_back(cur->full_word);
    }
   
    return words;
}

std::vector<std::string> Trie::allWordsFromNode(Trie*& node)
{
    std::vector<std::string> words;
    Trie* cur = node;

    for(int i=0; i < C_SIZE; i++) {
        if (cur->trieNode[i] != nullptr) {
            if (cur->trieNode[i]->isWord){
                words.push_back(cur->trieNode[i]->full_word);
            }

            std::vector<std::string> tmp = allWordsFromNode(cur->trieNode[i]);
            for (int o=0; o < tmp.size(); o++){
                words.push_back(tmp[o]);
            }           
        }
    }

    return words;
}

std::vector<std::string> Trie::allWordsInTrie()
{
    Trie* cur = this;
    std::vector<std::string> words = allWordsFromNode(cur);

    return words;
}

int main()
{
    
    Trie* root = new Trie();

    std::fstream MyFile("words/words.txt");
    std::string word;

    while (std::getline(MyFile, word)){
        root->addWord(word);
    }
    
    while (true)
    {   
        std::string input;
        std::cin >> input;
        
        std::vector<std::string> words = root->wordsByPrefix(input);

        for (int i=0; i< words.size(); i++)
        {
            std::cout << words[i] << std::endl;
        }
        
    }
    
    
    free(root);

    return 0;

}



