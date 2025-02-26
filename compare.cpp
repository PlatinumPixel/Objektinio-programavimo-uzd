#include "bibl.h"

bool compVardas(stud &a, stud &b){
    return a.vard>b.vard;
}

bool compPavard(stud &a, stud &b){
    return a.pava>b.pava;
}

bool compVid(stud &a, stud &b){
    return a.galutinisvid>b.galutinisvid;
}

bool compMed(stud &a, stud &b){
    return a.galutinismed>b.galutinismed;
}