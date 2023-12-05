#include <bits/stdc++.h>
using namespace std;
void modify(string &word){
    for (int i = 0; i < word.size(); ++i) {
        if((ispunct(word[i])||!isalnum(word[i]))&&word[i]!='-'){
            word.erase(i,1);
        }
        word[i] = tolower(word[i]);
    }
}
vector<string> split(string target, char delimiter = ' '){
    vector<string>splited_text;
    string temp;
    for(int i =0  ; i<target.size();i++ ){
        if(target[i] == delimiter)
        {
            splited_text.push_back(temp);
            temp="";
        }
        else{
            temp += target[i];
        }
    }splited_text.push_back(temp);
    return splited_text;
}
void solve(){
    map<string,int>words;
    string File_name,File_words;
    cout<<"Please enter file name: \n";
    cin>>File_name;
    File_name+=".txt";
    ifstream filename(File_name);
    vector<string>texts;
    while(getline(filename,File_words)){
        texts = split(File_words);
        for (int i = 0; i < texts.size(); ++i) {
            modify(texts[i]);
            words[texts[i]]++;
        }
    }
    for(auto i:words){
        cout<<"The word "<<i.first<<" Has been repeated "<<" "<<i.second<<" times.\n";
    }
}
int main(){
    ios::sync_with_stdio(true);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
}
