#include "stdnt.h"
#include "ivest_tikrinimai.h"
#include "prad_duom.h"



void rikiavimas(list<studentas>& grupe) {
    auto start = hrclock::now(); // matuosime laika

    grupe.sort(rusiuoti_paz);

    duration diff = hrclock::now() - start;

    cout << "Rikiavimas didejimo tvarka (sort): " << diff.count() << "s" << endl;

}



void skirstymas_2(list<studentas>& grupe, list<studentas>& silpnuciai, list<studentas>& gudruciai) { //studentu skirstymas i du vektorius, istrinant sena
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

    cout << "Studentu dalijimas i dvi grupes, panaikinant pradini list`a: " << diff.count() << "s" << endl;
}

void skirstymas_1(list<studentas>& grupe, list<studentas>& silpnuciai) { //Naujas budas
    auto start = hrclock::now(); // matuosime laika

    for (auto it = grupe.begin(); it != grupe.end(); ) {
        if (it->galutinis_v < 5) {
            silpnuciai.push_back(std::move(*it));
            it = grupe.erase(it);
        }
        else {
            ++it;
        }
    }

    duration diff = hrclock::now() - start;

    cout << "Studentu dalijimas i dvi grupes nauju budu: " << diff.count() << "s" << endl;
}


void galutinis_balas(studentas& asmuo) {
    int nd_suma = accumulate(asmuo.nd.begin(), asmuo.nd.end(), 0);

    double nd_pask_v = double(nd_suma) / asmuo.nd.size(); //vidurkis

    asmuo.galutinis_v = 0.4 * nd_pask_v + 0.6 * asmuo.egz;
}



bool rusiuoti_paz(const studentas& x,const studentas& y) {
    return x.galutinis_v < y.galutinis_v;
}


