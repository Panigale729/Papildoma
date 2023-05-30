#include "darb_su_fail.h"
#include "mylib.h"
#include "generavimas.h"
#include "ivest_tikrinimai.h"
#include "stdnt.h"

#include <string>
#include <vector>
#include <algorithm>
#include <execution>


//-------------------------------------------------------------------------------------------------------------------------------------------------------
//GAUNAME PRADINIUS STUDENTU DUOMENIS

void darbas_su_generuotais(vector<studentas>& grupe, bool skirstymas) {
    long long int stud_sk = 1000; //maziausias failas
    int n = 0;

    vector<studentas> silpnuciai;
    vector<studentas> gudruciai;

    cout << "Jeigu nenorite dirbti su (is anksto) sugeneruotais failais - iveskite „1“\n";
    cout << "Jeigu norite dirbti su (is anksto) sugeneruotais failais - iveskite „0“\n";

    bool generavimas_fail;
    generavimas_fail = tikrinti_bool();


    for (auto& i : input_files) {

        auto start = hrclock::now(); // matuosime laika

        cout << endl << "Failo dydis:" << stud_sk << endl;
        if(generavimas_fail) generavimas(i, stud_sk);
        skaitymas(i, grupe);    //reikia laiko
        rikiavimas(grupe);      //reikia laiko

        //spausdinimas(grupe, sorted[n]);

        if (skirstymas) {
            skirstymas_2(grupe, silpnuciai, gudruciai); //i 2 naujus vektorius, istrinant sena. reikia laiko
            spausdinimas(silpnuciai, silpnuciai_out[n]);
            spausdinimas(gudruciai, gudruciai_out[n]);
        }
        else {
            skirstymas_1(grupe, silpnuciai);  //Nauju budu: tik silpnucius iskelti i atskira faila
            spausdinimas(silpnuciai, silpnuciai_out[n]);
            spausdinimas(grupe, gudruciai_out[n]);
        }

        duration diff = hrclock::now() - start;

       // cout << endl << stud_sk << " irasu testo laikas: " << diff.count() << "s" << endl;

        stud_sk *= 10;
        n++;
        system("pause");

        grupe.clear();
        silpnuciai.clear();
        gudruciai.clear();

    }
}



void darbas_su_paruostais(vector<studentas>& grupe) {
    string isvest_fail = "txt_failai/kursiokai.txt";

    cout << "Pasirinkite studentø failà: " << endl;
    cout << "1. studentai1000000.txt" << endl;
    cout << "2. studentai100000.txt" << endl;
    cout << "3. studentai10000.txt" << endl;
    cout << "Áveskite pasirinkimo numerá: ";

    bool gera_ivest = false;
    int pasirinkimas;

    //tikriname ivesti
    while (!gera_ivest) {

        while (!(cin >> pasirinkimas)) {
            cin.clear(); // pasaliname error flag`us
            cin.ignore(INT_MAX, '\n'); // praignoruojame bloga ivesti
            cout << "Iveskite teisingà pasirinkimo numerá (1-3): ";
        }
        cin.ignore(); // ignoruojame \n

        if (pasirinkimas >= 1 && pasirinkimas <= 3) {
            gera_ivest = true;
        }
        else {
            cout << "Iveskite teisingà pasirinkimo numerá (1-3): ";
        }
    }

    string skait_fail;

    if (pasirinkimas == 1) {
        skait_fail = "txt_failai/studentai1000000.txt";
    }
    else if (pasirinkimas == 2) {
        skait_fail = "txt_failai/studentai100000.txt";
    }
    else if (pasirinkimas == 3) {
        skait_fail = "txt_failai/studentai10000.txt";
    }

    cout << endl << "*Vyksta skaitymas is failo ir isvedimas*\n" << endl;

    try {
        skaitymas(skait_fail, grupe); //skaitymas ir áraðymas vyksta per buffer`á. Is karto pildome studentus.
    }
    catch (const exception& e) {
        cout << "Klaida vykdant programà: " << e.what() << endl;
        return;
    }

    rikiavimas(grupe);

    spausdinimas(grupe, isvest_fail);

}



