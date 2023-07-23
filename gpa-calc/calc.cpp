#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[]) {
    fstream fin;
    fin.open(argv[1], ios::in);
    
    unordered_map<string, int> grades = {
        {"A", 4},
        {"B", 3},
        {"C", 2},
        {"D", 1},
        {"F", 0}
    };
    
    int gpa_sum = 0;
    int num_credits = 0;

    // Read csv file
    string line;
    while (getline(fin, line)) {
        // Split line by comma
        vector<string> tokens;
        stringstream ss(line);
        string token;
        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        gpa_sum += grades[tokens[0]] * stoi(tokens[1]);
        num_credits += stoi(tokens[1]);
    }

    cout << setprecision(2) << fixed; // Set decimal precision to 2
    cout << "Cumulative GPA: " << (double)gpa_sum / num_credits << endl;
    return 0;
}
