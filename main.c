#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char fillTable(char *array, int len) {
    char q;
    for (int i = 0; i < len; i++) {
        scanf(" %c", &q);
        *(array + i) = q;
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

void upperChars(char *array, int len) {
    for (int i = 0; i < len; i++) {
        *(array + i) = toupper(*(array + i));
    }
}

float *getMemory(int n) {
    float *x;
    x = (float *) calloc(n, sizeof(float));
    return x;
}

char *getMemoryC(int n) {
    char *x = (char *) malloc(n * sizeof(char));
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
                char *pt;
                int len;
                scanf("%d", &len);
                pt = getMemoryC(len);
                fillTable(pt, len);
                for (int i = 0; i < len; i++) {
                    printf("%c\n", *(pt + i));
                }
                upperChars(pt, len);
                for (int i = 0; i < len; i++) {
                    printf("%c\n", *(pt + i));
                }
                (void) free(pt);
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