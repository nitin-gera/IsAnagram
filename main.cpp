#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool IsAnagram1(const string &s, const string &t)
{
    if(s.length() != t.length())
        return false;

    if(s == "" and t == "")
        return true;

    size_t n = s.length();
    vector<bool> matched(n, false);

    for(size_t i(0); i < n; i++)
    {
        for(size_t j(0); j < n; j++)
        {
            if((s[i] == t[j]) && (matched[j] == false))
            {
                matched[j] = true;
                break;
            }
        }
    }

    for(bool flag : matched)
    {
        if(flag == false)
            return false;
    }

    return true;
}

bool IsAnagram2(string &s, string &t)
{
    if(s.length() != t.length())
        return false;

    if(s == "" and t == "")
        return true;

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    return (s==t);
}

bool IsAnagram3(const string &s, const string &t)
{
    if(s.length() != t.length())
        return false;

    if(s == "" and t == "")
        return true;

    unordered_map<char, int>    count;
    size_t n = s.length();

    for(size_t i(0); i < n; i++)
    {
        count[s[i]]++;
    }

    for(size_t i(0); i < n; i++)
    {
        count[t[i]]--;
    }

    for(auto value : count)
    {
        if(value.second != 0)
            return false;
    }

    return true;
}

bool IsAnagram4(const string &s, const string &t)
{
    if(s.length() != t.length())
        return false;

    if(s == "" and t == "")
        return true;

    vector<int> count(128, 0);

    size_t n = s.length();

    for(size_t i(0); i < n; i++)
    {
        count[s[i]]++;
    }

    for(size_t i(0); i < n; i++)
    {
        count[t[i]]--;
    }

    for(const auto ctr : count)
    {
        if(ctr != 0)
            return false;
    }
    return true;
}

int main()
{
    string s = "anagram";
    string t = "nagaram";

    cout << "string 1:" << s << endl;
    cout << "string 2:" << t << endl;

    if(IsAnagram1(s, t))
    {
        cout << "IsAnagram1::Strings are Anagrams" << endl;
    }
    else
    {
        cout << "IsAnagram1::Strings are NOT Anagrams" << endl;
    }

    if(IsAnagram2(s, t))
    {
        cout << "IsAnagram2::Strings are Anagrams" << endl;
    }
    else
    {
        cout << "IsAnagram2::Strings are NOT Anagrams" << endl;
    }

    if(IsAnagram3(s, t))
    {
        cout << "IsAnagram3::Strings are Anagrams" << endl;
    }
    else
    {
        cout << "IsAnagram3::Strings are NOT Anagrams" << endl;
    }

    if(IsAnagram4(s, t))
    {
        cout << "IsAnagram4::Strings are Anagrams" << endl;
    }
    else
    {
        cout << "IsAnagram4::Strings are NOT Anagrams" << endl;
    }
}
