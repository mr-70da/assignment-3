#include "StringSet.cpp"
using namespace std;
void solve(){
    cout<<"Please enter the first string or a file name: \n";
    string s1;
    char s2[100];
    getline(cin,s1);
    cout<<"Please enter the second string or a file name: \n";
    cin.getline(s2,100);
    StringSet a(s1),b(s2),c;
    a.add("hi");
    a.remove("ice");
    a.print();
    c = a+b;
    c.print();
    c.clear();
    c = a*b;
    c.print();
    cout<<StringSet::Similarity(a,b)<<'\n';
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
