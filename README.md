## Projektni zadatak 2022 - Operativni sistemi 1
### Elektrotehnički fakultet u Beogradu
### Katedra za računarsku tehniku i informatiku

## Opis projekta
Ovaj projekat je deo kursa "Operativni sistemi 1" na Elektrotehničkom fakultetu u Beogradu. Cilj projekta je bila realizacija malog, ali funkcionalnog jezgra (kernel) operativnog sistema sa podrškom za niti (multithreaded operating system) i deljenje vremena (time-sharing).

### Realizovane funkcionalnosti:
* Alokator memorije
* Upravljanje nitima
* Semafori
* Asinhrona promena konteksta i preotimanje na prekid od tajmera i tastature

### Arhitektura
Jezgro je implementirano za RISC V procesorsku arhitekturu i školsku računarsku platformu sa ovim procesorom. Koristi se asembler i jezik C/C++ za implementaciju, a jezgro se izvršava u virtuelnom okruženju – emulatoru procesora RISC V.

### Komponente projekta
1. Kernel: Centralni deo operativnog sistema koji obuhvata upravljanje memorijom i nitima.
2. C API: Proceduralan interfejs za sistemske pozive implementiran kao skup funkcija na jeziku C.
3. C++ API: Objektno orijentisan interfejs koji pruža objektni pogled na podržane koncepte.
4. ABI: Binarni interfejs sistemskih poziva koji obezbeđuje prenos argumenata preko registara procesora i prelazak u privilegovani režim rada.
