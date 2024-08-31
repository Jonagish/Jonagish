#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <limits.h>
#include <stdlib.h>





// use this instead of namespace std
using std::cout;
using std::cin;  
using std::string;
using std::vector;  

//defining complicated/long datatypes
using int_vec2D = std::vector<std::vector<int>>; 
using str = std::string; 


using str_vec2D = std::vector<std::vector<str>>;

/* -- USEFUL MATH RELATED FUNCTIONS -- 
    std::max( , ); min likewise
    pow(,) power function
    sqrt() square root
    abs() absolute val
    round()
    ceil() round up
    floor(); 

*/

/* -- USEFUL STRING METHODS  -- 
    std::getline(std::cin, var); 
    length
    
    */

/*ternary operator -- replacement of if/else statement
condition ? expresion 1 : expresion 2;

**one way to calculate the size of an array is to do, 
the size of the array, divided by the datatype**

**For each loop to do more simple iterations;
ex: for(int number : (already and arr or vec )numbers){
    cout <<number; 
}
**fill() = fills a range of elements with a specified value
            fill(begin, end, value)

** empty() = checks if a string or array is empty

    const parameter = parameter that is effectevely read-only
                    code is more secure & conveys intent
                    useful for references and pointers


** pointers = variable that stores the memory address of another variable

** nullptr = null pointers are helpful when determining if an address 
            was succesfuly assigned to a pointer

** dynamic memory = Memory on the heap is allocated dynamically,
                    meaning it can be allocated and 
                    deallocated at runtime as needed. 
                    This allows for greater flexibility in how much memory is used.

                    use "new" to allocate a new memory, and "delete" to deallocate that memory
                    it is also useful when creating an array of undefined size

** funciton template = describes what a function looks like.
                       can be use to generate as many overloaded functions
                       aas needed, eachusing different data types 

                       use keyword auto so the compiler deduces what return type should be 
                       template <typename T>

** enums = user defined data types that consists
           of paired named integer constants. 


** structs
?@

*/
static int count = 0;

class Human{
    public:
        str name;
        int age;
        str pronoun[3] = {};
        str occupation; 
        int num;

        void action(){
            cout << name << " is " << age << " and " << pronoun[2] << " occupation is " << occupation;
        }

        void print(){
            cout << name << "\n";
            cout << age << "\n";
            cout << occupation << "\n";
        }

        Human(){
            count++;
            num = count;
            cout << "No. of Object created " << num << "\n";
        }

        Human(str name, int age, str occupation){
            this->name = name;
            this->age = age;
            this->pronoun[3] = pronoun[3];
            this->occupation = occupation;

        }

        ~Human(){
            cout << "No. of Object created " << num << "\n";

        }

};


int main(){
    Human human1, human2, human3, human4;

    int num = 5;
    int *ptr = &num;


    cout << ptr << " Adress of num" << "\n";
    cout << &ptr << " Adress of ptr" << "\n";


    return 0;

}
