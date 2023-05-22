# v0.1

Programos aprašymas:
Programa skirta apskaičiuoti studentų galutinius balus pagal įvestus duomenis.
Galutinis balas = 0.4 * namų darbų vidurkis/mediana + 0.6 egzamino pažymys.
Paleidus programą, vartotojas turi pasirinkti, kaip bus skaičiuojamas pažymys už visus namų darbus - pagal vidurkį ar medianą.
Tada vartotojas pradeda pildyti studentų duomenis:
Studento vardą,
Studento pavardę,
Studento namų darbų pažymius (vartotojas jų gali įvesti kiek tik nori, taip pat jie gali būti generuojami atsitiktinai, jeigu vartotojas to nori),
Studento egzamino pažymį (kursi taip pat gali būti generuojamas atsitiktinai, jeigu vartotojas to nori),
Galiausiai vartotojas renkasi, ar jis nori įvesti kito studento duomenis. Šiuo atveju visas prieš tai minėtų duomenų įvedimas kartojasi iš naujo (vartotojas gali įvesti kiek tik nori studentų).
Vartotojui nusprendus nebeįvedinėti naujų studentų, programa ekrane eilutėmis atvaizduoja kiekvieno studento vardą, pavardę ir galutinį balą šimtųjų tikslumu (su patikslinimu, kaip buvo skaičiuota: ar pagal vidurkį, ar medianą).


Programos veikimas:

Programa realizuota 2 būdais:
1. v0.1 - arrays.
   Studentų įvedimui ir studento namų darbų įvedimui naudoja dinaminškai reguliuojamus masyvus.
2. v0.1 - vectors.
   Studentų įvedimui ir studento namų darbų įvedimui naudoja vektorius. Taip pat naudojami vektorių metodai tokie kaip size() ir t.t.
   
Bet programos veikimo ir funkcijų principas yra lygiais toks pats.


Programos funkcijos:

1. pradzia(): Ši funkcija atvaizduoja pradinį pranešimą vartotojui ir prašo pasirinkti, ar galutinį balą skaičiuoti naudojant vidurkį ar medianą. 
2. studentu_pildymas(char x): Ši funkcija apdoroja studentų duomenų įvedimą. Ji naudoja ciklą, kad leistų vartotojui įvesti kiek tik jis nori studentų.
3. asmens_pildymas(studentas& asmuo, char x): Ši funkcija apdoroja duomenų įvedimą vienam studentui. Ji prašo vartotojo įvesti studento vardą, pavardę, namų darbų pažymius ir egzamino balą. 
  Taip pat teikia galimybę generuoti atsitiktinius namų darbų pažymius (ir jų skaičių). 
  Funkcija skaičiuoja galutinį balą pagal pasirinktą metodą (vidurkį ar medianą) ir priskiria jį studentui.
4. tikrinti_pazymi(): Ši funkcija patikrina ir grąžina vartotojo įvestą pažymį. Patikrinama, ar įvestis yra 0–10 reikšmių srityje.
5. tikrinti_vard(int v): Ši funkcija patikrina ir grąžina vartotojo įvestą vardą. Patikrinama, ar įvestis sudaryta tik iš raidžių.
6. tikrinti_bool(): Ši funkcija patikrina ir grąžina vartotojo įvestą loginę reikšmę. Patikrinama, ar įvestis yra arba '0', arba '1'.
7. spausdinti(char x, vector<studentas>& grupe): Ši funkcija atsakinga už studentų duomenų atspausdinimą. Ji atvaizduoja lentelę su studentų vardais, pavardėmis ir galutiniais balais.
8. asmens_spausdinimas(studentas& asmuo): Atspausdina vieno studento rezultatus.
9. didziosios(string a): Verčia vardo ar pavardės raides į didžiąsias.
  

main() funkcija  
