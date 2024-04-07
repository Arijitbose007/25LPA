#include <iostream>
#include <string>
#include <algorithm>  // For std::max

using namespace std;

int main() {
    string str;
    int n;

    cout << "Enter the string: ";
    getline(cin, str);

    cout << "Enter the value of n: ";
    cin >> n;

    int maxCount = 0, count = 0;
    for (int i = 0; i < str.length(); i++) {
        if (i % n == 0) {
            maxCount = std::max(count, maxCount);
            count = 0;
        }

        if (str[i] == 'a') {
            count++;
        }
    }

    // Update maxCount one last time to capture the final count of 'a's
    maxCount = std::max(count, maxCount);

    cout << "Maximum count of consecutive 'a's: " << maxCount << endl;

    return 0;
}
