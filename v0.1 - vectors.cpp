#include "Mylib.h"


//struktûra studento
struct studentas {
    string vardas = "";
    string pavarde = "";
    vector<int> nd;       //namø darbø paþymiø vektorius
    int egz = 0;          //egzamino paþymys
    double galutinis = 0; //galutinis paþymys = 0.4 * vidurkis/mediana (nd) + 0.6 * egz
};


//funkcijos deklaracijos
char pradzia();                                   //pradinis tekstas + pasirinkimas, kaip skaièiuoti galutiná balà

vector<studentas> studentu_pildymas(char x);     //pildome studentus
void asmens_pildymas(studentas& asmuo, char x);   //uþpildome vieno studento duomenis

int tikrinti_pazymi();                            //tikriname, ar ávestas paþymys yra nuo 0 iki 10
string tikrinti_vard(int v);                      //tikriname, ar vardas/pavardë sudaryta/-as tik ið raidþiø
bool tikrinti_bool();                             //tikriname, ar ávedë bool reikðmæ

void spausdinti(char x, vector<studentas>& grupe); //spausdinimas
void asmens_spausdinimas(studentas& asmuo);        //spausdiname vieno studento rezultatus

string didziosios(string a);                      //Verèia vardo ir pavardës raides á didþiàsias



int main()
{
    setlocale(LC_ALL, "Lithuanian"); //Ágaliname lietuviðkas raides

    // PROGRAMOS PRADÞIA
    char x = pradzia(); // x yra 'v' - vidurkiui arba 'm' - medianai

    // STUDENTØ ÁVEDIMAS (ÁVEDAME STUDENTØ, KIEK TIK NORIME)
    vector<studentas> grupe = studentu_pildymas(x);

    // SPAUSDINIMAS
    spausdinti(x, grupe);
}



char pradzia() {
    cout << "Paleidote programà, skirtà studento galutiniam balui apskaièiuoti." << endl;
    cout << "Galutinis balas = 0.4 * namø darbø paþymiø vidurkis/mediana + 0.6 * egzamino paþymys." << endl << endl;
    cout << "Pasirinkite, kà naudosite galutinio balo skaièiavimui: " << endl;
    cout << "Vidurká - áveskite raidæ „v“. " << endl;
    cout << "Medianà - áveskite raidæ „m“. " << endl;
    cout << "Jûsø pasirinkimas: ";

    string a;
    getline(cin, a);
    //tikriname ávestá
    while (a != "v" && a != "m") {
        cout << "Neteisinga ávestis. Bandykite dar kartà (áveskite: „v“ arba „m“). " << endl;
        getline(cin, a);
    }

    cout << "Pasirinkimas iðsaugotas." << endl << endl;
    cout << "Pradëkite studentø ávedimà." << endl << endl;

    char x = a[0];

    return x;
}



vector<studentas> studentu_pildymas(char x) {

    bool testi = true;
    vector<studentas> grupe;

    while (testi) { //tikrinam, ar vartotojas nori ávesti dar studentà + ávedimas

        grupe.push_back(studentas());   //pridedame naujà studentà á vektoriø.
        asmens_pildymas(grupe.back(), x);   //pildome paskutinio pridëto studento duomenis

        //ar tæsti toliau ávedinëti studentus?
        cout << "Jeigu norite tæsti studentø ávedimà - áveskite „1“" << endl << "Jeigu nenorite tæsti studento ávedimo - áveskite „0“" << endl << endl;
        testi = tikrinti_bool();
    }

    return grupe;
}



