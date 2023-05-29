# v1.0

Praeitos versijos:

# v0.1

## Programos aprašymas:
   Programa skirta apskaičiuoti studentų galutinius balus pagal įvestus duomenis.
   
   Galutinis balas = 0.4 * namų darbų vidurkis/mediana + 0.6 egzamino pažymys.
   
   Paleidus programą, vartotojas turi pasirinkti, kaip bus skaičiuojamas pažymys už visus namų darbus - pagal vidurkį ar medianą.
   
   
   Tada vartotojas pradeda pildyti studentų duomenis:
   - Studento vardą,
   - Studento pavardę,
   - Studento namų darbų pažymius (vartotojas jų gali įvesti kiek tik nori, taip pat jie gali būti generuojami atsitiktinai, jeigu vartotojas to nori),
   - Studento egzamino pažymį (kursi taip pat gali būti generuojamas atsitiktinai, jeigu vartotojas to nori),
   - Galiausiai vartotojas renkasi, ar jis nori įvesti kito studento duomenis. Šiuo atveju visas prieš tai minėtų duomenų įvedimas kartojasi iš naujo (vartotojas gali įvesti kiek tik nori studentų).
   
   
   Vartotojui nusprendus nebeįvedinėti naujų studentų, programa ekrane eilutėmis atvaizduoja kiekvieno studento vardą, pavardę ir galutinį balą šimtųjų tikslumu (su patikslinimu, kaip buvo skaičiuota: ar pagal vidurkį,      ar medianą).


## Programos veikimas:

   ### Programa realizuota 2 būdais:
   1. ***v0.1 - arrays.***
   
      Studentų įvedimui ir studento namų darbų įvedimui naudoja dinaminškai reguliuojamus masyvus.
      
   2. ***v0.1 - vectors.***
   
      Studentų įvedimui ir studento namų darbų įvedimui naudoja vektorius. Taip pat naudojami vektorių metodai tokie kaip size() ir t.t.
      

   Bet programos veikimo ir funkcijų principas yra lygiais toks pats.
   
# v0.2

## Programos aprašymas (pakeitimai nuo v0.1 versijos):
   - Patobulinas programos veikimas (modernesni atsitikinių skaičių generavimo biblioteka, geriau naudojami vektorių metodai)
   - Vartotojas gali pasirinkti, jog duomenys būtų skaitomi iš failo (vartotojas turi 3 pasirinkimus. Deja, milijono studentų .txt failas netilpo 'Githube'). Iš failo skaitoma į buferį, tada išskirtoma į eilutes ir   kiekvienas eilutės dėmuo paverčiamas į vektoriaus struktūros 'Studentas' atitinkamą dalį.
   - Rezultatai taip pat išvedami į failą, naudojant stringstream visų duomenų suvedimui į viena stringą, o tada išvedama į failą. Taip pat, studentai yra rūšiuojami pagal pavardę ir išvedimo lentelė dinamiškai prisitaiko pagal ilgiausią studentų vardą ir pavardę. Galiausiai, dabar yra išvedamas galutinis balas tiek apgal vidurkį, tiek pagal medianą.
   - Pradėtos naudoti ir tikslios laiko matavimo priemonės (pvz. skaitymui iš failo ir įrašymui į failą).

# v0.3

## Programos aprašymas (pakeitimai nuo v0.2 versijos):
- Pridėtas išimčių valdymas (apsaugojama nuo tuščių įvesties failų ir namų darbų pažymių nebuvimo)
- Programa labiau struktūrizuota (išskaidyta į skirtingus *header ir *.cpp tipo failus)

# v0.4 (pakeitimai nuo v0.3)

**Sukurtas failų generatorius:**
  - Vartotojui pasirinkus, jog jis nori skaityti iš failo - pridėtas pasirinkimas tuos failus generuoti. Sukuriami 5 atsitiktiniai studentų tekstiniai failai: (1000, 10000, 100000, 1000000, 10000000 dydžių)
  - Taip pat tik paleidus programą, visi prieš tai sugeneruoti tekstiniai failai yra ištrinami


**Studentai rūšiuojami į dvi grupes (surūšiuotai išvedami į atskirus failus):**
  - Galutinis balas pagal vidurkį < 5 - „Silpnučiai“
  - Galutinis balas pagal vidurkį >= 5 - „Gudručiai“


