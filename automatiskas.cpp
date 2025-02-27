#include "bibl.h"

string Vard[5] {"Jonas", "Vytautas", "Antanas", "Tomas", "Juozas"};
string Pava[5] {"Kazlauskas", "Stankevicius", "Petrauskas", "Janauskas", "Zukauskas"};

void automatiskas (vector <stud> &A){
    stud temp;  

    temp.vard=Vard[rand()%5];
    temp.pava=Pava[rand()%5];


    for (int i=0;i<rand()%10+1;i++){
        int paz=rand()%10+1;
        temp.tarp.push_back(paz);
        temp.tarpsum+=paz;
    }
    std::sort(temp.tarp.begin(),temp.tarp.end());
    temp.egz=rand()%10+1;

    temp.tarpvid=double(temp.tarpsum/temp.tarp.size());
    if (temp.tarp.size()%2==0){
        temp.tarpmed=(temp.tarp[(temp.tarp.size()/2)-1]+temp.tarp[(temp.tarp.size()/2)])/2;
    }
    else temp.tarpmed=temp.tarp[(temp.tarp.size()/2)];

    temp.galutinisvid=(temp.tarpvid*0.4)+(temp.egz*0.6);
    temp.galutinismed=temp.tarpmed*0.4+temp.egz*0.6;
    A.push_back(temp); 
}