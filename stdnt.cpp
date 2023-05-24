#include "stdnt.h"
#include "ivest_tikrinimai.h"


void galutinis_balas(studentas& asmuo) {

    int nd_suma = accumulate(asmuo.nd.begin(), asmuo.nd.end(), 0);

    double nd_pask_v = double(nd_suma) / asmuo.nd.size(); //vidurkis

    //mediana
    sort(asmuo.nd.begin(), asmuo.nd.end());
    double nd_pask_m;

    if (asmuo.nd.size() == 1) {
        nd_pask_m = asmuo.nd[0];
    }
    else if (asmuo.nd.size() % 2 != 0) {
        nd_pask_m = asmuo.nd[asmuo.nd.size() / 2];
    }
    else {
        nd_pask_m = (asmuo.nd[asmuo.nd.size() / 2] + asmuo.nd[asmuo.nd.size() / 2 - 1]) / 2.0;
    }

    asmuo.galutinis_v = 0.4 * nd_pask_v + 0.6 * asmuo.egz;
    asmuo.galutinis_m = 0.4 * nd_pask_m + 0.6 * asmuo.egz;
}

bool rusiuoti_pavard(studentas& x, studentas& y) {
    return x.pavarde < y.pavarde;
}

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
