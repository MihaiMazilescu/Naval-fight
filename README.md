# Naval-fight
Este anul 3241 și încă este nevoie de programatori în federația stelară. Pentru a antrena viitoarele generații de astronauți, în mare secret sunteți membru în echipa care dezvoltă un nou simulator pentru bătăliile navale.

Cerință
Se vor citi de la tastatură informațiile despre navele participante la lupte și apoi comenzile propriu zise. Se va afisa nava cu puterea totala maxima din cele ramase in viata.

Să se creeze o clasă cu numele Spaceship cu următoarele specificații:
Conține trei atribute private: mName de tip șir de caractere (std::string), mAttack, mShield numere întregi (int).
Conține trei constructori publici:
Constructor fără argumente care setează numele navei ca "nedefinit" și puterile la 0
Constructor cu trei argumente (de tip std::string, int și int) care setează cele trei câmpuri.
Constructor de copiere care primeste o alta navă (ca referință constantă) ale cărei date sunt copiate în noul obiect. 
Declară metode individuale de tip getter și setter pentru cele trei câmpuri. Deduceți tipul de date întors și tipul argumentelor. Numele acestora vor fi getName, getAttack, getShield, setName, setAttack, setShield. Funcțiile de tip getter sunt declarate const.
Supraîncarcă următorii operatori (se declară ca membrii ai clasei):
Operatorul "=" primește ca argument o navă sursă (ca referință constantă) și întoarce o navă. Modifică datele obiectului curent (this) și îl întoarce pe acesta.
Operatorul "+=" primește ca argument o navă (ca referință constantă) și întoarce o navă. Puterile navei argument (attack și shield) sunt adăugate la cele ale navei curente.
Operatorul "-=" primește ca argument o navă (ca referință constantă) și întoarce o navă. Scade din puterea defensivă a navei curente puterea ofensivă a navei argument și întoarce nava curentă.
Operatorul "^" primește ca argument o navă (ca referință constantă) si întoarce o navă, pe cea supraviețuitoare. Se apelează astfel:  nava_atacata ^ nava_atacatoare. Aceasta este funcția de luptă propriu zisă, care întoarce nava câștigătoare a bătăliei in starea ei de după luptă. Bătălia are loc în runde până când una din nave rămâne fără scuturi și este distrusă. Fiecare rundă are două etape: nava atacatoare atacă nava atacată (folosiți operatorul "-="). Nava atacată apoi răspunde cu atacul ei, dacă a supraviețuit. Aceasta functie nu modfica parametrii niciuneia din cele 2 nave.
Date de intrare
Pe prima linie se află numărul n reprezentând numărul de nave din flotă. Pe următoarele n linii se află câte o navă definită prin nume, atac și scuturi, separate prin unul sau mai multe spații. Pe linia n+2 se află un număr k ce reprezintă numărul de comenzi iar pe ultimele k linii se află o comandă și nouă nume de nave. Comenzile pot fi "fight" sau "transfer". Comanda transfer va folosi operatorul "+=" iar fight operatorul "^".

Date de ieșire
Se va afișa numele navei ce are cea mai mare putere totala(attack și shield) .

Exemplu:
input:
4
atena 50 500
jupiter 80 100 
zeus 200 200  
hera 200 200
2
fight atena jupiter 
transfer zeus hera

output:
zeus