**Atlikta programos veikimo spartos analizė (kiekvienam sugeneruotam atsitiktiniam failui):**
  - Atsitiktinio failo sugeneravimo greitis
  - Duomenų nuskaitymo iš failo greitis
  - Studentų rikiavimo greitis didėjimo tvarka (sort)
  - Studentų rūšiavimo į 2 grupes greitis („Silpnučiai“ ir „Gudručiai“)
  - Surūšiuotų studentų išvedimo į 2 naujus failus greitis
  - Visos programos veikimo laikas su šiuo failo dydžiu

|Failo dydis ->                                           |1,000  |10,000  |100,000  |1,000,000  |10,000,000|
|---|---|---|---|---|---|
|Atsitiktinio failo sugeneravimo greitis                   | 0.005 | 0.031 | 0.25 | 2.73 | 26.56 | 
|Duomenų nuskaitymo iš failo greitis                       | 0.004 | 0.032 | 0.31 | 3.26 | 31.86 | 
|Studentų rikiavimo greitis didėjimo tvarka (sort)         | 0.000 | 0.001 | 0.01 | 0.12 | 1.18 | 
|Studentų rūšiavimo į 2 grupes greitis                     | 0.000 | 0.002 | 0.02 | 0.26 | 2.84 | 
|„Gudručių“ išvedimas į failą                              | 0.001 | 0.004 | 0.04 | 0.36 | 3.31 | 
|„Silpnučių“ išvedimas į failą                             | 0.001 | 0.006 | 0.05 | 0.47 | 4.82 | 
|Visos programos veikimo laikas su šiuo failo dydžiu       | 0.020 | 0.084 | 0.70 | 7.21 | 70.77 | 

Laikas duotas sekundėmis. Buvo apvalinama, tai galima paklaida, gaunant visos programos veikimo laiką.

Visos programos veikimo laikas įskaičiuoja kreipamąsi į funkcijas, duomenų perdavimus ir t.t., todėl su mažesniais failais sudedant laiką, jis gali neatitikti.


# v0.5 ataskaita

Matuojama programos sparta panaudojant skirtingų tipų konteinerius.

|| Kont. tipas | 1 000  | 10 000 | 100 000 | 1 000 000 | 10 000 000 |
| --- | --- | --- | --- | --- | --- | --- |
| Nuskaitymas|Vector|0.004|0.032|0.31|3.16|31.10|
||List|0.004|0.031|0.32|3.12|31.28|
||Deque|0.004|0.032|0.32|3.14|34.01|
| Rūšiavimas|Vector|0.000|0.001|0.01|0.12|1.12|
||List|0.000|0.001|0.02|0.52|9.11|
||Deque|0.000|0.002|0.02|0.31|4.06|
| Skirstymas|Vector|0.000|0.002|0.02|0.26|3.08|
||List|0.000|0.002|0.03|0.26|2.85|
||Deque|0.000|0.002|0.02|0.29|3.45|

Laikas duotas sekundėmis. Laikas buvo apvalinamas (tūkstantųjų arba šimtųjų tikslumu).

Testavimo sistemos parametrai:

CPU: AMD Ryzen 5 5625U with Radeon Graphics (6 branduoliai (12 loginių), 2.3 GHz)

RAM: 16 GB (3200 MHz)

SSD: 512 GB SAMSUNG MZVLQ512HBLU-00BH1


# v1.0

Optimizuota studentų rūšiavimo (dalijimo) į dvi kategorijas ("silpnučių" ir "gudručių") realizacija:
t.y. visiems trims konteinerių tipams (vector, list ir deque) išmatuota programos veikimo sparta
priklausomai nuo studentų dalijimo į dvi kategorijas strategijos:

 - 1 strategija: Bendro studentai konteinerio (vector, list ir deque tipų)
skaidymas (rūšiavimas) į du naujus to paties tipo konteinerius: "silpnučius" ir "gudručius".

 - 2 strategija: Bendro studentų konteinerio (vector, list ir deque) skaidymas (rūšiavimas)
panaudojant tik vieną naują konteinerį: "silpnučiai".

Skirstymo į 2 grupes rezultatai:

| Kont. tipas | Strategija | 1 000  | 10 000 | 100 000 | 1 000 000 | 10 000 000 |
|--- | --- | --- | --- | --- | --- | --- |
|Vector|1 str.|0.000|0.002|0.02|0.26|3.08|
||2 str.|0.003|0.227|23.26|-|-|
|List|1 str.|0.000|0.002|0.03|0.26|2.85|
||2 str.|0.000|0.000|0.01|0.14|1.64|
|Deque|1 str.|0.000|0.002|0.02|0.29|3.45|
||2 str.|9.7e-05|0.001387|0.006499|0.062924|0.728491|





