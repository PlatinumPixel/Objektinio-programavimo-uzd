#include "bibl.h"

void spausdina(vector <stud> A){
    cout << "Vardas              Pavarde        Galutinis(vid.) / Galutinis(med.)" << endl;
    cout << "--------------------------------------------------------------------" << endl;
for (int i=0;i<A.size();i++){
    cout << std::left << setw(20) << A[i].vard << setw(15) << A[i].pava  << setw(18) << std::fixed << std::setprecision(2) << A[i].galutinisvid << " " << A[i].galutinismed << endl;
}

}