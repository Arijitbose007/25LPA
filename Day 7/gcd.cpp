#include <iostream>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int num1, num2;
    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;
    int result = gcd(num1, num2);
    std::cout << "GCD: " << result << std::endl;
    return 0;
}
int lcm(int a, int b) {
    int gcd = gcd(a, b);
    int lcm = (a * b) / gcd;
    return lcm;
}

int main() {
    int num1, num2;
    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;
    int result = lcm(num1, num2);
    std::cout << "LCM: " << result << std::endl;
    return 0;
}