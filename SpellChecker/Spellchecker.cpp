#include <algorithm>
#include <string>
#include <fstream>
#include <iostream>
#include <set>
#include <tuple>
#include <sstream>
#include <vector>

using namespace std;

void toLowerCase(string &text)
{
    std::for_each(text.begin(), text.end(), [](char & c){
        c = ::tolower(c);
    });
}

set<string> split(string s, char del = '\n')
{
    set<string> returnSet;
    string temp = "";
    for (int i = 0; i < (int) s.size(); ++i)
    {
        if (s[i] != del)
        {
            temp += s[i];
        }
        else
        {
            toLowerCase(temp);
            returnSet.insert(temp);
            temp = "";
        }
    }
    return returnSet;
}


set<string> read_all_words(string filename)
{
    ifstream data(filename, std::ios::in);
    std::stringstream sstream;
    sstream << data.rdbuf();
    
    string text = sstream.str();  
    
    return split(text);
}

set<tuple<string, string>> split_word(string word)
{
    set<tuple<string, string>> returnSet;
    for (int i = 0; i < word.length() + 1; ++i)
    {
        returnSet.insert(make_tuple(word.substr(0, i), word.substr(i, word.length())));
    }
    return returnSet;
}

vector<string> edit1(string word)
{
    char abc[] = {
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
        'w', 'x', 'y', 'z'
    };
    vector<string> mistakes;

    for (const auto& i : split_word(word))
    {
        string x = get<1>(i);
        // Letter is missing
        if (x.length() >= 1)
        {
            mistakes.push_back(get<0>(i) + x.substr(1));
        }
        else
        {
            mistakes.push_back(get<0>(i));
        }

        // 2 letters swapped
        if (x.length() >= 2)
        {
            string value;
            value = x.at(1);
            string value1;
            value1 = x.at(0);
            string temp = value + value1 + x.substr(2);
            mistakes.push_back(get<0>(i) + temp);
        }

        // Letter replaced
        if (x.length() >= 1)
        {
            for (char letter : abc)
            {
                mistakes.push_back(get<0>(i) + letter + x.substr(1));
            }
        }
        // Letter insertion
        for (char letter : abc)
        {
            mistakes.push_back(get<0>(i) + letter + x);
        }
    }
    return mistakes;
}

set<string> edit1_good(string & word, set<string> & all_words)
{
    set<string> returnSet;
    for (string mistake : edit1(word))
    {
        if (all_words.find(mistake) != all_words.end())
        {
            returnSet.insert(mistake);
        }
    }
    return returnSet;
}

template <typename T>
std::set<T> getUnion(const std::set<T>& a, const std::set<T>& b)
{
    std::set<T> result = a;
    result.insert(b.begin(), b.end());
    return result;
}

set<string> edit2_good(string & word, set<string> & all_words)
{
    set<string> returnSet;
    for (string mistake : edit1(word))
    {
        returnSet = getUnion<string>(returnSet, edit1_good(mistake, all_words));
    }

    return returnSet;
}


int main()
{
    set<string> dict = read_all_words("C:\\Users\\mabug\\german.dic");

    cout << "Eingabe: " ;
    string input;

    cin >> input;

    toLowerCase(input);

    set<string> basic_strings = edit1_good(input, dict);
    for (const string line : basic_strings)
    {
        cout << line << endl;
    }

}