void asmens_pildymas(studentas& asmuo, char x) { //uþpildome vieno studento duomenis

    //vardas, pavardë
    asmuo.vardas = tikrinti_vard(1);
    asmuo.pavarde = tikrinti_vard(2);

    //paþymiai
    int nd_suma = 0;
    int paz_sk = 0;
    double nd_pask = 0; //paskaièiuota pagal vidurká arba medianà

    //Þiûrime, ar vartotojas nori, jog paþymiai (ir jø skaièius), egzamino balas bûtø sugeneruojami atsitiktinai
    bool generuoti;

    cout << endl << "Jeigu norite tæsti, jog paþymiø skaièius, paþymiai ir egzamino balas bûtø generuojami atsitiktinai áveskite „1“" << endl;
    cout << "Jeigu nenorite atsitiktinio generavimo áveskite „0“" << endl;
    generuoti = tikrinti_bool();

    if (generuoti) {
        srand(time(NULL)); //nustatome seed`à atsitiktinio generatoriaus

        int paz_sk = rand() % 8 + 3; //sugeneruojame atsitiktiná skaièiø paþymiø (nuo 3 iki 10)
        asmuo.nd.resize(paz_sk); //resizinam`e vektoriø atitinkamai

        for (int i = 0; i < paz_sk; i++) {  //uþpildome nd vektoriø paþymiais
            asmuo.nd[i] = rand() % 11; 
        }
        
        nd_suma = accumulate(asmuo.nd.begin(), asmuo.nd.end(), 0);

        asmuo.egz = rand() % 11; //generuojame nuo 0 iki 10

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
            nd_suma += p; //paþymiø suma
        }

        asmuo.nd.shrink_to_fit(); //kad elementø skaièius vektoriuje sutaptø su jo dydþiu

        cin.clear(); //iðtriname error flag`us
        cin.ignore(INT_MAX, '\n'); //praignoruojame, kas liko ið neteisingos ávesties


        //jeigu nebuvo ávesta paþymiø
        if (asmuo.nd.empty()) {
            cout << "Neuvo ávesta nei vieno paþymio ðiam studentui." << endl;

            if (x == 'v') {
                cout << "Namø darbø vidurkis bus laikomas 0." << endl;
            }
            else {
                cout << "Namø darbø mediana bus laikoma 0." << endl;
            }

            nd_pask = 0;

        };

        cout << "Áveskite egzamino paþymá: " << endl;
        asmuo.egz = tikrinti_pazymi();
    }

    //skaèiuojame galutiná balà

    //skaièiuojame nd galutiná pagal vidurká
    if (!asmuo.nd.empty()) {    //jeinu paþymiø vektorius nëra tusèias

        //skaièiuojame pagal vidurká
        if (x == 'v') {
                nd_pask = double(nd_suma) / asmuo.nd.size();
         }

        //skaièiuojame nd galutiná pagal medianà
        else {
             sort(asmuo.nd.begin(), asmuo.nd.end());

             if (asmuo.nd.size() % 2 != 0) nd_pask = asmuo.nd[asmuo.nd.size() / 2];
             else nd_pask = (asmuo.nd[asmuo.nd.size() / 2] + asmuo.nd[asmuo.nd.size() / 2 - 1]) / 2; 
         }
    }
    


    asmuo.galutinis = 0.4 * nd_pask + 0.6 * asmuo.egz; //paskaièiuojame galutiná balà

    cout << "Ðio studento duomenys sëkmingai áraðyti" << endl << endl;
}



string tikrinti_vard(int v) {

    if (v == 1) {
        cout << "Áveskite studento vardà:" << endl;
    }
    else {
        cout << endl << "Áveskite studento pavardæ: " << endl;
    }

    string vard;
    getline(cin, vard);

    for (char& c : vard) {
        if (!isalpha(c)) { //Þiûrime, ar raidë
            if (v == 1) {
                cout << endl << "Neteisinga ávestis. Vardas turi bûti tik is raidþiø. Bandykite dar kartà." << endl;
                return tikrinti_vard(1);
            }
            else {
                cout << endl << "Neteisinga ávestis. Pavardë turi bûti tik is raidþiø. Bandykite dar kartà." << endl;
                return tikrinti_vard(2);
            }

        }
    }

    return vard; //reiðkia viskas gerai ir galime naudoti toká varda/pavardæ
}

bool tikrinti_bool() {
    string ivest;
    getline(cin, ivest);
    while (ivest != "0" && ivest != "1") {
        cout << "Neteisinga ávestis. Bandykite dar kartà (áveskite: „0“ arba „1“)." << endl;
        getline(cin, ivest);
    }

    bool x = ivest == "1" ? 1 : 0; //priskiriame 1 arba 0

    return x;
}

int tikrinti_pazymi() {

    int a;
    cin >> a;

    while (a < 0 || a > 10 || cin.fail()) {
        cin.clear(); //iðtriname error flag`us
        cin.ignore(INT_MAX, '\n'); //praignoruojame, kas liko ið neteisingos ávesties
        cout << "Neteisinga ávestis (turi bûti nuo 0 iki 10). Bandykite dar kartà." << endl;
        cin >> a;
    }

    cin.clear();
    cin.ignore(INT_MAX, '\n');

    return a;
}




void spausdinti(char x, vector<studentas>& grupe) {
    //LENTELE
    cout << endl;
    cout << setw(10) << left << "VARDAS";
    cout << setw(15) << left << "PAVARDË";

    if (x == 'v')
        cout << setw(25) << left << "GALUTINIS (vid.)" << endl;
    else
        cout << setw(25) << left << "GALUTINIS (med.)" << endl;

    cout << "------------------------------------------------------------";

    for (int i = 0; i < grupe.size(); i++) asmens_spausdinimas(grupe[i]);

}

void  asmens_spausdinimas(studentas& asmuo) {

    //paverèiame á didþiàsias raides
    asmuo.vardas = didziosios(asmuo.vardas);
    asmuo.pavarde = didziosios(asmuo.pavarde);

    cout << endl;
    cout << setw(10) << left << asmuo.vardas;
    cout << setw(15) << left << asmuo.pavarde;
    cout << setw(15) << left << fixed << setprecision(2) << asmuo.galutinis << endl;

}


string didziosios(string a) {

    for (char& c : a) {
        c = toupper(c);
    }

    return a;
}
