# ifndef BIBL_H
# define BIBL_H

#include <iostream> 
#include <iomanip>
#include <vector>
#include <algorithm>
#include <ctime>
#include <stdlib.h>
#include <fstream>
#include <algorithm>
#include <chrono> 
#include <sstream> 

using std::cin; 
using std::cout;
using std::endl;
using std::string;  
using std::vector;
using std::setw;

struct stud{
  string vard;
  string pava;
  vector <int> tarp;
  double tarpsum=0;
  double tarpvid;
  double tarpmed;
  double egz;
  double galutinisvid;
  double galutinismed;
};


class Timer {
  private:
    // panaudojame using
    using hrClock = std::chrono::high_resolution_clock;
    using durationDouble = std::chrono::duration<double>;
    std::chrono::time_point<hrClock> start;
  public:
    Timer() : start{ hrClock::now() } {}
    void reset() {
      start = hrClock::now();
    }
    double elapsed() const {
      return durationDouble (hrClock::now() - start).count();
    }
};

void spausdina(vector <stud> );
void rankinis(vector <stud> &);
void pusrankis(vector <stud> &);
void automatiskas (vector <stud> &);
void failoNusk (vector <stud> &,string);
bool compVardas(stud &, stud &);
bool compPavard(stud &, stud &);
bool compVid(stud &, stud &);
bool compMed(stud &, stud &);

extern string Vard[5];
extern string Pava[5];


# endif