#pragma once

#include "mylib.h"
#include "stdnt.h"
#include "prad_duom.h"

//kaip gauname studentu duomenis:
void darbas_su_generuotais(deque<studentas>& grupe);	//renkames, ar skaitom is failo, ar ivedam studentus ranka
void darbas_su_paruostais(deque<studentas>& grupe);	//skaitome is is anksto paruostu failu
void darbas_su_ivedimu(deque<studentas>& grupe);		//vartotojas pats iveda studentus

void skaitymas(string skait_fail, deque<studentas>& grupe);      //skaitymas is failo
void spausdinimas(const deque<studentas>& grupe, string isvest_fail);  //spausdinimas is failo
void rikiavimas(deque<studentas>& grupe);
void skirstymas_2(deque<studentas>& grupe, deque<studentas>& silpnuciai, deque<studentas>& gudruciai); //skirstymas i du vektorius, trinant sena

void istrinti_senus(); //istrinam failu nuo praeito paleidimo