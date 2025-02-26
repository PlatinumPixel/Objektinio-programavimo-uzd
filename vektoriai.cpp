#include "bibl.h"

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

vector <stud> A;


void spausdina(vector <stud> A);
void rankinis(vector <stud> &A);
void pusrankis(vector <stud> &A);
void automatiskas (vector <stud> &A);
void failoNusk (vector <stud> &A,string failas);
bool compVardas(stud &a, stud &b);
bool compPavard(stud &a, stud &b);
bool compVid(stud &a, stud &b);
bool compMed(stud &a, stud &b);

int main(){  
    srand(time(NULL));
    char input;
    string failas;
    cout << "Iveskite skaiciu kokiu budu norite ivesti duomenis " << endl;
    cout << "1 - Iveskite visus duomenis rankiniu budu " << endl;
    cout << "2 - Iveskite varda ir pavarde rankniu budu " << endl;
    cout << "3 - Sugeneruoti visus duomenis automatiskai " << endl;
    cout << "4 - Paiimti duomenis is failo " << endl;
    cout << "5 - Baigti darba ir spausdinti " << endl;
    while ((cin >> input)){
        switch(input){
            case '1':
                rankinis(A);
                break;

            case '2':
                pusrankis(A);
                break;

            case '3':
                int n;
                cout << "Iveskite kiek mokiniu generuoti" << endl;
                cin >> n;
                for (int i=0;i<n;i++){
                    automatiskas(A);        
                }
                break;

            case '4':
                
                cout << "Iveskite failo pavadinima (pvz. kursiokai.txt)" << endl;
                cin >> failas;
                failoNusk(A,failas);
                break;

            case '5':
                cout << "Pagal ka isrusiuoti duomenis?" << endl;
                cout << "1 - Pagal Varda " << endl;
                cout << "2 - Pagal Pavarde " << endl;
                cout << "3 - Pagal pazymiu vidurki " << endl;
                cout << "4 - Pagal pazymiu mediana " << endl;

                cin >> input;

                switch(input){
                    case '1':
                        std::sort(A.begin(),A.end(), compVardas);
                        break;

                    case '2':
                        std::sort(A.begin(),A.end(), compPavard);
                        break;

                    case '3':
                        std::sort(A.begin(),A.end(), compVid);
                        break;

                    case '4':
                        std::sort(A.begin(),A.end(), compMed);
                        break;
                }

                spausdina(A);
                return 0;
            default:
                cout << "Ivedete neteisinga simobli, pabandykit vel! :)" << endl;
                break;
        }
        cout << "Iveskite skaiciu kokiu budu norite ivesti duomenis " << endl;
        cout << "1 - Iveskite visus duomenis rankiniu budu " << endl;
        cout << "2 - Iveskite varda ir pavarde rankniu budu " << endl;
        cout << "3 - Sugeneruoti visus duomenis automatiskai " << endl;
        cout << "4 - Paiimti duomenis is failo " << endl;
        cout << "5 - Baigti darba ir spausdinti " << endl;   
    }
 return 0;
}

void rankinis(vector <stud> &A){
    stud temp; 
    int input; 

        cout << "Iveskite studento Varda ir pavarde ";
        cin >> temp.vard >> temp.pava;

        cout << "Veskite studento namu darbo pazymius arba neskaiciu, kad daugiau pazymiu nerasyti ";
        
        while (cin >> input){
            temp.tarp.push_back(input);
            temp.tarpsum+=input;
        }
        cin.clear();
        cin.ignore();
        std::sort(temp.tarp.begin(),temp.tarp.end());

        cout << "Iveskite studento egzamino rezultata ";
        cin >> temp.egz;

        temp.tarpvid=double(temp.tarpsum/temp.tarp.size());
        if (temp.tarp.size()%2==0){
            temp.tarpmed=(temp.tarp[(temp.tarp.size()/2)-1]+temp.tarp[(temp.tarp.size()/2)])/2;
        }
        else temp.tarpmed=temp.tarp[(temp.tarp.size()/2)];

        temp.galutinisvid = ( temp.tarpvid * 0.4) + ( temp.egz * 0.6);
        temp.galutinismed= temp.tarpmed * 0.4 + temp.egz* 0.6;
        A.push_back(temp);    
}

