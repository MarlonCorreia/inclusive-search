#include <iostream>
#include "src/trie.hpp"
#include <fstream>

#define LOG(x) std::cout << x << std::endl

int main()
{
    Trie* root = new Trie();

    std::fstream MyFile("words/words.txt");
    std::string word;
    
    while (std::getline(MyFile, word))
    {   
        root->addWord(word);
        //LOG(word);
    }
    
    while (true)
    {   
        std::string input;
        std::cin >> input;
        
        std::vector<std::string> words = root->wordsByPrefix(input);

        for (int i=0; i< words.size(); i++)
        {
        std::cout << i+1 << " -> " << words[i] << std::endl;
        }
        
    }
    
    
    delete root;

    return 0;

}