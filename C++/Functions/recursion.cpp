#include <iostream>

using namespace std;

int recursiveSum(int a, int b) {
    if (a > b) return 0;
    return a + recursiveSum(a + 1, b);
};

int main(){

    cout << "Enter two integers: ";
    int a, b, c;
    cin >> a >> b;

    // if (a > b) {
    //     c = a;
    //     a = b;
    //     b = c;
    // }
    // int sum = 0;
    
    // cout << "Sum fo numbers: " << sum << "\n";



    return 0;
}