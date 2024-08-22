#include <iostream>
#include <cmath>

using std::cout;
using std::cin;  
using std::string;

//initializing functions
void makeStar(int size);
void makeRectangle(int rows, int cols);
void makeTriangle(int size);
void makeRhombus(int size);
void makeRightTriangle(int size);
void makeLeftTriangle(int size);
void makeHeart();
void makeXMAtree(int size);

//Function to get size, run the shape functions and to ask if the program should keep running
void doWork(int &size, char & run, void (*func)(int)){
    cout << "Enter Size: ";  
    cin >> size;                                                                        
    func(size);
    cout << "Would you like to continue making Shapes? Y/N" << '\n';
    cin >> run;
}
//Funciton to a triangle in the middle -sorta. 
void triangleinhalf(int size){
    for(int i = 1; i <= size/2; i++){
        for(int j = size/2 - i; j > 0; j--){
            cout << " ";
        }
        for(int k = 0; k < i; k++){
            cout << "* ";
        }
        cout << '\n';
    }
}

//Function to print the top and bottom edges
 void top_n_bottom(int n){
        std::cout << "#";
    for (int i = 0; i < n*4; i++){
        std::cout << "=";
    }
    std::cout << "#" << std::endl;
    }

//Function to print out the content in the rug
void printRow(int spaces, int dots) {
    std::cout << "|";
    std::cout << std::string(spaces, ' ');
    std::cout << "<>";
    std::cout << std::string(dots, '.');
    std::cout << "<>";
    std::cout << std::string(spaces, ' ');
    std::cout << "|" << std::endl;
}

//Function to print out a Lovely Rug
void a_lovely_rug(int n) {
    int spaces = (n * 2) - 2;
    int dots = 0;

    // Print the top part of the rug
    top_n_bottom(n);

    // Print the middle upper part of the rug
    for (int i = 0; i < n; i++) {
        printRow(spaces, dots);
        dots += 4;
        spaces -= 2;
    }

    // Print the middle lower part of the rug
    for (int i = 0; i < n; i++) {
        dots -= 4;
        spaces += 2;
        printRow(spaces, dots);
    }

    // Print the bottom part of the rug
    top_n_bottom(n);
}

//Function to print out an x of stars
void x_of_stars(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == i || j == n - i - 1) {
                std::cout << "*";
            } else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}


int main(){

    int rows, cols, size;
    char run = 'Y';
    string shape;

    cout << "----- WELCOME TO SHAPE BUILDER -----" << "\n";

    while(run == 'Y'){
     cout << "What Shape Would You Like?\n(S) for Star\n(T) for Triangle\n(RT) for Right Triangle\n(LT) for Left Triangle\n(H) for Heart\n(RB) for Rhombus\n(REC) for Rectangle\n(RUG) for a Lovely Rug\n(X) for an X\n";
        cin >> shape;

        if (shape == "S") doWork(size, run, &makeStar);
        else if (shape == "T") doWork(size, run, &makeTriangle);
        else if (shape == "RT") doWork(size, run, &makeRightTriangle);
        else if (shape == "LT") doWork(size, run, &makeLeftTriangle);
        else if (shape == "H") cout << "Would you like to continue making Shapes? Y/N\n", cin >> run;
        else if (shape == "RB") doWork(size, run, &makeRhombus);
        else if (shape == "REC") {
            cout << "Enter Rows: ", cin >> rows, cout << "Enter Columns: ", cin >> cols;
            makeRectangle(rows, cols);
            cout << "Would you like to continue making Shapes? Y/N\n", cin >> run;
        }
        else if (shape == "XMA") doWork(size, run, &makeXMAtree);
        else if (shape == "RUG") doWork(size, run, &a_lovely_rug);
        else if (shape == "X") doWork(size, run, &x_of_stars);
        else cout << "******THIS IS NOT A shape, PLEASE ENTER AGAIN******\n";
    }

    cout << "-----------------------------------------------------";

    return 0;
}

void makeXMAtree(int size){
    triangleinhalf(size);
    triangleinhalf(size);
    triangleinhalf(size);

    for(int i = 1; i <= size/2; i++){
        for(int j = 1; j < size; j++){
            cout << " ";
        }
        cout << "*" << '\n';

    }
}


void makeStar(int size){
for(int i = 1; i <= size; ++i){
        for(int j = 1; j < 2*(size+2); ++j){
            cout << " ";
        }
        for(int sp = size; sp > i; --sp){
            cout << " ";
        }
        for(int ast = 1; ast <= i; ++ast){
            cout << "* ";
        }
        cout << '\n';
    }

    for(int r = 1; r <= (size+3)/2; ++r){

        for(int sp = 1; sp <= 3*(r-1)+1; ++sp){
            cout << " ";
        }
        for(int ast = 3*(size+1); ast >= 3*(r-1) +1; --ast){
            cout << "* ";
        }
        cout << "\n";
    }

    for(int r =1; r <= size/2-1; ++r){
        for(int sp = 3*(size+1)/2; sp >= r; --sp){
            cout << " ";
        }
        for(int ast = 1; ast <= (3*size+3)/2 + r; ++ast){
            cout << "* ";
        }
        cout << '\n';
    }

    for(int r=1; r<= (size+1)/2; ++r){

        for(int sp =(2*size+7)/2; sp >=r; --sp){
            cout << " ";
        }

        for(int ast = size; ast > 2*(r-1); --ast){
            cout << "* ";
        }

        for(int sp = 1; sp <= 10*(r-1)+2; ++sp){
            cout << " ";
        }

        for(int ast = size; ast > 2*(r-1); --ast){
            cout << "* ";
        }
        cout << '\n';
    }

}
//Fucntion to print Rectangle
void makeRectangle(int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << "* ";
        }
        cout << '\n';
    }
    return; 
}

void makeTriangle(int size){
    for(int i = 1; i <= size; i++){
        for(int j = size - i; j > 0; j--){
            cout << " ";
        }
        for(int k = 0; k < i; k++){
            cout << "* ";
        }
        cout << '\n';
    }
}

void makeRhombus(int size){
    triangleinhalf(size);

    for(int i = 1; i <= (size/2) - 1; i++){
        for(int j = 0; j < i; j++){
            cout << " ";
        }
        for(int k = 0; k < (size/2) - i; k++){
            cout << "* ";
        }
        cout << '\n';
    }
}
//Funciton to print Rigth Triangle
void makeRightTriangle(int size){
    for(int i = 1; i <= size; i++){
        for(int j = 0; j < i; j++){
            cout << "* ";
        }
        cout << '\n';
    }
}

//Function to make Left Triangle
void makeLeftTriangle(int size){
     for (int i = 0; i < size; i++) {
        //white spaces
        for (int j = 0; j < size - i - 1; j++) {
            std::cout << " ";
        }

        //stars
        for (int j = 0; j < i + 1; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

void makeHeart(){

}
