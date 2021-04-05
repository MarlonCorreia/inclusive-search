#include <iostream>
#include <vector>
#include <algorithm>
#include "reversedIndex.hpp"
#include "../utils/utils.hpp"

using namespace std;

ReversedIndex::ReversedIndex()
{

}

ReversedIndex::~ReversedIndex()
{

}

void ReversedIndex::addToindex(std::string phrase, int id)
{
    set<string> words = utils::split(phrase, " ");
    
    for(set<string>::iterator it = words.begin(); it != words.end(); it++)
    {
        auto ids = this->index[*it];
        ids.insert(id);
        this->index[*it] = ids;
    }
}  

bool ReversedIndex::isIndexed(string word, int id)
{   
    set<int> ids = this->index[word];

    return ids.find(id) != ids.end();
}

set<int> ReversedIndex::queryIndex(string query)
{   
    set<string> words = utils::split(query, " ");
    set<int> w;
    vector<int> tmp;

    for(set<string>::iterator it = words.begin(); it != words.end(); it++)
    {
        set<int> idsByword = this->index[*it];

        for(set<int>::iterator it2 = idsByword.begin(); it2 != idsByword.end(); it2++)
        {
            tmp.push_back(*it2);
        }
    }

    for (int i=0; i< tmp.size(); i++)
    {
        if (count(tmp.begin(), tmp.end(), tmp[i]) == words.size()){
            w.insert(tmp[i]);
        }
    }

    return w;
}