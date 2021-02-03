#include<stdio.h>
#include <stdlib.h>
#include"ListaDwukierunkowa.h"

int main() {
    int dec, val, pos;
    int active = 1;
    while(active==1){
        printf("Co chcesz zrobic?\n[1] Dodaj element na koniec listy\n[2] Dodaj element na poczatek listy\n[3] Dodaj element w srodek listy\n[4] Usun wartosc\n[5] Wypisz od poczatku\n[6] Wypisz od konca\n[7] Zakoncz program\n");
        scanf("%d", &dec);
        switch(dec) {
            case 1:
                printf("Podaj liczbe: \n");
                scanf("%d", &val);
                addTail(val);
                break;
            case 2:
                printf("Podaj liczbe: \n");
                scanf("%d", &val);
                addHead(val);
                break;
            case 3:
                printf("Podaj liczbe: \n");
                scanf("%d", &val);
                printf("Podaj pozycje: \n");
                scanf("%d", &pos);
                addMiddle(val, pos);
                break;
            case 4:
                printf("Podaj liczbe: \n");
                scanf("%d", &val);
                delValue(val);
                break;
            case 5:
                printFromBeginning();
                break;
            case 6:
                printFromEnd();
                break;
            case 7:
                active = 0;
                break;
        }

    }

}

