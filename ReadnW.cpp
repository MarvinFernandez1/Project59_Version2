//include necessary files
#include "ReadnW.h"

ReadnW::ReadnW(){

}

//function that creates file
void ReadnW::inFile(string fileName){
    ifstream inFile(fileName);
    if(inFile.is_open()){
        while(getline (inFile,readFile)){
        cout<< readFile <<endl;
    }
    inFile.close();
    }
    else{
        cout << "unable to open file" << endl;
    }
}

//takes input and creates a new file
void ReadnW::writeFile(string newFileName){
    int i;
    cout<<"Enter number of players text\n";
    cin>>i;
    ofstream outFile(newFileName);
    cout<<"Type the player's name, then hit enter and type the player's role, then hit enter."<<endl;
    for(int j;j<(2*i);j++){
    cin>>input;
    outFile << input << endl;
    }
    outFile.close();
}


ReadnW::~ReadnW(){}