#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the Number of Rows: ";
    cin >> n;

    // Upper half
    for (int i = 1; i <= n; i++) {
        
        for (int s = 1; s <= n - i; s++)
            cout << " ";

        
        for (int j = 0; j < 2 * i - 1; j++)
            cout << char('A' + j);

        cout << endl;
    }

    // Lower half
    for (int i = n - 1; i >= 1; i--) {
        
        for (int s = 1; s <= n - i; s++)
            cout << " ";

        for (int j = 0; j < 2 * i - 1; j++)
            cout << char('A' + j);

        cout << endl;
    }

    return 0;
}
