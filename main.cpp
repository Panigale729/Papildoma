#include "mylib.h"
#include "stdnt.h"
#include "ivest_tikrinimai.h"
#include "darb_su_fail.h"
#include "generavimas.h"
#include "prad_duom.h"


int main(){

    //istrinti_senus();

    setlocale(LC_ALL, "Lithuanian"); //�galiname lietuvi�kas raides

    // PROGRAMOS PRAD�IA
    cout << "Paleidote program�, skirt� studento galutiniam balui apskai�iuoti." << endl;
    cout << "Galutinis balas = 0.4 * nam� darb� pa�ymi� vidurkis/mediana + 0.6 * egzamino pa�ymys." << endl << endl;

    //ziurime, ar reikies skaityti studentus is failo, ar vartotojas pats juos ives
    cout << "Ar norite studentus ir j� rezultatus skaityti i� failo?\n";
    cout << "Jeigu norite  - iveskite �1�\n";
    cout << "Jeigu nenorite - iveskite �0�\n";

    bool skaityti;
    skaityti = tikrinti_bool();
    list<studentas> grupe;    //deklaruojame vektoriu grupe

    if (skaityti) {
        cout << "Jeigu norite dirbti su failu generavimu - iveskite �1�\n";
        cout << "Jeigu nenorite dirbti su failais generavimu - iveskite �0�\n";

        bool generuoti;
        generuoti = tikrinti_bool();

        if (generuoti) {
            darbas_su_generuotais(grupe); //dirbam su sugeneruotais failais
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

