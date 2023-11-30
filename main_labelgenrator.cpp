#include "FileLabelGenerator.cpp"
using namespace std;
void solve(){
    LabelGenerator figureNumbers("Figure ",1);
    LabelGenerator pointNumbers("P",0);
    cout<<"Figure numbers: ";
    for (int i = 0; i < 3; ++i) {
        cout<<figureNumbers.nextLabel()<<(i<=1? ", ":"");
    }
    cout<<"\nPoint numbers: ";
    for (int i = 0; i < 5; ++i) {
        cout<<pointNumbers.nextLabel()<<(i<=3? ", ":"");
    }
    cout<<"\nMore figures: ";
    for (int i = 0; i < 3; ++i) {
        cout<<figureNumbers.nextLabel()<<(i<=1? ", ":"");
    }
    cout<<"\n";
    FileLabelGenerator figureLabels("Figure",1,"Labels.txt");
    for (int i = 0; i < 3; i++) {
        cout << figureLabels.nextLabel() << "\n";
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