#include "Universe.cpp"
using namespace std;
void solve(){
    Universe game;
    game.initialize();
    game.run(10);
    game.reset();
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
