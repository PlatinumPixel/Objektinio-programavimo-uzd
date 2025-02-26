#include "bibl.h"



vector <stud> A;

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










