#include "darb_su_fail.h"
#include "mylib.h"
#include "generavimas.h"
#include "ivest_tikrinimai.h"
#include "prad_duom.h"

#include <string>
#include <vector>
#include <algorithm>
#include <execution>


void istrinti_senus() {
    for (const auto& file : input_files) {
        remove(file.c_str());
    }

    for (const auto& file : output_files) {
        remove(file.c_str());
    }

    for (const auto& file : sorted) {
        remove(file.c_str());
    }

    for (const auto& file : silpnuciai_out) {
        remove(file.c_str());
    }

    for (const auto& file : gudruciai_out) {
        remove(file.c_str());
    }

    remove("kursiokai.txt");

    cout << "Pries tai sukurti failai sekmingai istrinti" << endl;

    system("pause");
}



void skaitymas(string skait_fail, list<studentas>& grupe) {
    auto start = hrclock::now();

    ifstream open_f(skait_fail);
    if (!open_f.is_open()) {
        throw runtime_error("Nepavyko atidaryti failo.");
    }

    string first_line;
    getline(open_f, first_line);

    string line;


    try {
        while (getline(open_f, line)) {
            studentas asmuo;

            istringstream ss(line);
            std:: istream_iterator<string> begin(ss);
            std:: istream_iterator<string> end;
            vector<string> vstrings(begin, end);

            asmuo.vardas = vstrings[0];
            asmuo.pavarde = vstrings[1];

            for (int i = 2; i < vstrings.size() - 1; i++) {
                asmuo.nd.push_back(stoi(vstrings[i]));
            }

            asmuo.egz = stoi(vstrings.back());
            asmuo.nd.pop_back();

            if (asmuo.nd.empty()) {
                throw runtime_error("Studento " + asmuo.vardas + " " + asmuo.pavarde + " namø darbø paþymiø nëra.");
            }

            galutinis_balas(asmuo);

            grupe.emplace_back(std::move(asmuo)); 
        }

        open_f.close();


    }
    catch (exception& e) {
        throw runtime_error("Klaida apdorojant failo duomenis: " + string(e.what()));
    }

    duration diff = hrclock::now() - start;
    cout << "Failo nuskaitymas: " << diff.count() << " s\n";

}



void spausdinimas(const list<studentas>& grupe, string isvest_fail) {
    auto start = hrclock::now(); // matuosime laika

    stringstream output{};

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
    output << setw(20) << left << "GALUTINIS (vid.)" << endl;
    //output << setw(20) << left << "GALUTINIS (med.)" << endl;
    output << string(maxVardasLength + 2, '-');
    output << string(maxPavardeLength + 2, '-');
    output << "-----------------------------------------" << endl;

    for (const auto& asmuo : grupe) {
        output << setw(maxVardasLength + 2) << left << asmuo.vardas;
        output << setw(maxPavardeLength + 2) << left << asmuo.pavarde;
        output << setw(20) << left << fixed << setprecision(2) << asmuo.galutinis_v;
        //output << setw(20) << left << fixed << setprecision(2) << asmuo.galutinis_m;
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
    //cout << "duomenu isvedimas faila uztruko: " << diff.count() << " s\n";
}



