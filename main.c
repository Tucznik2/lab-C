#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char randomCharacter() {
    int rl = (rand() % 26) + 'a';
    return (char) rl;
}

void fillTable(char array[], int len) {
    for (int i = 0; i < len; i++) {
        array[i] = randomCharacter();
    }
}

int countOddNumber() {
    int liczba, count = 0;
    do {
        printf("%s", "Wprowadz liczbe: ");
        scanf("%d", &liczba);
        if (liczba % 2 != 0) {
            count += 1;
        }
    } while (liczba != 0);
    return count;
}

void upperChars(char array[], int len) {
    for (int i = 0; i < len; i++) {
        array[i] = toupper(array[i]);
    }
}

float *getMemory(int n) {
    float *x;
    x = (float *) calloc(n, sizeof(float));
    return x;
}

void freeMemory(float *pointer) {
    (void) free(pointer);
}

int maxIndex(float *array, int len) {
    int maxIndex = 0;
    int maxValue = 0;
    for (int i = 0; i < len; i++) {
        if (*(array + i) > maxValue) {
            maxIndex = i;
            maxValue = *(array + i);
        }
    }
    return maxIndex;
}

void defaultOption() {
    printf("Wybrano opcje z poza zakresu\n");
}

void main_menu(int indeks, int rokStudiow) {
    int wybranaOpcja;
    do {
        printf("Program w jezyku C wykonany przez studenta o indeksie nr %d na %d roku studiow\n", indeks, rokStudiow);
        printf("Menu:\n- opcja -1:\n- opcja 1:\n- opcja 2:\n- opcja 3:\nWybierz opcje:");
        scanf("%d", &wybranaOpcja);
        switch (wybranaOpcja) {
            case -1:
                break;
            case 1:
                printf("Uzytkownik wpisal %d liczb nieparzystych\n", countOddNumber());
                break;
            case 2: {
                char tablica[25];
                int len;
                len = sizeof(tablica);
                fillTable(tablica, len);
                for (int i = 0; i < len; i++) {
                    printf("%c\n", tablica[i]);
                }
                upperChars(tablica, len);
                for (int i = 0; i < len; i++) {
                    printf("%c\n", tablica[i]);
                }
            }
                break;
            case 3:
                printf("podaj liczbe elementow: ");
                int len;
                scanf("%d", &len);
                float *pt;
                pt = getMemory(len);
                for (int i = 0; i < len; ++i) {
                    float q;
                    scanf("%f", &q);
                    *(pt + i) = q;
                    printf("%f\n", *(pt + i));
                }
                int max = maxIndex(pt, len);
                printf("Max indeks tablicy: %d\n", max);
                freeMemory(pt);
                break;
            default:
                defaultOption();
        }
    } while (wybranaOpcja != -1);
    printf("Do widzenia!");
}

int main() {
    int indeks = 173654, rokStudiow = 1;
    main_menu(indeks, rokStudiow);
    return 0;
}