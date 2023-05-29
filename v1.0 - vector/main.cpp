#include "mylib.h"
#include "stdnt.h"
#include "ivest_tikrinimai.h"
#include "darb_su_fail.h"
#include "generavimas.h"
#include "prad_duom.h"


int main(){

    //istrinti_senus();

    setlocale(LC_ALL, "Lithuanian"); //Ágaliname lietuviðkas raides

    // PROGRAMOS PRADÞIA
    cout << "Paleidote programà, skirtà studento galutiniam balui apskaièiuoti." << endl;
    cout << "Galutinis balas = 0.4 * namø darbø paþymiø vidurkis/mediana + 0.6 * egzamino paþymys." << endl << endl;

    //ziurime, kai pvartotojas nores rusiuoti studentus
    cout << "Kokiu budu skirstyti studentus i grupes?\n";
    cout << "Senu budu: perkelti gudrucius ir silpnucius i atskirus failus - iveskite „1“\n";
    cout << "Nauju budu: tik silpnucius iskelti i atskira faila - iveskite „0“\n";

    bool skirstymas;
    skirstymas = tikrinti_bool();


    //ziurime, ar reikies skaityti studentus is failo, ar vartotojas pats juos ives
    cout << "Ar norite studentus ir jø rezultatus skaityti ið failo?\n";
    cout << "Jeigu norite  - iveskite „1“\n";
    cout << "Jeigu nenorite - iveskite „0“\n";

    bool skaityti;
    skaityti = tikrinti_bool();
    vector<studentas> grupe;    //deklaruojame vektoriu grupe

    if (skaityti) {

        cout << "Jeigu norite dirbti su failu generavimu - iveskite „1“\n";
        cout << "Jeigu nenorite dirbti su failu generavimu - iveskite „0“\n";

        bool generuoti;
        generuoti = tikrinti_bool();

        if (generuoti) {
            darbas_su_generuotais(grupe, skirstymas); //dirbam su sugeneruotais failais
        }
        else {
            darbas_su_paruostais(grupe); //dirbam su is anksto paruostais failais
        }
    }
    else {
        darbas_su_ivedimu(grupe); //dirbam su vartotojo ivedamais duomenimis
    }
    

    cout << endl << "*Programa baigta vykdyti*" << endl;

}

