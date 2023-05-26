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
