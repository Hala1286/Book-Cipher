
//Name:		Hala  Hammad
//Date:		March 24, 2020
//Purpose:	To encode a message based on provided book

#include <iostream>
#include<fstream>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;

//making a structure to hold the positions
typedef struct data_struct {
    int page;
    int line;
    int offset;
}inner_vector;

//declaring a container -vector of vectors - to handle all the information about the characters in the book.
vector <vector <inner_vector*>> encode;
int main(int argc, char** argv)
{
    //argv[argc++]= (char*)"C:\\Users\\hala1\\Desktop\\2ND SEMESTER FANSHAWE cOURSES\\c++\\Project3Question\\books (1)\\books\\Richard3.txt";
    //argv[argc++] = (char*)"C:\\Users\\hala1\\Desktop\\2ND SEMESTER FANSHAWE cOURSES\\c++\\Project3Question\\books (1)\\books\\noodles.txt";
    //argv[argc++] = (char*)"C:\\Users\\hala1\\Desktop\\2ND SEMESTER FANSHAWE cOURSES\\c++\\Project3Question\\books (1)\\books\\encoded.txt";


    srand((unsigned)time(NULL));
    //Create the 255 vectors of type innerVector which are inside the  the outer container
    int i = 255;
    while (i--) {
        vector <inner_vector*> positions;
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
    char ch;

    while (bookInput.get(ch)) {
        //declare new inner vector and instaniate it every loop and push it inside the main container "encode  vector". 
        inner_vector* curr_char = (inner_vector*)malloc(sizeof(inner_vector));
        curr_char->page = pagesCounter;
        curr_char->line = linesCounter;
        curr_char->offset = offsetCounter;

        encode.at((int)ch).push_back(curr_char);
        //specify the requirments by checking character by character and save the information.
        if (ch == '\n') {
            linesCounter++;
            offsetCounter = 0;
        }
        if (ch == '\f') {
            pagesCounter++;
            linesCounter = 0;
            offsetCounter = 0;
        }
        if (ch != '\n' && ch != '\f' && ch != '\r')
            offsetCounter++;
    }
    //open the message file. 
    ifstream messageInput(argv[2]);
    if (!messageInput) {
        cout << "could not open the message file.\n";
        return EXIT_FAILURE;
    }
    //open the file that I should put the output on it.
    ofstream output(argv[3]);
    if (!output) {
        cout << "could not open the output file.\n";
        return EXIT_FAILURE;
    }
    //read the message character by character from the message file thenn read randomly from the container vectors and write encode in the output message. 
    while (messageInput.get(ch)) {
        int randGenerator = rand() % encode[(int)ch].size();
        output << encode[(int)ch][randGenerator]->page << "," << encode[(int)ch][randGenerator]->line << "," << encode[(int)ch][randGenerator]->offset << " ";

    }
}



