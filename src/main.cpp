#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>

// File needed for program to run properly.
std::fstream NEEDEDFILE{"shopped.log"};

void addSale(int saleAmount){
    // Read file, then add saleAmount to amount read, then overwrite the contents of the file with the new total.

    std::string context;

    // Read logic.
    std::ifstream file{"shopped.log"};
    //std::getline(file, context);
    if(file.is_open()){
        context = file.get();
    }

    //Convert 'tmp' to int. 
    int tmpint;
    std::stringstream strstream;
    strstream << context;
    strstream >> tmpint;


    //FIXME: Addition error when writing
    // Add the sale amount to the temporary intager.
    int tmpTotal = saleAmount + tmpint;

    std::ofstream fileWrite{"shopped.log"};
    
    if(!fileWrite){
        std::cerr << "FATAL: unable to open file!";
        getchar();
    }

    fileWrite << tmpTotal << "\n";
    file.close();
    fileWrite.close();
}

int main(void){
    using namespace std;

    string option;

    if(!NEEDEDFILE){
        cout << "Missing files detected!\n";
        cout << "Creating needed files... \n";
        NEEDEDFILE.open("shopped.log");
    }

    system("cls");
    cout << "Enter help for command list\n";
    cout << "Please enter a command:  ";

    cin >> option;

    if(strcmp(option.c_str(), "as") == 0){
        cout << "How much money was recieved with the sale?  ";
        int saleAmount;
        cin >> saleAmount;
        addSale(saleAmount);
    }

    else if(strcmp(option.c_str(), "TEST") == 0){
        cout << "Test works! \n";
        getchar();
    } else {
        cerr << " FATAL:  failed to recognise command!";
        return 1;
    }
        
    

    return 0;
}