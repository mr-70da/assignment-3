#include "StringSet.h"
StringSet::StringSet() = default;
StringSet::StringSet(const string& line) {
    stringstream ss(line);
    string word;
    while(getline(ss,word,' ')){
        modify(word);
        add(word);
    }
}

void StringSet::modify(string &line) {
    for (int i = 0; i < line.size(); ++i) {
        if ((ispunct(line[i]) || !isalnum(line[i]))) {
            line.erase(i,1);
        }
        line[i] = (char) tolower(line[i]);
    }
}

void StringSet::add(const string& word) {
    if(count(words.begin(), words.end(),word))
        cout<<"The word "<<word<<" already exists\n";
    else{ words.push_back(word); }
    sort(words.begin(),words.end());
}

void StringSet::remove(const string& word) {
    auto it = find(words.begin(), words.end(),word);
    if(it!=words.end())
        words.erase(it);
    else
        cout<<"This word does not exist\n";
}
void StringSet::clear(){
    words.clear();
}
int StringSet::size(){
    return (int)words.size();
}
void StringSet::print() {
    for_each(words.begin(),words.end(),[](string& word){
        cout<<word<<'\n';
    }
    );
}

StringSet StringSet::operator+(StringSet &b) {
    StringSet c;
    for (int i = 0; i < this->words.size(); ++i) {
        c.add(words[i]);
    }
    for (const auto & word : b.words) {
        c.add(word);
    }
    return c;
}

StringSet StringSet::operator*(StringSet &b) {
    StringSet c;
    if(this->size()>b.size()){
        for (const auto & word : b.words) {
            if(count(words.begin(), words.end(),word)){
                c.add(word);
            }
        }
    }
    else{
        for (const auto & word : words) {
            if(count(b.words.begin(), b.words.end(),word)){
                c.add(word);
            }
        }
    }
    cout<<"The Similarity between the two StringSets is: \n";
    c.print();
    cout<<"The number of intersection between them is: "<<c.size()<<'\n';
    return c;
}

double StringSet::Similarity(StringSet& q,StringSet& d) {
    StringSet c;
    c = q*d;
    return (c.size())/(sqrt(q.size())*sqrt(d.size()));
}

StringSet::StringSet(char Line[]) {
    ifstream File(Line);
    string texts;
    while(getline(File,texts)){
        stringstream ss(texts);
        string word;
        while(getline(ss,word,' ')){
            modify(word);
            add(word);
        }
    }
}
