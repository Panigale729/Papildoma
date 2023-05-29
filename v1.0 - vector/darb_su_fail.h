#pragma once

#include "mylib.h"
#include "stdnt.h"
#include "prad_duom.h"

//kaip gauname studentu duomenis:
//void darbas_su_generuotais(vector<studentas>& grupe);	//renkames, ar skaitom is failo, ar ivedam studentus ranka
void darbas_su_paruostais(vector<studentas>& grupe);	//skaitome is is anksto paruostu failu
void darbas_su_ivedimu(vector<studentas>& grupe);		//vartotojas pats iveda studentus

void skaitymas(string skait_fail, vector<studentas>& grupe);      //skaitymas is failo
void spausdinimas(const vector<studentas>& grupe, string isvest_fail);  //spausdinimas is failo
void rikiavimas(vector<studentas>& grupe);
void skirstymas_2(vector<studentas>& grupe, vector<studentas>& silpnuciai, vector<studentas>& gudruciai); //skirstymas i du vektorius, trinant sena
void skirstymas_1(vector<studentas>& grupe, vector<studentas>& silpnuciai); //nauju budu

void istrinti_senus(); //istrinam failu nuo praeito paleidimo