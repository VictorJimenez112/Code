//This is a code that I developed during one of my academic classes before discontinuing the program for personal reasons.
//Unfortunately, I haven't had the chance to apply this skill in a work environment, which has limited my practical experience.

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
using namespace std;

int main() {

    string title, colOneHeader, colTwoHeader, dataPoint;
    vector<string> words;
    vector<int> numbers;

    cout << "Enter a title for the data:" << endl;
    getline(cin, title);
    cout << "You entered: " + title << endl;

    cout << "Enter the column 1 header:" << endl;
    getline(cin, colOneHeader);
    cout << "You entered: " + colOneHeader << endl;

    cout << "Enter the column 2 header:" << endl;
    getline(cin, colTwoHeader);
    cout << "You entered: " + colTwoHeader << endl;

    while (dataPoint != "-1") {

        cout << "Enter a data point (-1 to stop input):" << endl;
        getline(cin, dataPoint);

        vector <string> input;
        if (dataPoint =="-1"){
            cout <<""<<endl;
            break;
        }
        string line = "";
        stringstream  x(dataPoint);
        int commas = 0;

        try {
            for (unsigned int i = 0; i < dataPoint.length(); i++) {
                if (dataPoint.at(i) == ',') {
                    commas++;
                }
            }
            if (commas == 0) {
                throw invalid_argument("Error: No comma in string.");
            }

            if (commas > 1) {
                throw invalid_argument("Error: Too many commas in input.");
            }

            while (getline(x, line, ',')) {
                input.push_back((line));
            }
            try {
                int data = stoi(input[1]);
                words.push_back(input [0]);
                numbers.push_back(data);
                cout << "Data string: " << dataPoint.substr(0,dataPoint.find(','))<< endl;
                cout << "Data integer: " << data << endl;
            }
            catch (exception const&) {
                cout << "Error: Comma not followed by an integer." << endl;
            }
        }

        catch (invalid_argument& er)
        {
            cout << er.what() << endl;
        }

    }

    cout << setw(33);
    cout << title << endl;
    cout << left << setw (20);
    cout << colOneHeader;
    cout << '|' ;
    cout << right << setw (23);
    cout << colTwoHeader << endl;
    cout << "--------------------------------------------" << endl;

    for (unsigned int i = 0; i < words.size(); i++)
    {
        cout << left << setw (20);
        cout << words [i];
        cout << '|' ;
        cout << right << setw (23);
        cout << numbers [i] << endl;
    }

    cout << endl;

    for (unsigned int i = 0; i < words.size(); i++)
    {
        cout << right << setw (20);
        cout << words [i] << " ";

        for (int j = 0; j < numbers [i]; j++){
            cout << left << setw (0);
            cout << "*" ;
        }
        cout << endl;
    }


    return 0;
}