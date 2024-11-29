#include "friends.h"

#include <math.h>
#include <stdio.h>

unsigned int sumFriends(friend_t friends[], unsigned int size, unsigned int buffer[], unsigned int max) {
    unsigned int sum = 0;
    int i_friends = 0;
    // Alle Zahlen haben mindestens den Teiler 1
    for (int i = 0; i < max; i++) {
        buffer[i] = 1;
    }
    // Anstatt für jede Zahl die Teiler einzeln zu ermitteln, addieren wir
    // einfach den Teiler auf alle Teiler-Summen der Vielfachen. Der
    // größtmögliche Teiler ist die Hälfte von max.
    // i: Teiler
    for (int i = 2; i < max / 2; i++) {
        int d = i + i;  // erstes Vielfaches
        while (d < max) {
            buffer[d - 1] += i;  // index 0 ist Zahl 1
            d += i;              // nächstes Vielfaches
        }
    }
    // Suche alle Freunde in der Liste von Summen
    for (int a = 1; a <= max; a++) {
        int b = buffer[a - 1];
        // Wir prüfen ob b < a, damit wir Freunde nicht doppelt finden und da
        // a ungleich b sein muss. Außerdem sichern wir uns damit gegen indexe
        // größer als max ab.
        if (b < a && buffer[b - 1] == a) {
            friends[i_friends].a = a;
            friends[i_friends].b = b;
            i_friends++;
            friends[i_friends].a = b;
            friends[i_friends].b = a;
            i_friends++;
            sum += a + b;
        }
    }

    return sum;
}