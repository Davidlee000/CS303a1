

#include <iostream>
#include<fstream>
#include "functions.h"
using namespace std;


int main()
{
    int myarray[150] = {};
    char userinput;
    int value, index;
    fstream fin("myfile.txt");
    for (int i = 0; i < 100; i++) {
        fin >> myarray[i];
    }
    while (true) {
        //menu
        cout << "Enter C to check if number is in array" << endl;
        cout << "Enter M to modify a number" << endl;
        cout << "Enter A to add a number" << endl;
        cout << "Enter R to remove a number" << endl;
        cout << "Enter E to exit" << endl;

        //try and catch for menu choice.
        try {
            cin >> userinput;
            if (userinput != 'C' && userinput != 'M' && userinput != 'A' && userinput != 'R' && userinput != 'E') {
                throw 1;
            }
            
        }
        catch (...) {
            cout << "Choose a valid menu choice\n" << endl;
        }

        //menu choices
        switch (userinput) {
        case 'C':
            cout << "Enter an integer" << endl;
            //assumes valid input
            cin >> value;
            //assumes array size 150
            if (check_num_present(value, myarray) == 150) {
                cout << "Integer not in array" << endl;
            }
            else {
                cout << "Integer found in array location " << check_num_present(value, myarray) << endl;
            }
            break;

        case 'M':
            cout << "Enter the location of the array to modify" << endl;
            //uses try and catch to verify input
            while (true) {
                try {
                    cin >> index;
                    cin.ignore();
                    if (index < 0 || index>149) {
                        throw out_of_range("number not in index");
                    }
                    break;
                }
                catch (out_of_range) {
                    cout << "Enter an integer between 0 and 149" << endl;
                }
                catch (...) {
                    cout << "try again" << endl;
                }
            }
            cout << "Enter a new value for that location" << endl;
            cin >> value;
            cout << "The previous value at that location was" << modify_at_index(index, value, myarray)<<endl;
            cout << "The value at index " << index << " is " << myarray[index] << endl;
            break;

        case 'A':
            cout << "Enter a value to add to the end of the array"<<endl;
            //try and catch for user inputs
            while (true) {
                try {
                    cin >> value;
                    if (!cin) {
                        throw 1;
                    }
                    break;
                }
                catch (...) {
                    cout << "Enter an integer" << endl;
                }
            }
            add_int(value, myarray);
            break;
            
        case 'R':
            cout << "Enter an index to remove" << endl;
            while (true) {
                try {
                    cin >> index;
                    if (index < 0 || index>149) {
                        throw out_of_range("number not in index");
                    }
                    break;
                }
                catch (out_of_range) {
                    cout << "Enter an integer between 0 and 149" << endl;
                }
            }
            remove_int(index, myarray);
            break;

        }
        cout << endl;
    }
    fin.close();

}

