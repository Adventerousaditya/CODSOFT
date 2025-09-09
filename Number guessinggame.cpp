#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    random_device rd; mt19937 gen(rd()); uniform_int_distribution<int> dist(1, 100);
    int secret = dist(gen);

    cout << "=== Number Guessing Game ===\n(I'm thinking of a number 1..100)\n";
    int tries = 0;
    while (true) {
        cout << "Enter your guess: ";
        long long g;
        if (!(cin >> g)) { cout << "Please enter a number!\n"; cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); continue; }
        if (g < 1 || g > 100) { cout << "Stay within 1..100.\n"; continue; }
        ++tries;
        if (g == secret) { cout << "Correct! You took " << tries << " tries.\n"; break; }
        cout << (g < secret ? "Too low.\n" : "Too high.\n");
    }
    return 0;
}
