#include "bibl.h"

void rankinis(vector <stud> &A){
    stud temp; 
    int input; 

        cout << "Iveskite studento Varda ir pavarde ";
        cin >> temp.vard >> temp.pava;

        cout << "Veskite studento namu darbo pazymius arba N, kad sustoti ";
        
        while (true){
            try{
                if (input==78) break;
                if (!(cin>>input)||input<0 || input>10){
                    cin.clear();
                    cin.ignore();
                    throw "Ivestas neteisingas simbolis";
                }
            temp.tarp.push_back(input);
            temp.tarpsum+=input;
            }
            catch (char const *x){
                cout << x << endl;
                continue;
            }
        }

        std::sort(temp.tarp.begin(),temp.tarp.end());

        cout << "Iveskite studento egzamino rezultata ";
        while (true){
            try{
                if (!(cin>>input)||input<0 || input>10){
                    cin.clear();
                    cin.ignore();
                    throw "Ivestas neteisingas simbolis";
                }
            temp.egz=input;
            break;
            }
            catch (char const *x){
                cout << x << endl;
                continue;
            }
        }

        temp.tarpvid=double(temp.tarpsum/temp.tarp.size());
        if (temp.tarp.size()%2==0){
            temp.tarpmed=(temp.tarp[(temp.tarp.size()/2)-1]+temp.tarp[(temp.tarp.size()/2)])/2;
        }
        else temp.tarpmed=temp.tarp[(temp.tarp.size()/2)];

        temp.galutinisvid = ( temp.tarpvid * 0.4) + ( temp.egz * 0.6);
        temp.galutinismed= temp.tarpmed * 0.4 + temp.egz* 0.6;
        A.push_back(temp);    
}