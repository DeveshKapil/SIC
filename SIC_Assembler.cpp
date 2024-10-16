#include<iostream>
#include<unordered_map>
#include<fstream>
#include<sstream>

using namespace std;

void seperate(string &line , string &label , string &opcode , string &operand)
{
    stringstream ss(line);
    if (line[0] != ' ' && line[0] != '\t') {
        ss >> label;
    } else {
        label = "";
    }
    ss >> opcode >> operand;
}

void firstPass(ifstream &ifile , int &pstart , int &plen , unordered_map<string , string> &optab , unordered_map<string , int> &symtab)
{
    string line , label , opcode , operand;
    int locctr = 0;
    bool flag  = false;

    while(getline(ifile , line))
    {
        seperate(line , label , opcode , operand);
        
    }
}


int main()
{
    unordered_map<string , string> optab = {
        {"LDA", "00"}, {"LDX", "04"}, {"LDL", "08"}, {"STA", "0C"}, {"STX", "10"}, {"STL", "14"},
        {"ADD", "18"}, {"SUB", "1C"}, {"MUL", "20"}, {"DIV", "24"}, {"COMP", "28"}, {"TIX", "2C"},
        {"JEQ", "30"}, {"JGT", "34"}, {"JLT", "38"}, {"J", "3C"}, {"AND", "40"}, {"OR", "44"},
        {"JSUB", "48"}, {"RSUB", "4C"}, {"LDCH", "50"}, {"STCH", "54"}, {"ADDF", "58"}, {"SUBF", "5C"},
        {"MULF", "60"}, {"DIVF", "64"}, {"LDB", "68"}, {"LDS", "6C"}, {"LDF", "70"}, {"LDT", "74"},
        {"STB", "78"}, {"STS", "7C"}, {"STF", "80"}, {"STT", "84"}, {"COMPF", "88"}, {"ADDR", "90"},
        {"SUBR", "94"}, {"MULR", "98"}, {"DIVR", "9C"}, {"TIXR", "B8"}, {"CLEAR", "B4"}, {"SHIFTL", "A4"},
        {"SHIFTR", "A8"}, {"SVC", "B0"}, {"FLOAT", "C0"}, {"FIX", "C4"}, {"NORM", "C8"}, {"LPS", "D0"},
        {"STSW", "E8"}, {"RD", "D8"}, {"WD", "DC"}, {"TD", "E0"}, {"SSK", "EC"}, {"STI", "D4"}
    };
    unordered_map<string , int> symtab;

    int progStart = 0 , progLen = 0;

    cout << "Enter name of file\n";
    string str;
    cin >> str;

    ifstream ifile(str+".txt");
    ofstream ofile("ObjectCode.txt");

    if(!ifile.is_open() && !ofile.is_open())
    {
        cerr << "Error opening files" << endl;
        return 1;
    }

    firstPass (ifile , progStart , progLen , optab , symtab);

    secondPass ( ifile , ofile , progStart , optab , symtab);

    ifile.close();
    ofile.close();

    cout << "Assembling complete...\nThe Opcode generated is stored in ObjectCode.txt\n";

    return 0;
    
}
