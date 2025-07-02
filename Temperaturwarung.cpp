#include <iostream>
#include <limits>
#include <vector>

/*
 * 1. Von der Problemanalyse zur Datendefinition:
 *
 * Identifiziere die Informationen, die dargestellt werden müssen, und lege fest
 * wie sie in der gewählten Programmiersprache als Daten repräsentiert werden.
 *
 * Temperaturwerte: int
 *   Gültiger Wertebereich: [-40; +60]
 *   Ungültige Werte: alles andere
 *   Auslöseschwelle (von plus nach minus): 4
 *   (Rücknahmeschwelle (von minus nach plus):)
 *
 *   char, unsigned char, signed char
 *   ganze Zahlen und Festkommazahlen: signed int, unsigned int
 *   short int, long int, long long int
 *   int8_t
 *   Gleitkommazahlen: float, double, long double
 *     x * 2^y
 *
 *
 * Rückgabewert: {Warning, NoWarning, Invalid}
 *
 ***************************************************************************
 * Warnmeldung (Zeichenkette): std::string
 *   Gültiger Wertebereich: {"Glatteis", ""}
 *
 * IceWarning -> std::string
 *
 * Formuliere entsprechende Datendefinitionen und veranschauliche diese anhand
 * von Beispielen.
 *
 * int temperature1 = -40;
 * int temperature2 = 60;
 *
 * IceWarning warning1 = IceWarning::Warning;
 * IceWarning warning2 = IceWarning::NoWarning;
 * IceWarning warning3 = IceWarning::Invalid;
 *
 * std::string text_warning1 = "Glatteis";
 * std::string nowarning = "";
 *
 */
enum class IceWarning {
  Warning,
  NoWarning,
  Invalid,
};

/*
* IceWarning -> std::string
* Die Eingabe IceWarning soll einen String ausgeben

 * Warnmeldung (Zeichenkette): std::string
 *   Gültiger Wertebereich: {"Glatteis", ""}

* Wenn Warnung, dann string = Glatteis
* Wenn NoWarning, dann string = ""
* Wenn Invaid, dann string = ""
*/


/*
 * 2. Schnittstellendefinition:
 *
 * Ermittle welche Art von Daten die gewünschte Funktion verarbeitet und
 * produziert.
 *
 * Eingabetyp: Temperatur, also int
 * Ausgabetyp: Warnzustand, also IceWarning
 *
 * Formuliere eine prägnante Antwort auf die Frage, was die Funktion berechnet.
 *
 * Welche Wertebereiche der Ein- und Ausgaben sind gültig, welche ungültig und
 * wie verhält sich die Funktion bei ungültiger Eingabe?
 *
 * Erzeugung einer Warnmeldung bei niedrigen Temperaturen, d.h.
 *   - Im Bereich zwischen [-40; +4] Grad Celsius -> IceWarning::Warning
 *   - Im Bereich zwischen ]+4; +60] Grad Celsius -> IceWarning::NoWarning
 *   - Sonst                                      -> IceWarning::Invalid
 *
 * Definiere ein Funktionsgerüst, das zur Signatur passt.
 *
 */
// IceWarning ice_warning(int temperature) {}
std::string ice_warning_to_string(IceWarning warning)  {
  if (warning == IceWarning::Warning) {
    return "Glatteis";
  } else {
    "";
  }
}



/*
IceWarning ice_warning(int temperature) {
  if (temperature < -40) {
    return IceWarning::Invalid;
  } else if (temperature <= 4) {
    return IceWarning::Warning;
  } else if (temperature < 61) {
    return IceWarning::NoWarning;
  } else {
    return IceWarning::Invalid;
  }
}
  */


/*
 * 3. Funktionale Beispiele:
 *
 * Erarbeite konkrete Beispiele für Funktions-Ein- und Ausgaben, die den Zweck
 * der Funktion verdeutlichen.
 *
 * IceWarning warning1 = ice_warning(-40) // IceWarning::Warning
 * IceWarning warning2 = ice_warning(4) // IceWarning::Warning
 * IceWarning warning5 = ice_warning(0) // IceWarning::Warning
 * IceWarning warning4 = ice_warning(5) // IceWarning::NoWarning
 * IceWarning warning3 = ice_warning(60) // IceWarning::NoWarning
 * IceWarning warning6 = ice_warning(-41) // IceWarning::Invalid
 * IceWarning warning7 = ice_warning(61) // IceWarning::Invalid
 *
 */


 /*
 * std::string warning_string1 = ice_warning_to_string(IceWarning::Warning)   // string: "Glatteis"
 * std::string warning_string2 = ice_warning_to_string(IceWarning::NoWarning) // string: ""
 * std::string warning_string3 = ice_warning_to_string(IceWarning::Invalid)   string: ""
 */ 




/*
 * 4. Funktionsvorlage:
 *
 * Übertrage die Datendefinitionen in einen Entwurf der Funktion, der zunächst
 * lediglich einen trivialen Wert zurückliefert.
 *
 */
//IceWarning ice_warning(int temperature) {
//  return IceWarning::Invalid;
//}

/*
 * 5. Funktionsdefinition:
 *
 * Fülle die Lücken in der Funktionsvorlage aus.
 *
 * Nutze dabei die Zweckdefinition und die Beispiele.
 *
 */
 /*
IceWarning ice_warning(int temperature) {
  if (temperature < -40) {
    return IceWarning::Invalid;
  } else if (temperature <= 4) {
    return IceWarning::Warning;
  } else if (temperature < 61) {
    return IceWarning::NoWarning;
  } else {
    return IceWarning::Invalid;
  }
}
*/


/*
 * 6. Testen:
 *
 * Formuliere die Beispiele als Testfälle und stelle sicher, dass die Funktion
 * alle Tests besteht.
 *
 * So entdeckst du Fehler.
 *
 */

 
struct stimulus_response_t {
  int stimulus;
  IceWarning response;
};

int main() {
  stimulus_response_t foo{-40, IceWarning::Warning};
  std::vector<stimulus_response_t> temperatures{
      {-40, IceWarning::Warning},  {4, IceWarning::Warning},
      {0, IceWarning::Warning},    {5, IceWarning::NoWarning},
      {60, IceWarning::NoWarning}, {-41, IceWarning::Invalid},
      {61, IceWarning::Invalid},
  };

  for (stimulus_response_t stimulus_response : temperatures) {
    IceWarning warning = ice_warning(stimulus_response.stimulus);

    std::cout << "ice_warning(" << stimulus_response.stimulus << ") ";
    if (warning == stimulus_response.response) {
      std::cout << "OK";
    } else {
      std::cout << "not OK";
    }
    std::cout << "\n";
  }

  return 0;
}
