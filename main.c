#include <stdio.h>

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

void secondOption(int wybranaOpcja);

void thirdOption(int wybranaOpcja);

void defaultOption() {
    printf("Wybrano opcje z poza zakresu\n");
}

int main_menu(int indeks, int rokStudiow) {
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
            case 2:
                secondOption(wybranaOpcja);
                break;
            case 3:
                thirdOption(wybranaOpcja);
            default:
                defaultOption();
        }
    } while (wybranaOpcja != -1);
    printf("Do widzenia!");
}

void main() {
    int indeks = 173654, rokStudiow = 1, wybranaOpcja;
    main_menu(indeks, rokStudiow);

}