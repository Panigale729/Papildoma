#include "mylib.h"
#include "stdnt.h"
#include "ivest_tikrinimai.h"
#include "darb_su_fail.h"


int main()
{
    setlocale(LC_ALL, "Lithuanian"); //Ágaliname lietuviðkas raides

    // PROGRAMOS PRADÞIA
    cout << "Paleidote programà, skirtà studento galutiniam balui apskaièiuoti." << endl;
    cout << "Galutinis balas = 0.4 * namø darbø paþymiø vidurkis/mediana + 0.6 * egzamino paþymys." << endl << endl;

    //ziurime, ar reikies skaityti studentus is failo, ar vartotojas pats juos ives
    cout << "Ar norite studentus ir jø rezultatus skaityti ið failo?\n";
    cout << "Jeigu norite skaityti is failo - iveskite „1“\n";
    cout << "Jeigu nenorite skaityti is failo - iveskite „0“\n";

    string isvest_fail = "kursiokai.txt";

    bool skaityti;
    skaityti = tikrinti_bool();

    vector<studentas> grupe;

    if (skaityti) { //skaitome is failo

        cout << "Pasirinkite studentø failà: " << endl;
        cout << "1. studentai1000000.txt" << endl;
        cout << "2. studentai100000.txt" << endl;
        cout << "3. studentai10000.txt" << endl;
        cout << "Áveskite pasirinkimo numerá: ";

        bool gera_ivest = false;
        int pasirinkimas;

        //tikriname ivesti
        while (!gera_ivest) {

            while (!(cin >> pasirinkimas)) {
                cin.clear(); // pasaliname error flag`us
                cin.ignore(INT_MAX, '\n'); // praignoruojame bloga ivesti
                cout << "Iveskite teisingà pasirinkimo numerá (1-3): ";
            }
            cin.ignore(); // ignoruojame \n

            if (pasirinkimas >= 1 && pasirinkimas <= 3) {
                gera_ivest = true;
            }
            else {
                cout << "Iveskite teisingà pasirinkimo numerá (1-3): ";
            }
        }

        string skait_fail;

        if (pasirinkimas == 1) {
            skait_fail = "studentai1000000.txt";
        }
        else if (pasirinkimas == 2) {
            skait_fail = "studentai100000.txt";
        }
        else if (pasirinkimas == 3) {
            skait_fail = "studentai10000.txt";
        }

        cout << endl << "*Vyksta skaitymas is failo ir isvedimas*\n" << endl;

        try {
            skaitymas(skait_fail, grupe); //skaitymas ir áraðymas vyksta per buffer`á. Is karto pildome studentus.
        }
        catch (const exception& e) {
            cout << "Klaida vykdant programà: " << e.what() << endl;
            return 1;
        }

    }
    else {  //vartotojas pats ivedineja
        try {
            grupe = studentu_pildymas();
        }
        catch (const exception& e) {
            cout << "Klaida vykdant programà: " << e.what() << endl;
            return 1;
        }
    }

    //spausdinimas
    spausdinimas(grupe, isvest_fail);

    cout << endl << "*Programa baigta vykdyti*" << endl;

}