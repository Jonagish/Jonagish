#include <iostream>
#include <cmath>

using std::cout;
using std::cin;  
using std::string;

int main(){
    double a, b, c;

    cout << "Enter Side (a): " ; 
    cin >> a;
    cout << "Enter Side (b): ";
    cin >> b;

    c = sqrt((pow(a,2) + pow(b, 2)));

    cout << "The Hypotenuse of the traingle is: " << c;

    return 0;
}
