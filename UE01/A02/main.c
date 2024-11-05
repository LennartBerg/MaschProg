#include <stdio.h>
#include "printTypes.h"
#include "limits.h"
/*
  Dieses Programm gibt die untere und obere Grenze, sowie die Bitbreite
  aller Ganzzahltypen in einem JSON-Format aus.
  Bearbeite die Datei "printTypes.c" entsprechend und lade diese hoch!
*/

int main(void) {
  char buffer[2048];
  printTypesToJson(buffer);
  puts(buffer);
  return (0);
}