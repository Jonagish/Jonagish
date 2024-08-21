#include <iostream>
#include <cmath>

using std::cout;
using std::cin;  
using std::string;

//initializing functions
void makeStar();
void makeRectangle(int rows, int cols);
void makeTriangle(int size);
void makeRhombus(int size);
void makeRightTriangle(int size);
void makeLeftTriangle(int size);
void makeHeart();
void makeCXMtree(int size);
void triangleinhalf(int size){
    for(int i = 1; i <= size/2; i++){
        for(int j = size - i; j > 0; j--){
            cout << " ";
        }
        for(int k = 0; k < i; k++){
            cout << "* ";
        }
        cout << '\n';
    }
}


int main(){

    int rows, cols, size;
    bool run = true;
    string pattern;


    cout << "----- WELCOME TO PATTERN BUILDER -----" << "\n";

    cout << "What Pattern Would You Like?" << '\n';

    while(run){
        cout << "(S) for Star" << '\n' << 
        "(T) for Triangle" << '\n' << 
        "(RT) for Rigth Triangle" << '\n' <<
        "(LT) for Left Triangle" << '\n' <<
        "(H) for Heart" << '\n' <<
        "(RB) for Rhombus" << '\n' <<
        "(REC) for Rectangle" << '\n';

        cin >> pattern;
        //Star pattern
        if(pattern == "S"){
            run = false; 
        }
        //Triangle pattern
        else if(pattern == "T"){
            cout << "Enter Size: ";                                                                         
            cin >> size;
            makeTriangle(size);
            run = false;
        }
        //Right Triangle pattern
        else if(pattern == "RT"){
            cout << "Enter Size: ";                                                                         
            cin >> size;
            makeRightTriangle(size);

            run = false;
        }
        //Left Trianlge pattern
        else if(pattern == "LT"){
            cout << "Enter Size: ";                                                                         
            cin >> size;
            makeLeftTriangle(size);

            run = false;
        }
        //Heart pattern
        else if(pattern == "H"){
            run = false;
        }
        //Rhombus pattern
        else if(pattern == "RB"){
            cout << "Enter Size: ";                                                                         
            cin >> size;
            makeRhombus(size);

            run = false;
        }
        //Rectangle Pattern
        else if(pattern == "REC"){
            cout << "Enter Rows: ";
            cin >> rows;
            cout << "Enter Columns: ";
            cin >> cols;
            cout << '\n';
            makeRectangle(rows, cols);

            run = false;

        }
        else if(pattern == "CXM"){
            cout << "Enter Size: ";                                                                         
            cin >> size;
            makeCXMtree(size);

            run = false;
        }
        else{
            cout << "******THIS IS NOT A PATTERN, PLEASE ENTER AGAIN******" << '\n';
        }
    }

    cout << "---------------------------------------";

    return 0;
}

void makeCXMtree(int size){
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


void makeStar(){

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
    triangleinhalf(size*2);
    
    for(int i = 1; i < size/2; i++){
        for(int j = 1; j < i; j++){
            cout << " ";
        }
        for(int k = size; k > 1; k--){
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
