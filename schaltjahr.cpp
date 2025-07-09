#include <vector>
#include <iostream>
/*
 * 1. Von der Problemanalyse zur Datendefinition:
 *
 * Identifiziere die Informationen, die dargestellt werden müssen, und lege fest
 * wie sie in der gewählten Programmiersprache als Daten repräsentiert werden.
 *
 ** Eingabewert: "Jahreszahl" -> Positive ganzzahlige Zahlen
 ** Ausgabewert: "IstSchaltjahr" -> Boolean "0": Kein Schaltjahr, "1" Schaltjahr 
 */


/*
 * 2. Schnittstellendefinition:
 *
 * Ermittle welche Art von Daten die gewünschte Funktion verarbeitet und
 * produziert.
 ** siehe oben
 *
 * Formuliere eine prägnante Antwort auf die Frage, was die Funktion berechnet.
 *
 ** Funktion soll bewerten ob die eingegebene Jahreszahl ein Schaltjahr ist oder nicht.
 * 
 * Welche Wertebereiche der Ein- und Ausgaben sind gültig, welche ungültig und
 * wie verhält sich die Funktion bei ungültiger Eingabe?
 *
 ** Eingabe: Positive ganzzahlige Zahlen größer 0
 ** Rückgabewert: Boolean "false": Kein Schaltjahr, "true" Schaltjahr 
 *
 * Definiere ein Funktionsgerüst, das zur Signatur passt.
 *
 ** Name der Funktion: Ist_Schaltjahr
 ** Parameter: Jahreszahl(), Rückgabewert(bool)
 */



/*
 * 3. Funktionale Beispiele:
 *
 * Erarbeite konkrete Beispiele für Funktions-Ein- und Ausgaben, die den Zweck
 * der Funktion verdeutlichen.

 ** Eingabe Jahreszahl, Ausgabe
 ** (400, true)
 ** (1, false)
 ** (1900, false)
 ** (2024, true)
 ** (1943, false)
 *
 */

/*
 * 4. Funktionsvorlage:
 *
 * Übertrage die Datendefinitionen in einen Entwurf der Funktion, der zunächst
 * lediglich einen trivialen Wert zurückliefert.
 */


/*
 * 5. Funktionsdefinition:
 *
 * Fülle die Lücken in der Funktionsvorlage aus.
 *
 * Nutze dabei die Zweckdefinition und die Beispiele.
 *
 */

bool Ist_Schaltjahr(unsigned int Jahreszahl) {    
    return Jahreszahl % 400 == 0 || (Jahreszahl % 4 == 0 && Jahreszahl % 100 != 0);
}

/*
 * 6. Testen:
 *
 * Formuliere die Beispiele als Testfälle und stelle sicher, dass die Funktion
 * alle Tests besteht.
 *
 * So entdeckst du Fehler.
 ** Eingabe Jahreszahl, Ausgabe
 ** (400, true)
 ** (1, false)
 ** (1900, false)
 ** (2024, true)
 ** (1943, false)
 *
 */

struct schaltjahr_test {
 unsigned int stimulus;
 bool response;
}; 

int main() {
  std::vector<schaltjahr_test> testfaelle{
    {400, true }, 
    {1, false },
    {1900, false },
    {2024, true }, 
    {1943, false },
    {2025, true}  
  };


  for (schaltjahr_test testfall:testfaelle){
    if (Ist_Schaltjahr(testfall.stimulus) == testfall.response) {
      std::cout << "Testfall OK!";
    }
    else {
      std::cout << "Testfall nicht OK!";
    }
    std::cout << "\n";
  }
  return 0;
}