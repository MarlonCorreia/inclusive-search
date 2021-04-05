#pragma once

#include <set>
#include <string>

using namespace std;

namespace utils
{
  
    set<string> split(string phrase, string delimiter){
        set<string> words;
        size_t pos = 0;

        while ((pos = phrase.find(delimiter)) != string::npos)
        {
            string s = phrase.substr(0, pos);
            if (s != ""){
                words.insert(s);
            }
            phrase.erase(0, pos + delimiter.length());
        }
        
        words.insert(phrase);
        return words;
    }

}