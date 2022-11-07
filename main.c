#include <stdio.h>

void main() {
    int indeks = 173654, rokStudiow = 1, wybranaOpcja, opcje[] = {-1, 1, 2, 3}, isPresent;
    do {
        isPresent = 0;
        printf("Program w jezyku C wykonany przez studenta o indeksie nr %d na %d roku studiow\n", indeks, rokStudiow);
        printf("Menu:\n- opcja -1:\n- opcja 1:\n- opcja 2:\n- opcja 3:\nWybierz opcje:");
        scanf("%d", &wybranaOpcja);
        switch (wybranaOpcja) {
            case -1:
                break;
            case 1:
                printf("Wybrano opcje: %d\n", wybranaOpcja);
                break;
            case 2:
                printf("Wybrano opcje: %d\n", wybranaOpcja);
                break;
            case 3:
                printf("Wybrano opcje: %d\n", wybranaOpcja);
            default:
                printf("Wybrano opcje z poza zakresu\n");
        }
    } while (wybranaOpcja != -1);
    printf("Do widzenia!");
}