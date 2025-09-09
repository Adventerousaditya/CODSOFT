#include <bits/stdc++.h>
using namespace std;

struct Game {
    array<char, 9> b{};
    char cur = 'X';
    Game() { b.fill(' '); }

    void draw() const {
        cout << "\n";
        for (int r = 0; r < 3; ++r) {
            for (int c = 0; c < 3; ++c) {
                int i = r*3 + c;
                cout << " " << (b[i]==' ' ? char('1'+i) : b[i]) << " ";
                if (c<2) cout << "|";
            }
            if (r<2) cout << "\n---+---+---\n";
        }
        cout << "\n\n";
    }

    bool move(int cell) {
        if (cell < 1 || cell > 9 || b[cell-1] != ' ') return false;
        b[cell-1] = cur;
        return true;
    }

    bool win(char p) const {
        static int w[8][3]={{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
        for (auto &line:w) if (b[line[0]]==p && b[line[1]]==p && b[line[2]]==p) return true;
        return false;
    }
    bool full() const { return all_of(b.begin(), b.end(), [](char x){return x!=' ';}); }
    void switchPlayer(){ cur = (cur=='X'?'O':'X'); }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "=== Tic-Tac-Toe ===\nPlayers: X and O\n";
    while (true) {
        Game g;
        while (true) {
            g.draw();
            cout << "Player " << g.cur << ", choose cell (1-9): ";
            int x; 
            if (!(cin >> x)) return 0;
            if (!g.move(x)) { cout << "Invalid move. Try again.\n"; continue; }
            if (g.win(g.cur)) { g.draw(); cout << "Player " << g.cur << " wins!\n"; break; }
            if (g.full())     { g.draw(); cout << "It's a draw.\n"; break; }
            g.switchPlayer();
        }
        cout << "Play again? (y/n): ";
        char ans; cin >> ans;
        if (ans!='y' && ans!='Y') break;
    }
    return 0;
}
