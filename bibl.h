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



string Vard[5] {"Jonas", "Vytautas", "Antanas", "Tomas", "Juozas"};
string Pava[5] {"Kazlauskas", "Stankevicius", "Petrauskas", "Janauskas", "Zukauskas"};


# endif