#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <limits>


using std::cout;
using std::cin;
using std::string;
using std::vector;

//text colors
const string RESET = "\033[0m";
const string BRIGHT_GREEN = "\033[92m";
const string BRIGHT_YELLOW = "\033[93m";
const string BRIGHT_RED = "\033[91m";
const string BRIGHT_MAGENTA = "\033[95m";
const string BRIGHT_BLUE = "\033[94m";
const string BRIGHT_CYAN = "\033[96m";

void upperString(string &word);
void draw_menu();
void get_words(vector<string> &words);
void draw_table( const string &current_word,  const vector<string> &tries);

int main() {
    srand(static_cast<unsigned>(time(0)));  // Seed for random number generation

    vector<string> words;  // Vector to store the five-letter words
    get_words(words);  // Populate the vector with words from the file


    

    bool run = true;  // Flag to control the game loop

    do {
        vector<string> tries(5 , "     ");  // Vector to store the user's guesses
        int randomNum = rand() % words.size();  // Randomly select a word
        string current_word = words[randomNum];  // The word to guess

        char input;
        draw_menu();  // Display the game menu
        cin >> input;  // Get user input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        cout << '\n';

        // Validate user input
        if (std::toupper(input) != 'Y' && std::toupper(input) != 'N') {
            cout << BRIGHT_RED << "WRONG INPUT - TRY AGAIN\n" << RESET;
        } else if (std::toupper(input) == 'N') {
            run = false;  // Exit the game loop
        } else {
            string answer;
            int i = 0;

            // Main game loop
            while (i < 5) {
                draw_table(current_word, tries);  // Display the current state of the board
                bool check = true;

                cout <<BRIGHT_CYAN << "ENTER A FIVE LETTER WORD: " << RESET;

                // Loop to ensure the user inputs a valid five-letter word
                while (check) {
                    cin >> answer;
                    upperString(answer);

                    auto it = std::find(words.begin(), words.end(), answer);
                    auto ot = std::find(tries.begin(), tries.end(), answer);

                    if (answer.length() != 5 || it == words.end()) {
                        cout << BRIGHT_RED << "NOT A FIVE LETTER WORD (OR) WORD NOT IN DATABASE\nPLEASE ENTER AGAIN: " << RESET;
                    } 
                    else if(ot != tries.end()){
                        cout << BRIGHT_YELLOW << "ALREADY ATTEMPTED - TRY AGAIN: " << RESET;
                    }
                    else {
                        check = false;
                        tries[i] = answer;  // Store the valid guess
                    }
                    if (answer == current_word){
                        i = 5;
                    }
                }
                i++;
            }

            
            draw_table(current_word, tries);  // Display the final state of the board
            if(answer == current_word){
                cout << BRIGHT_MAGENTA << "\n!!!!!! CONGRATULATIONS YOU GUESSED THE WORD !!!!!!\n\n" << RESET;
            }
            else{
                cout << BRIGHT_CYAN << "\nTHE CORRECT WORD WAS - " << RESET << BRIGHT_GREEN << current_word << RESET <<'\n';
            }
        }

    } while (run);


    return 0;
} 


void upperString(string & word){
    for(char& ch : word){
        ch = std::toupper(static_cast<unsigned char>(ch));
    }
}

// Function to read five-letter words from a file and store them in a vector
void get_words(vector<string> &words) {
    std::ifstream file("five-letter-words.txt");
    string word;
    while (file >> word) {
        upperString(word);
        words.push_back(word);
    }
}

// Function to display the game menu with colored text
void draw_menu() {
    cout << BRIGHT_YELLOW <<"******** GUESS THE FIVE LETTER WORD ********\n" << RESET;
    cout << BRIGHT_GREEN << "------- (Y) TO CONTINUE" << RESET << BRIGHT_RED << " / (N) TO STOP -------\n" << RESET;
    cout << BRIGHT_YELLOW << "********************************************\n" << RESET;
}

// Function to display the current state of the game board
void draw_table(const string &current_word,  const vector<string> &tries) {
    cout << BRIGHT_YELLOW << "===============\n" << RESET;
    for(int i = 0; i < 5; i++){
        string temp = tries[i];
        for(int j = 0; j < 5; j++){
            if(temp[j] == current_word[j]){
                cout << BRIGHT_GREEN << temp[j] << RESET << ' ';
            }
            else if(current_word.find(temp[j]) != std::string::npos){
                cout << BRIGHT_YELLOW << temp[j] << RESET << ' ';
            }
            else{
                cout << BRIGHT_RED << temp[j] << RESET << ' ';
            }
        }
        cout << '\n';
        cout << BRIGHT_BLUE << "---------\n" << RESET;
    }


    cout << BRIGHT_YELLOW << "===============\n" << RESET;
    
}
