// Project3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<fstream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;

//declaring a container -vector of vectors - to handle all the information about the characters in the book.
vector <vector <string>> encode;
int main(int argc, char** argv)
{
    //argv[argc++] = (char*)"C:\\Users\\hala1\\Desktop\\2ND SEMESTER FANSHAWE cOURSES\\c++\\Project3Question\\books (1)\\books\\Richard3.txt";
     //argv[argc++] = (char*)"C:\\Users\\hala1\\Desktop\\2ND SEMESTER FANSHAWE cOURSES\\c++\\Project3Question\\books (1)\\books\\encoded.txt";
     //argv[argc++] = (char*)"C:\\Users\\hala1\\Desktop\\2ND SEMESTER FANSHAWE cOURSES\\c++\\Project3Question\\books (1)\\books\\decoding.txt";



    srand(time(NULL));
    //Create the 255 vectors of type innerVector which are inside the  the outer container
    int i = 255;
    while (i--) {
        vector <string> positions;
        encode.push_back(positions);
        if (i < 0)
            break;
    }
    //Reading the text from the book.
    ifstream bookInput(argv[1]);
    if (!bookInput) {
        cout << "could not open the bookInput file.\n";
        return EXIT_FAILURE;
    }
    //declaring some variables that are useful to store the required information.
    int offsetCounter = 0;
    int linesCounter = 0;
    int pagesCounter = 0;

    string offsetStr;
    string linesStr;
    string pagesStr;

    string code;

    char ch;

    while (bookInput.get(ch)) {
        //change the numbers to strings to push back to the vector
        pagesStr = to_string(pagesCounter);
        linesStr = to_string(linesCounter);
        offsetStr = to_string(offsetCounter);
        //create a string that contains the code.
        code = pagesStr + "," + linesStr + "," + offsetStr;
        //push the vector to the big vector encode.
        encode.at((int)ch).push_back(code);

        offsetCounter++;

        if (ch == '\n') {
            linesCounter++;
            offsetCounter = 0;
        }

        if (ch == '\f') {
            pagesCounter++;
            linesCounter = 0;
            offsetCounter = 0;
        }
    }
    //open the code file. 
    ifstream codeInput(argv[2]);
    if (!codeInput) {
        cout << "could not open the message file.\n";
        return EXIT_FAILURE;
    }
    //open the message file. 
    ofstream messoutput(argv[3]);
    if (!messoutput) {
        cout << "could not open the output file.\n";
        return EXIT_FAILURE;
    }
    
    //declare variable to store the code which will be read from the code file
    string charCode;

    while (codeInput >> charCode) {
        //read the encode vector to compare the codes and find the character that exist in thats location.
        for (int i = 0; i< encode.size(); ++i) {
            for (int j = 0; j < encode[i].size(); ++j) {

                if ((encode[i][j] == charCode))
                    messoutput << (char)i;


            }


        }
    }
}


