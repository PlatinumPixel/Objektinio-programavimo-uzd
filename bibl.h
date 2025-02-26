# ifndef BIBL_H
# define BIBL_H


#include "stud.h"
#include "std.h"

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