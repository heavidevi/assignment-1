#include <iostream>
using namespace std;

int main() {
    int start, end;
    
    cout << "enter first number: ";
    cin >> start;
    cout << "enter second number: ";
    cin >> end;

    cout << "\neven numbers between " <<" are:\n";
    for (int i = start; i <= end; i++) {
        if (i % 2 == 0)
            cout << i << " ";
    }

    cout << "\n\nodd numbers between " <<" are:\n";
    for (int i = start; i <= end; i++) {
        if (i % 2 != 0)
            cout << i << " ";
    }

    return 0;
}