void darbas_su_ivedimu(vector<studentas>& grupe) {
    string isvest_fail = "txt_failai/kursiokai.txt";

    try {
        grupe = studentu_pildymas();
    }
    catch (const exception& e) {
        cout << "Klaida vykdant programà: " << e.what() << endl;
        return;
    }

    spausdinimas(grupe, isvest_fail);

}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//DARBAS SU IVEDIMU

vector<studentas> studentu_pildymas() {

    bool testi = true;
    vector<studentas> grupe;

    while (testi) { //tikrinam, ar vartotojas nori ávesti dar studentà + ávedimas

        grupe.push_back(studentas());   //pridedame naujà studentà á vektoriø.
        asmens_pildymas(grupe.back());   //pildome paskutinio pridëto studento duomenis
        galutinis_balas(grupe.back());

        //ar tæsti toliau ávedinëti studentus?
        cout << "Jeigu norite tæsti studentø ávedimà - áveskite „1“" << endl << "Jeigu nenorite tæsti studento ávedimo - áveskite „0“" << endl << endl;
        testi = tikrinti_bool();
    }

    rikiavimas(grupe);

    return grupe;
}


void asmens_pildymas(studentas& asmuo) { //uþpildome vieno studento duomenis

    //vardas, pavardë
    asmuo.vardas = tikrinti_vard(1);
    asmuo.pavarde = tikrinti_vard(2);

    //paþymiai
    int paz_sk = 0;
    double nd_pask = 0; //paskaièiuota pagal vidurká arba medianà

    //Þiûrime, ar vartotojas nori, jog paþymiai (ir jø skaièius), egzamino balas bûtø sugeneruojami atsitiktinai
    bool generuoti;

    cout << endl << "Jeigu norite tæsti, jog paþymiø skaièius, paþymiai ir egzamino balas bûtø generuojami atsitiktinai áveskite „1“" << endl;
    cout << "Jeigu nenorite atsitiktinio generavimo áveskite „0“" << endl;
    generuoti = tikrinti_bool();

    if (generuoti) {
        //pagerintas atsitiktinio skaièiaus generavimas
        random_device rd;
        mt19937 gen(rd());

        uniform_int_distribution<int> paz_sk_dist(3, 10);
        uniform_int_distribution<int> paz_dist(0, 10);

        paz_sk = paz_sk_dist(gen);
        asmuo.nd.resize(paz_sk); //resizinam`e vektoriø atitinkamai

        for (int i = 0; i < paz_sk; i++) {  //uþpildome nd vektoriø paþymiais
            asmuo.nd[i] = paz_dist(gen); //generuojame nuo 0 iki 10
        }

        asmuo.egz = paz_dist(gen);  //generuojame nuo 0 iki 10

    }
    else {

        //namø darbø paþymiai
        cout << "Áveskite paþymius (nuo 0 iki 10):" << endl;
        cout << "Norint baigti paþymiø ávedimà, áveskite bet koká simbolá/-ius (iðskyrus paþymius):" << endl;

        asmuo.nd.reserve(10); //uþrezervuojame vietos 10 paþymiø (kiek ir atsitiktinai generuojam). Iðvengsim nereikalingo atminties perskirstymo.

        int p; //vienas paþymys

        while (cin >> p && p >= 0 && p <= 10) {
            //Reiðkia ávedë paþymá
            asmuo.nd.push_back(p);
        }

        asmuo.nd.shrink_to_fit(); //kad elementø skaièius vektoriuje sutaptø su jo dydþiu

        cin.clear(); //iðtriname error flag`us
        cin.ignore(INT_MAX, '\n'); //praignoruojame, kas liko ið neteisingos ávesties


        if (asmuo.nd.empty()) {
            throw runtime_error("Studento " + asmuo.vardas + " " + asmuo.pavarde + " namø darbø paþymiø nëra.");
        }

        cout << "Áveskite egzamino paþymá: " << endl;
        asmuo.egz = tikrinti_pazymi();
    }

    cout << "Ðio studento duomenys sëkmingai áraðyti" << endl << endl;
}