// This program is created to have the user input a file name from either the command prompt or the IDE console.
// The program will then take that file, will grab every single character in the file and determine if it is a vowel or
// a consonant. If it is a vowel it will determine which one and will add 1 to that vowel variable. It will do this for
// the entire file, and will print out the total vowel count for each vowel along with the total vowel count of all the
// vowels put together.
// Include all libraries needed to complete the assignment
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// Declared all my global variables I will use in more than one function
int A = 0;
int E = 0;
int I = 0;
int O = 0;
int U = 0;
int J = 0;
int K = 0;
int S = 0;
const int STARS_LENGTH = 60;
const int SIDE_STAR_LENGTH = 12;

// This message will be called if no file is inputted to the command prompt or IDE.
void errorMessage(){
        cout << "Error opening file... Now exiting" << endl;
        system("pause");
}
// This function will be called in the beginning of the main function to welcome the user to my program
void welcomeMessage(){
    cout << setw(STARS_LENGTH) << setfill('*') << "" << endl;
    cout << setw(SIDE_STAR_LENGTH) << "" << " Welcome to my Letter Count Program " << setw(SIDE_STAR_LENGTH) << "" << endl;
    cout << setw(STARS_LENGTH) << "" << endl;
    cout << endl;
}
// This function grabs the character in the file the user inputs, and checks to see what letter it is. If it is
// a vowel, it will check which one and will add 1 to said vowel
void letterCheck(char (vowel)){
    switch (vowel) {
        case 'A':
        case 'a':
            A++;
            break;
        case 'E':
        case 'e':
            E++;
            break;
        case 'I':
        case 'i':
            I++;
            break;
        case 'O':
        case 'o':
            O++;
            break;
        case 'U':
        case 'u':
            U++;
            break;
        case 'j':
        case 'J':
            J++;
            break;
        case 's':
        case 'S':
            S++;
            break;
        case 'k':
        case 'K':
            K++;
            break;
    }
}
//This function will be called at the end to print out the results of the number of vowels in the file the user inputs
// Added J, S, and K as letters to add for the Github Submission
void printedResults(){
    string stringA = "The number of A's: ";
    string stringE = "The number of E's: ";
    string stringI = "The number of I's: ";
    string stringO = "The number of O's: ";
    string stringU = "The number of U's: ";
    string stringJ = "The number of J's: ";
    string stringS = "The number of S's: ";
    string stringK = "The number of K's: ";
    string vowelCount = "The vowel count is: ";
    // Added consonantCount as something extra considering the extra 3 letters arent vowels
    string consonantCount = "The consonant count is: ";
    int totalVowelCount = A + E + I + O + U;
    int totalConsonantCount = J + K + S;
    // This brick is what is outputted to the user. I want to take the repeated code in this brick and make another
    // function for it, but my knowledge of inputting one parameter at a time isn't to that level yet. Once it is
    // I will come back and change this brick to look more efficient.
    cout << stringA <<setfill('.') << setw(STARS_LENGTH - stringA.length()) << "" << A << endl;
    cout << stringE << setw(STARS_LENGTH - stringE.length()) << "" << E << endl;
    cout << stringI << setw(STARS_LENGTH - stringI.length()) << "" << I << endl;
    cout << stringO << setw(STARS_LENGTH - stringO.length()) << "" << O << endl;
    cout << stringU << setw(STARS_LENGTH - stringU.length()) << ""  << U << endl;
    cout << stringJ << setw(STARS_LENGTH - stringJ.length()) << ""  << J << endl;
    cout << stringS << setw(STARS_LENGTH - stringS.length()) << ""  << S << endl;
    cout << stringK << setw(STARS_LENGTH - stringK.length()) << ""  << K << endl;
    cout << vowelCount << setw(STARS_LENGTH - vowelCount.length()) << "" << totalVowelCount << endl;
    cout << consonantCount << setw(STARS_LENGTH - consonantCount.length()) << "" << totalConsonantCount;
}
// Main function that will hold all the calls to different functions
int main(int argc, char* argv[]) {
    char vowel;
    // Opens a filestream, which will take argument[1], which will be the file name
    ifstream fileName;
    fileName.open(argv[1]);
    // If statement when the file is not the second argument inputted by the user
    if (!fileName){
        errorMessage();
        return -1;
    }
    welcomeMessage();
    // This while loop serves the purpose of checking the end of file for whatever file the user inputs, while it is not
    // the end of the file, it will extract a character from said file
    while (!fileName.eof() && fileName >> vowel){
        // The letterCheck function is called with the vowel the file supplied
        letterCheck(char (vowel));
    }
    // printed the file the program is analyzing
    cout << "Analyzing file " << '\'' << argv[1] << '\'' << "..." << endl;
    cout << endl;
    // Results are printed by calling this function at the very end
    printedResults();
    return 0;
}
