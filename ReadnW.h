//includes necessary files
#ifndef READNW_H
#define READNW_H
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class ReadnW{

    protected:
    //sets data members
    string fileName;
    string newFileName;
    string readFile;
    string input;
    //sets function members
    public:
    ReadnW();
    void inFile(string fileName);
    void writeFile(string newFileName);
    ~ReadnW();
};
#endif