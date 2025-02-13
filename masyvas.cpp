#include "bibl.h"

struct stud{
    string vard;
    string pava;
    int *tarp = new int [10];
    int size=0;
    double tarpsum=0;
    double tarpvid;
    double tarpmed;
    double egz;
    double galutinisvid;
    double galutinismed;
};

vector <stud> A;

void spausdina(vector <stud> A);
void rankinis(vector <stud> &A);
void pazymiai(stud &temp);

int main(){  
    setlocale(LC_ALL, "Lithuanian");
    char input;
    cout << "Iveskite Y kad irasyti studenta, arba N kad sustoti ir atspausdinti ";
    while ((cin >> input)){
        if (input=='Y'){
            rankinis(A);
            cout << "Iveskite Y kad irasyti studenta, arba N kad sustoti ir atspausdinti " << endl;
            continue;
        }
        if (input=='N'){
            spausdina(A);
            break;
        }
        cout << "Ivedete neteisinga simobli, pabandykit vel! :)" << endl;
        cout << "Iveskite Y kad irasyti studenta, arba N kad sustoti ir atspausdinti " << endl;
    }
 return 0;
}

void rankinis(vector <stud> &A){
    stud temp;  

        cout << "Iveskite studento Varda ir pavarde ";
        cin >> temp.vard >> temp.pava;
        cout << "Veskite studento namu darbo pazymius arba neskaiciu, kad daugiau pazymiu nerasyti ";
        pazymiai(temp);
        std::sort(temp.tarp,temp.tarp+temp.size);
        cout << "Iveskite studento egzamino rezultata ";
        cin >> temp.egz;

        temp.tarpvid=double(temp.tarpsum/temp.size);
        if (temp.size%2==0){
            temp.tarpmed=(temp.tarp[(temp.size/2)-1]+temp.tarp[(temp.size/2)])/2;
        }
        else temp.tarpmed=temp.tarp[(temp.size/2)];

        temp.galutinisvid=(temp.tarpvid*0.4)+(temp.egz*0.6);
        temp.galutinismed=temp.tarpmed*0.4+temp.egz*0.6;
        A.push_back(temp);    
}

void spausdina(vector <stud> A){
        cout << "Pavarde    Vardas      Galutinis(vid.) / Galutinis(med.)" << endl;
        cout << "----------------------------------------------------" << endl;
    for (int i=0;i<A.size();i++){
        cout << std::left << setw(12) << A[i].pava << setw(15) << A[i].vard  << setw(16) << A[i].galutinisvid << " " << A[i].galutinismed << endl;
    }

}

void pazymiai(stud &temp){
    int input;
    int i=0;
    while (cin >> input){
        temp.tarp[i];
        temp.tarpsum+=input;
        i++;
        temp.size++;
    }
    cin.clear();
    cin.ignore();
}