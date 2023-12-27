//include libraries that your code uses
#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include "Project3a.h"
#include "Graph.h"

void lower(string &myString);

///////////////// Before submitting your code
//1) uncomment this part since zyBooks use it.
/*int main(int argc, const char* argv[]) {
    if (argc != 2)
    {
        std::cout << "./project3 inputFile" << std::endl;
        return EXIT_FAILURE;
    }
    string inputFileName = argv[1];
*/
///////////////////// uncomment above befofre submitting on zyBooks /////////////////
//2) Comment the next 2 lines below
int main(void) {

    string inputFileName = "input1.txt";    //Do NOT change the name "inputFileName" since used above

    //file handling
    ifstream inFS;
    inFS.open(inputFileName);
    string column1;
    string column2;

    if (!inFS.is_open()) {
        cout << "Could not open file :(" << endl;
        return 1; // 1 indicates error
    }

    //temp variables used to store a single line of an input file
    Account *temp1, *temp2;
    //main graph used
    Graph accountGraph;

    //cout << 
    while (!inFS.eof() && !inFS.fail()) {
        //read in account names from a single line
        inFS >> column1 >> column2;
        //SET THE STRINGS TO LOWERCASE
        lower(column1); lower(column2);

        //add the account from the first column if the name is not already in the graph
       // accountGraph.AddAccount(column1);
        cout << "Added col1" << endl;
        //add account from the second column if the name is not already in the graph
        //accountGraph.AddAccount(column2);

        //insert temp2 into followers of temp 1
        //column2 follows temp1
        //accountGraph.GetAccountFromName(column1)->InsertFollower(column2);

        //insert temp1 into following of temp 2
        //accountGraph.GetAccountFromName(column2)->InsertFollowing(column1);

        //temp1 in graph
        //accountGraph.GetAccountFromName(column1)
        //temp2 in graph
        //accountGraph.GetAccountFromName(column2)

    }
    //accountGraph.GetAccountFromName("microsoft").PrintFollowing();
    //find root account
    //accountGraph.SetRoot();
    

    //perform search
    //cout << accountGraph.GetRoot()->GetRootDist();

    //accountGraph.BFS();
    //accountGraph.PrintSN();

    return 0;
}

void lower(string &myString) {
    for (unsigned int i = 0; i < myString.length(); ++i) {
        myString[i] = tolower(myString[i]);
    }
}