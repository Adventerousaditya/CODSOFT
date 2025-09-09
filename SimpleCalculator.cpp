#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "=== Simple Calculator ===\n";
    cout << "Operations: +  -  *  /  %  ^(power)\n";
    cout << "Enter: <number> <op> <number>\n";
    long double a, b; char op;
    if (!(cin >> a >> op >> b)) { cout << "Invalid input.\n"; return 0; }

    cout.setf(std::ios::fixed); cout << setprecision(6);

    switch (op) {
        case '+': cout << (a + b) << "\n"; break;
        case '-': cout << (a - b) << "\n"; break;
        case '*': cout << (a * b) << "\n"; break;
        case '/':
            if (b == 0) cout << "Error: division by zero.\n";
            else cout << (a / b) << "\n";
            break;
        case '%': {
            long long x = llround(a), y = llround(b);
            if (y == 0) cout << "Error: modulo by zero.\n";
            else cout << (x % y) << "\n";
            break;
        }
        case '^': cout << pow(a, b) << "\n"; break;
        default: cout << "Unknown operator.\n";
    }
    return 0;
}