void spausdina(vector <stud> A){
        cout << "Vardas              Pavarde        Galutinis(vid.) / Galutinis(med.)" << endl;
        cout << "--------------------------------------------------------------------" << endl;
    for (int i=0;i<A.size();i++){
        cout << std::left << setw(20) << A[i].vard << setw(15) << A[i].pava  << setw(18) << std::fixed << std::setprecision(2) << A[i].galutinisvid << " " << A[i].galutinismed << endl;
    }

}

void pusrankis(vector <stud> &A){
    stud temp;  

        cout << "Iveskite studento Varda ir pavarde ";
        cin >> temp.vard >> temp.pava;
        for (int i=0;i<rand()%10+1;i++){
            int paz=rand()%10;
            temp.tarp.push_back(paz);
            temp.tarpsum+=paz;
        }
        std::sort(temp.tarp.begin(),temp.tarp.end());
        temp.egz=rand()%10;

        temp.tarpvid=double(temp.tarpsum/temp.tarp.size());
        if (temp.tarp.size()%2==0){
            temp.tarpmed=(temp.tarp[(temp.tarp.size()/2)-1]+temp.tarp[(temp.tarp.size()/2)])/2;
        }
        else temp.tarpmed=temp.tarp[(temp.tarp.size()/2)];

        temp.galutinisvid=(temp.tarpvid*0.4)+(temp.egz*0.6);
        temp.galutinismed=temp.tarpmed*0.4+temp.egz*0.6;
        A.push_back(temp); 
}

void automatiskas (vector <stud> &A){
    stud temp;  

    temp.vard=Vard[rand()%4];
    temp.pava=Pava[rand()%4];


    for (int i=0;i<rand()%10+1;i++){
        int paz=rand()%10;
        temp.tarp.push_back(paz);
        temp.tarpsum+=paz;
    }
    std::sort(temp.tarp.begin(),temp.tarp.end());
    temp.egz=rand()%10;

    temp.tarpvid=double(temp.tarpsum/temp.tarp.size());
    if (temp.tarp.size()%2==0){
        temp.tarpmed=(temp.tarp[(temp.tarp.size()/2)-1]+temp.tarp[(temp.tarp.size()/2)])/2;
    }
    else temp.tarpmed=temp.tarp[(temp.tarp.size()/2)];

    temp.galutinisvid=(temp.tarpvid*0.4)+(temp.egz*0.6);
    temp.galutinismed=temp.tarpmed*0.4+temp.egz*0.6;
    A.push_back(temp); 
}

void failoNusk (vector <stud> &A, string failas){
    string eil;

    Timer t;
    std::ifstream df(failas);
    getline(df,eil);
    while(getline(df,eil)){
        stud temp;
        int paz;
        std::istringstream line(eil);
        line >> temp.vard >> temp.pava;
        while (line >> paz){
            temp.tarp.push_back(paz);
            temp.tarpsum+=paz;
        }
        temp.tarpsum-=temp.tarp.back();
        temp.egz=temp.tarp.back();
        temp.tarp.pop_back();

        std::sort(temp.tarp.begin(),temp.tarp.end());
        temp.tarpvid=double(temp.tarpsum/temp.tarp.size());
        if (temp.tarp.size()%2==0){
            temp.tarpmed=(temp.tarp[(temp.tarp.size()/2)-1]+temp.tarp[(temp.tarp.size()/2)])/2;
        }
        else temp.tarpmed=temp.tarp[(temp.tarp.size()/2)];
    
        temp.galutinisvid=(temp.tarpvid*0.4)+(temp.egz*0.6);
        temp.galutinismed=temp.tarpmed*0.4+temp.egz*0.6;
        A.push_back(temp);
    }
    cout << "Perskaityt ir suskaiciuot vidurkius uztruko" << t.elapsed() << endl;
    df.close();
}

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