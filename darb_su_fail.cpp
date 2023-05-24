#include "darb_su_fail.h"
#include "mylib.h"

#include <string>
#include <vector>
#include <algorithm>

void skaitymas(string skait_fail, vector<studentas>& grupe) {
    stringstream my_buffer;

    auto start = hrclock::now(); //matuosime laika

    ifstream open_f(skait_fail); //jeigu nepavyko atidaryti failo
    if (!open_f.is_open()) {
        throw runtime_error("Nepavyko atidaryti failo.");
    }

    string first_line;
    getline(open_f, first_line); // nuskaitome ir praignoruojame pirma eilute

    my_buffer << open_f.rdbuf(); //viskas buferyje
    open_f.close(); //nebereikia failo, galime uzdaryti

    duration diff = hrclock::now() - start;
    cout << "Failo nuskaitymas á buferá uþtruko: " << diff.count() << " s\n";

    start = hrclock::now();
    string line;

    try {
        while (getline(my_buffer, line)) { //imame is buferio po eilute ir pildom 'asmuo'
            studentas asmuo;
            istringstream iss(line);
            iss >> asmuo.vardas >> asmuo.pavarde;

            int pazymys;
            while (iss >> pazymys) {    //kol skaicius int, tol nuskaitys
                asmuo.nd.push_back(pazymys);
            }

            asmuo.egz = asmuo.nd.back();    //kadangi nuskaiteme visus skaicius i pazymiu vektoriu
            asmuo.nd.pop_back();

            if (asmuo.nd.empty()) {
                throw runtime_error("Studento " + asmuo.vardas + " " + asmuo.pavarde + " namø darbø paþymiø nëra.");
            }

            galutinis_balas(asmuo);

            grupe.push_back(asmuo);         //pridedam i vektoriu grupe uzpildytus asmens duomenis

        }
    }
    catch (exception& e) {
        throw runtime_error("Klaida apdorojant failo duomenis: " + string(e.what()));
    }

    diff = hrclock::now() - start;
    cout << "\nBuferio padalijimas á eiluèiø vektoriø ir \nvektoriaus <studentas> uþpildymas truko (su galutinio balo paskaiciavimu): " << diff.count() << " s\n";

}



void spausdinimas(vector<studentas>& grupe, string isvest_fail) {

    auto start = hrclock::now(); // matuosime laika

    sort(grupe.begin(), grupe.end(), rusiuoti_pavard);

    stringstream output;

    size_t maxVardasLength = 6;  // "VARDAS"
    size_t maxPavardeLength = 8; // "PAVARDË"
    for (const auto& asmuo : grupe) {
        maxVardasLength = max(maxVardasLength, asmuo.vardas.length());
        maxPavardeLength = max(maxPavardeLength, asmuo.pavarde.length());
    }

    // Ivedam viska i outputa (i viena stringa)
    output << endl;
    output << setw(maxVardasLength + 2) << left << "VARDAS";
    output << setw(maxPavardeLength + 2) << left << "PAVARDË";
    output << setw(20) << left << "GALUTINIS (vid.)";
    output << setw(20) << left << "GALUTINIS (med.)" << endl;
    output << string(maxVardasLength + 2, '-');
    output << string(maxPavardeLength + 2, '-');
    output << "-----------------------------------------" << endl;

    for (const auto& asmuo : grupe) {
        output << setw(maxVardasLength + 2) << left << asmuo.vardas;
        output << setw(maxPavardeLength + 2) << left << asmuo.pavarde;
        output << setw(20) << left << fixed << setprecision(2) << asmuo.galutinis_v;
        output << setw(20) << left << fixed << setprecision(2) << asmuo.galutinis_m;
        output << endl;
    }


    // isvedame i faila
    ofstream f_out(isvest_fail);
    if (!f_out.is_open()) {
        cout << "Nepavyko atidaryti isvesties failo." << endl;
        return;
    }
    f_out << output.str(); // irasome i faila duomenis
    f_out.close();

    duration diff = hrclock::now() - start;
    cout << endl << "Duomenu isvedimas uztruko + rusiavimas: " << diff.count() << " s\n";
}
