#include <stdio.h>
#include "convergence.h"
/*
  Bestimme die längste Zahlenfolge, für die gilt:
    1. n(i+1) = (n(i) % 2) ? 3*n(i)+1 : n(i)/2
    2. n(0) elem [1,...,1000000]
  Jede dieser Zahlenfolgen terminiert mit 1.
  Schreibe n(0) und die Länge der Folge in das übergebene Array zurück.
  Die maximale, erlaubte Laufzeit beträgt 100ms.
  Implementiere die Funktion "convergence(..)" in der Datei "convergence.c".
  Lade diese anschließend im StudIP-VIPS-Modul hoch.
  
  Tipps:
    - Speichere Zwischenergebnisse
    - Definiere ggfs. weitere Funktionen
    - Streiche für die Laufzeitprüfung printf(..)-Aufrufe aus dem Quellcode
*/

int main(void) {
    unsigned int result[2];
    convergence(result);
    printf(" Die laengste Sequenz startet mit %d und ist %d Elemente lang.\n",
        result[0], result[1]);
    return 0;
}