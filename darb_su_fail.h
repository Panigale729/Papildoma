#pragma once

#include "mylib.h"
#include "stdnt.h"
#include "prad_duom.h"

//kaip gauname studentu duomenis:
void darbas_su_generuotais(list<studentas>& grupe);	//renkames, ar skaitom is failo, ar ivedam studentus ranka
void darbas_su_paruostais(list<studentas>& grupe);	//skaitome is is anksto paruostu failu
void darbas_su_ivedimu(list<studentas>& grupe);		//vartotojas pats iveda studentus

void skaitymas(string skait_fail, list<studentas>& grupe);      //skaitymas is failo
void spausdinimas(const list<studentas>& grupe, string isvest_fail);  //spausdinimas is failo
void rikiavimas(list<studentas>& grupe);
void skirstymas_2(list<studentas>& grupe, list<studentas>& silpnuciai, list<studentas>& gudruciai); //skirstymas i du vektorius, trinant sena

void istrinti_senus(); //istrinam failu nuo praeito paleidimo