#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

string file = "List.txt";
string fileSorted = "List.txt"; // "List-sorted.txt";
string fileBak = "List.txt_bak";
vector<string> Liste1(0, "");

void displayListe1() { // Ok.
    for(int a = 0; a < Liste1.size(); a++) {
        cout << Liste1[a] << endl;
        }
    }

void revertList1(){
for (int a=0;a<(Liste1.size()/2);a++){
swap(Liste1[a],Liste1[Liste1.size()-a-1]);
}

}
void initListe(string fileName1 = file) {   // With BAK. // Ok.
    ifstream file(fileName1.c_str(), ios::in);
    ofstream outfile(fileBak.c_str());     // Pas d'append pour le BAK : on remplace !
    if(!file) {
        cerr << "Impossible to read the file: " << fileName1 << endl;
        }
    else if(!outfile) {
        cerr << "Impossible to write the BAK file: " << fileBak << endl;
        }
    else {
        string line;
        while(getline(file, line)) {
            Liste1.push_back(line);
            outfile << line << endl;
            }
        file.close();
        }
    }

void writeListe1(string fileOut = "out.txt") { // Ok.
    ofstream outfile(fileOut.c_str());     // Pas d'append : on remplace ! On a déjà sauvé avant.
    if(!outfile) {
        cerr << "Impossible to write the file: " << fileOut << endl;
        }
    else {
        string line;
        for(int a = 0; a < Liste1.size(); a++) {
            outfile << Liste1[a] << endl;
            }
        outfile.close();
        }
    }

int main() {
    initListe();
    displayListe1(); // Tests ok.
    revertList1();
    cout << " " << endl;
    displayListe1(); // Tests ok.
   writeListe1(fileSorted);
    cout << "\nOk." << endl;
    return 0;
    }
