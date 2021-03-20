#include <iostream>
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
    void wordsByPrefix(std::string);
    void allWordsInTrie();

private:
    void allWordsFromNode(Trie*&);
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

void Trie::wordsByPrefix(std::string prefix){
    Trie* cur = this;
    std::vector<std::string> words;

    for(int i=0; i< prefix.length(); i++){
        if (cur->trieNode[prefix[i]] == nullptr){
            //return words;
            break;
        }

        cur = cur->trieNode[prefix[i]];
    } 

    if(cur->isWord){
        std::cout << cur->full_word << std::endl;
    }
   
    allWordsFromNode(cur);
   
    //return words;
}

void Trie::allWordsFromNode(Trie*& node)
{
    std::vector<std::string> words;
    Trie* cur = node;

    for(int i=0; i < C_SIZE; i++) {
        if (cur->trieNode[i] != nullptr) {
            if (cur->trieNode[i]->isWord){
                std::cout << cur->trieNode[i]->full_word << std::endl;
            }

            allWordsFromNode(cur->trieNode[i]);
           
        }
    }

    //return words;
}

void Trie::allWordsInTrie()
{
    Trie* cur = this;
    allWordsFromNode(cur);
}

int main()
{
    
    Trie* root = new Trie();

    root->addWord("Marlon");
    root->addWord("Mare");
    root->addWord("Maremoto");
    root->addWord("Marrom");
    root->addWord("Marreco");
    root->addWord("Marcelo");
    root->addWord("Murro");
    root->addWord("Morte");
    root->addWord("Morro");
    root->addWord("Mouro");
    root->addWord("Batom");
    root->addWord("Batima");
    root->addWord("bike");
    root->addWord("bicicleta");
    root->addWord("Horta");
    root->addWord("omg");

    root->allWordsInTrie();
    
    free(root);

    return 0;

}



