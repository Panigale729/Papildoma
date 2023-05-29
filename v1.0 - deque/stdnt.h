#pragma once

#include "mylib.h"


//struktûra studento
struct studentas {
    string vardas = "";
    string pavarde = "";
    vector<int> nd;       //namø darbø paþymiø vektorius
    int egz = 0;          //egzamino paþymys
    double galutinis_v = 0; //galutinis paþymys = 0.4 * vidurkis (nd) + 0.6 * egz
    //double galutinis_m = 0; //galutinis paþymys = 0.4 * mediana (nd) + 0.6 * egz
};

void galutinis_balas(studentas& asmuo); //galutinio balo paskaiciavimas
bool rusiuoti_paz(const studentas& x,const studentas& y); //rusiavimui

deque<studentas> studentu_pildymas();      //pildome studentus
void asmens_pildymas(studentas& asmuo);   //uþpildome vieno studento duomenis
