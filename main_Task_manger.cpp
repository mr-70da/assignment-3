#include <bits/stdc++.h>
#include "TaskList.cpp"
using namespace std;
void solve(){
    system("tasklist>com.txt");
    vector<TaskList> a;
    TaskList::get(a);
    cout<<"Image name\t"<<"\tPID"<<"     "<<"Session Name"<<"\t"<<'\t'<<"  Session# "<<"\tMem Usage\n";
    cout<<"-------------------------------------------------------------------------------\n";
    sort(a.begin(),a.end());
    for(auto &i:a){ cout << i; }
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
