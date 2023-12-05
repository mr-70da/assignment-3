#ifndef UNTITLED1_STRINGSET_H
#define UNTITLED1_STRINGSET_H
#include <bits/stdc++.h>
using namespace std;
class StringSet {
private:
    vector<string>words;
    string File_name;
public:
    StringSet();
    explicit StringSet(const string& line);
    explicit StringSet(char Line[]);
    static void modify(string& line);
    void add(const string& word);
    void remove(const string& word);
    void clear();
    int size();
    void print();
    StringSet operator+(StringSet& b);
    StringSet operator*(StringSet& b);
    static double Similarity(StringSet& a,StringSet& b);
};
#endif //UNTITLED1_STRINGSET_H
