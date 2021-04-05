#include <iostream>
#include <vector>
#include "trie.hpp"

Trie::Trie()
{
    this->isWord = false;

    for (int i=0; i < CHAR_SIZE; i++)
    {
        this->trieNode[i] = nullptr;
    }
}

void Trie::addWord(std::string word)
{
    Trie* cur = this;

    for(int i=0; i < word.length(); i++)
    {
        if (cur->trieNode[word[i]] == nullptr){
            cur->trieNode[word[i]] = new Trie();
        }

        cur = cur->trieNode[word[i]];
    }

    cur->isWord = true;
}

bool Trie::searchTrie(std::string word)
{
    Trie* cur = this;

    for(int i=0 ; i < word.length(); i++)
    {
        if (cur->trieNode[word[i]] == nullptr){
            return false;
        }
        cur = cur->trieNode[word[i]];
    }

    return cur->isWord;   
}

std::vector<std::string> Trie::wordsByPrefix(std::string prefix){
    Trie* cur = this;
    std::vector<std::string> words;

    for(int i=0; i< prefix.length(); i++)
    {
        if (cur->trieNode[prefix[i]] == nullptr){
            return words;
        }

        cur = cur->trieNode[prefix[i]];
    } 

    words = allWordsFromNode(cur, prefix);
    if (cur->isWord){
        words.insert(words.begin(), prefix);
    }
   
    return words;
}

std::vector<std::string> Trie::allWordsFromNode(Trie*& node, std::string prefix)
{
    std::vector<std::string> words;
    Trie* cur = node;

    for(int i=0; i < CHAR_SIZE; i++) 
    {
        if (cur->trieNode[i] != nullptr) {
            std::string curPrefix = prefix + (char)i;

            if (cur->trieNode[i]->isWord){
                words.push_back(curPrefix);
            }

            std::vector<std::string> tmp = allWordsFromNode(cur->trieNode[i], curPrefix);
            for (int o=0; o < tmp.size(); o++)
            {
                words.push_back(tmp[o]);
            }           
        }
    }

    return words;
}

std::vector<std::string> Trie::allWordsInTrie()
{
    Trie* cur = this;
    std::vector<std::string> words = allWordsFromNode(cur, "");

    return words;
}



