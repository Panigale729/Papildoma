#include "ivest_tikrinimai.h"


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