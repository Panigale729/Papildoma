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

Visos programos veikimo laikas su šiuo failu įskaičiuoja kreipamąsi į funkcijas, duomenų perdavimus ir t.t., todėl su mažesniais failais sudedant laiką, jis gali neatitikti.
