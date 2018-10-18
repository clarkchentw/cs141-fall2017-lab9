#include <iostream>
using namespace std;

/*
 * Return the integer length of the character array source[].
 */
int myStrlen(char source[]) {
    int length = 0;
    for (int i = 0; source[i] != '\0'; i++){
        length++;
    }

    return length;
}

/*
 * Copy the source character array to the destination character array.
*/
void myStrcpy(char destination[], char source[]) {
	// Your code here...
    for (int i = 0; i < myStrlen(source); i++){
        destination[i] = source[i];
    }
    
}

/*
 * Return the integer position of the last occurrence of the character target in the source character array.
 *    Note: Return -1 if the character is not found.
*/
int myStrrchr(char source[], char target) {
	// Your code here...
	int position = -1;
    for (int i = 0; i < myStrlen(source); i++){
        if (source[i] == target){
            position = i;
        }
    }

    return position;
}

/*
 * Return true if the source character array is a palindrome, otherwise return false.
*/
bool isPalindrome(char source[]) {
	// Your code here...
	
    for (int i = 0; i < myStrlen(source); i++){
        
        // cout << "source[" << i << "] vs. source[" <<myStrlen(source)-1-i << "]" << endl;
        // cout << source[i] << " vs. " << source[myStrlen(source)-1-i] << endl << endl;
        if (source[i] != source[myStrlen(source)-1-i]){
            
            return false;
        }
    }
    
    return true; // All characters match, so it was a palindrome
}

/*
 * Give menu options to all operations on a string,
 * such as copying, searching, as well as checking if the string is a palindrome.
*/
int main()
{
    //Assign the original string
    char source[ 81];
    int menuChoice = 0;
    
    //This loop repeats the 4 options regarding operations on the string.
    do {
        cout << endl 
        	 << "---------------------------------------------------------------------" << endl
		     << "Select the function you want to use:" << endl 
             << "   1. Copy a string (our own strcpy)" << endl
             << "   2. Find last position of a character in a string (our own strrchr)" << endl
             << "   3. Check if the string is a palindrome" << endl
             << "   4. Exit the program" << endl
             << "Your choice: ";
        cin >> menuChoice;
        cout << endl;

        // Copy a string, our own version of strcpy
        if( menuChoice == 1){
            char destination[ 81];
            cout << "Enter a word with no spaces for the source: ";
            cin >> source;
            myStrcpy( destination, source);
            
            cout << "The copied string is " << destination << endl;
            source[ 0] = 'Z';
            cout << "After alteration, the original string is " << source << endl
			     << "           and the destination string is " << destination << endl;

        // Searching for the last occurrence of a character in the given string, our own version of strrchr
        } else if( menuChoice == 2) {
        	cout << "Enter a word with no spaces for the source: ";
            cin >> source;
            
            char target = '\0';
            cout << "Please enter a character for which to search: ";
            cin >> target;

            int position = myStrrchr(source, target);

            if(position != -1){
                cout << "The position of " << target << " in the string " << source << " is " << position << endl;
            } else {
                cout << "The position of " << target << " in the string " << source << " is not found!" << endl;
            }

        // Check if the string is a palindrome
        } else if( menuChoice == 3) {
        	cout << "Enter a word with no spaces for the source: ";
            cin >> source;
            
            if( isPalindrome(source) ) {
                cout << "The string: \"" << source << "\" IS a palindrome!" << endl;
            } else {
                cout << "The string: \"" << source << "\" is NOT a palindrome." << endl;
            }

        //Exit the program
        } else if( menuChoice == 4){
            cout << "Goodbye. " << endl;
        } else {
            cout << "Sorry, you have given an invalid option!" << endl;
        }
    } while( menuChoice != 4);




    return 0;
} // end main()
