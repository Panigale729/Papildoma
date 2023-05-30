#include "generavimas.h"
#include "mylib.h"


//failu pavadinimai
vector<string> input_files = {
    "txt_failai/studentai1k.txt",
    "txt_failai/studentai10k.txt",
    "txt_failai/studentai100k.txt",
    "txt_failai/studentai1M.txt",
    "txt_failai/studentai10M.txt",
};

vector<string> output_files = {
    "txt_failai/studentai1k_rez.txt",
    "txt_failai/studentai10k_rez.txt",
    "txt_failai/studentai100k_rez.txt",
    "txt_failai/studentai1M_rez.txt",
    "txt_failai/studentai10M_rez.txt",
};

vector<string> sorted = {
    "txt_failai/studentai1k_sort.txt",
    "txt_failai/studentai10k_sort.txt",
    "txt_failai/studentai100k_sort.txt",
    "txt_failai/studentai1M_sort.txt",
    "txt_failai/studentai10M_sort.txt",
};

vector<string> silpnuciai_out = {
    "txt_failai/silpniukai1k_rez.txt",
    "txt_failai/silpniukai10k_rez.txt",
    "txt_failai/silpniukai100k_rez.txt",
    "txt_failai/silpniukai1M_rez.txt",
    "txt_failai/silpniukai10M_rez.txt",
};

vector<string> gudruciai_out = {
    "txt_failai/gudruciai1k_rez.txt",
    "txt_failai/gudruciai10k_rez.txt",
    "txt_failai/gudruciai100k_rez.txt",
    "txt_failai/gudruciai1M_rez.txt",
    "txt_failai/gudruciai10M_rez.txt",
};


void generavimas(string& write_vardas, long long int& n) { //sgeneruojam viena faila
    auto start = hrclock::now();

    ofstream out_f(write_vardas);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 10);

    //Antraste isvedimo
    //----------------------------------------------------------------------------
    out_f << left << setw(20) << "Vardas" << setw(20) << "Pavarde";
    for (int i = 1; i < 11; ++i)
        out_f << setw(7) <<"ND" + to_string(i) + "\t";
    out_f << "Egz.\n";
    //----------------------------------------------------------------------------

    for (int i = 1; i < n + 1; i++) {
        out_f << left << setw(20) << "Vardas" + to_string(i)
            << setw(20) << "Pavarde" + to_string(i);
        for (int j = 0; j < 11; ++j) {
            out_f << setw(5) << dist(gen) << "\t";
        }
        if (i != n) out_f << "\n";
    }
    out_f.close();

    auto end = hrclock::now();

    duration diff = end - start;
    diff = end - start; // Skirtumas (s)
    cout << "Failo sugeneravimo laikas: " << diff.count() << " s\n";
}