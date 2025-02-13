# ifndef BIBL_H
# define BIBL_H

#include <iostream> 
#include <iomanip>
#include <vector>
#include <algorithm>
#include <ctime>
#include <stdlib.h>

using std::cin; 
using std::cout;
using std::endl;
using std::string;  
using std::vector;
using std::setw;

struct stud{
    string vard;
    string pava;
    int n;
    vector <int> tarp;
    double tarpsum=0;
    double tarpvid;
    double tarpmed;
    double egz;
    double galutinisvid;
    double galutinismed;
};

string Vard[5] {"Jonas", "Vytautas", "Antanas", "Tomas", "Juozas"};
string Pava[5] {"Kazlauskas", "Stankevicius", "Petrauskas", "Janauskas", "Zukauskas"};


# endif