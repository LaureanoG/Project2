#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

int main() {
    // Initialzes variable
    int n = 0, c = 0, r = 0;
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    vector<vector<vector<int> > > validStates(n + 1, vector<vector<int> >(c + 1, vector <int>(r + 1, 0)));

    if (inputFile) {
        cout << "Input file successfully opened!" << endl;
        string line;
        string firstLine;

        vector<int> parameters;
        bool discard = false; // Boolean for checking if all parameters are there
        //Gets the number of operations (the first line in input.txt file)
        getline(inputFile, firstLine);
        int operations = atoi(firstLine.c_str());

        cout << "This is the number of operations running: " << operations << endl;
        cout << endl;

        while (operations > 0) { // Does it for each line in input.txt
            getline(inputFile, line);
            // Gets info from the line to assign n, c, & r
            parameters.clear();
            stringstream ss(line);
            string parameter;
            while (getline(ss, parameter, ' ')) // Delimits and converts from string to int
                parameters.push_back(atoi(parameter.c_str()));

            discard = false;
            switch (parameters.size()) {
            case 0:
            case 1:
            case 2:
                discard = true; // Sets to true to throw out parameters
                break;
            default: // Otherwise, sets the parameters
                n = parameters[0];
                c = parameters[1];
                r = parameters[2];
            };

            if (discard == true) // Ignores this line of parameters
                continue;

            //CHECKING FOR INVALID INPUTS
            if (n > 10000 || r > 100 || c > 100) {
                cout << "The inputs " << n << "," << r << "," << c << " are invalid & were skipped!" << endl;
            }

            else { //Inputs are valid, begin iterative dp
            // Creates data struct for interative dp
            vector<vector<vector<int> > > validStates(n + 1, vector<vector<int> >(c + 1, vector <int>(r + 1, 0)));

            // Performs iterative dp
            for (int i = 0; i < n + 1; i++) { // Chocolates
                for (int j = 0; j < c + 1; j++) { // Columns
                    for (int k = 0; k < r + 1; k++) { // Rows
                        if (k * j == i) // Base Case 1
                            validStates[i][j][k] = 1;
                        else if (k * j < i) // Base Case 2
                            validStates[i][j][k] = 0;
                        else {
                            for (int x = 0; x < k + 1; x++) {
                                if (i - x < 0) break;
                                validStates[i][j][k] += validStates[i - x][j - 1][x];
                            }
                        }
                    }
                }
            }
            outputFile << validStates[n][c][r] << endl;
            }//end of iterative dp
          //decrementing the number of operations
            operations--; 
       }
            outputFile.close();
            inputFile.close();
     }
    else if (!inputFile) { // There was a problem with opening the file
        cout << "Input file could not open!" << endl;
        return -1;
    }
    
    return 0;
}
