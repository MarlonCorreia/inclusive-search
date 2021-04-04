#include <iostream>
#include <vector>
#include "reversedIndex.hpp"
#include "utils/utils.hpp"

using namespace std;

void ReversedIndex::addToindex(std::string phrase, int id)
{
    vector<string> words = split(phrase, " ");
    
    for(int i=0; i < words.size(); i++)
    {
        //implementation
    }
}   