#include <bibl.h>

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

vector <stud> A;

void spausdina(vector <stud> A,int m);
void rankinis(vector <stud> &A);


int main(){  
    setlocale(LC_ALL, "Lithuanian");
    int m;  //studentu skaičius
    cout << "Iveskite studentu skaičiu " << setw(20);
    cin >> m;
    for (int i=0;i<m;i++){
        rankinis(A);
    }
    spausdina(A,m);
 return 0;
}

void rankinis(vector <stud> &A){
    stud temp;  
    int input;
        cout << "Iveskite studento Varda ir pavarde " << setw(20);
        cin >> temp.vard >> temp.pava;
        cout << "Iveskite studento pažymiu kieki (neskaitant egzamino) " << setw(20);
        cin >> temp.n;
        cout << "Iveskite studento pažymius " ;
        for (int j=0;j<temp.n;j++){
            cin >> input;
            temp.tarp.push_back(input);
            temp.tarpsum+=input;
        }
        std::sort(temp.tarp.begin(),temp.tarp.end());
        cout << "Iveskite studento egzamino rezultata ";
        cin >> temp.egz;

        temp.tarpvid=double(temp.tarpsum/temp.n);
        if (temp.n%2==0){
            temp.tarpmed=(temp.tarp[(temp.n/2)-1]+temp.tarp[(temp.n/2)])/2;
        }
        else temp.tarpmed=temp.tarp[(temp.n/2)];

        temp.galutinisvid=(temp.tarpvid*0.4)+(temp.egz*0.6);
        temp.galutinismed=temp.tarpmed*0.4+temp.egz*0.6;
        A.push_back(temp);    
}

void spausdina(vector <stud> A, int m){
        cout << "Pavardė    Vardas      Galutinis(vid.) / Galutinis(med.)" << endl;
        cout << "----------------------------------------------------" << endl;
    for (int i=0;i<m;i++){
        cout << std::left << setw(12) << A[i].pava << setw(15) << A[i].vard  << setw(16) << A[i].galutinisvid << " " << A[i].galutinismed << endl;
    }

}