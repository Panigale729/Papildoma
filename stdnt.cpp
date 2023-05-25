#include "stdnt.h"
#include "ivest_tikrinimai.h"
#include "prad_duom.h"



void rikiavimas(vector<studentas>& grupe) {
    auto start = hrclock::now(); // matuosime laika

    sort(grupe.begin(), grupe.end(), rusiuoti_paz);

    duration diff = hrclock::now() - start;

    cout << "Rikiavimas didejimo tvarka (sort): " << diff.count() << "s" << endl;

}



void skirstymas_2(vector<studentas>& grupe, vector<studentas>& silpnuciai, vector<studentas>& gudruciai) { //studentu skirstymas i du vektorius, istrinant sena
    auto start = hrclock::now(); // matuosime laika

    for (const auto& asmuo : grupe) {
        if (asmuo.galutinis_v < 5) {
            silpnuciai.push_back(asmuo);
        }
        else {
            gudruciai.push_back(asmuo);
        }
    }

    duration diff = hrclock::now() - start;

    cout << "Studentu dalijimas i dvi grupes, panaikinant pradini vektoriu: " << diff.count() << "s" << endl;
}



void galutinis_balas(studentas& asmuo) {
    int nd_suma = accumulate(asmuo.nd.begin(), asmuo.nd.end(), 0);

    double nd_pask_v = double(nd_suma) / asmuo.nd.size(); //vidurkis

    asmuo.galutinis_v = 0.4 * nd_pask_v + 0.6 * asmuo.egz;
}



bool rusiuoti_paz(studentas& x, studentas& y) {
    return x.galutinis_v < y.galutinis_v;
}


