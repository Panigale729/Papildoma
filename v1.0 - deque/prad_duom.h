#pragma once

#include "mylib.h"
#include "stdnt.h"

//kaip gauname studentu duomenis:
void darbas_su_generuotais(deque<studentas>& grupe, bool skirstymas);	//renkames, ar skaitom is failo, ar ivedam studentus ranka
void darbas_su_paruostais(deque<studentas>& grupe);	//skaitome is is anksto paruostu failu
void darbas_su_ivedimu(deque<studentas>& grupe);	//vartotojas pats iveda studentus
