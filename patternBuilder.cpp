#include <iostream>
#include <cmath>

using std::cout;
using std::cin;  
using std::string;

//initializing functions
void makeStar();
void makeRectangle(int rows, int cols);
void makeTriangle();
void makeRhombus();
void makeRightTriangle();
void makeLeftTriangle();
void makeHeart();



int main(){

    int rows;
    int cols;
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
            run = false;
        }
        //Right Triangle pattern
        else if(pattern == "RT"){
            run = false;
        }
        //Left Trianlge pattern
        else if(pattern == "LT"){
            run = false;
        }
        //Heart pattern
        else if(pattern == "H"){
            run = false;
        }
        //Rhombus pattern
        else if(pattern == "RB"){
            run = false;
        }
        //Rectangle Pattern
        else if(pattern == "REC"){
            cout << "Enter Rows: ";
            cin >> rows;
            cout << "Enter Columns: ";
            cin >> cols;

            makeRectangle(rows, cols);

            run = false;
        }
        else{
            cout << "******THIS IS NOT A PATTERN, PLEASE ENTER AGAIN******" << '\n';
        }
    }

    cout << "---------------------------------------";

    return 0;
}

void makeStar(){

}

void makeRectangle(int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << "* ";
        }
        cout << '\n';
    }
    return; 
}

void makeTriangleint(){


}

void makeRhombus(){

}

void makeRightTriangle(){

}

void makeLeftTriangle(){

}

void makeHeart(){

}
