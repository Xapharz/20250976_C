#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int store[100];
    int sale[100];
    int inventory[100];

    for (int i = 0; i < n; i++) {
        scanf("%d", &store[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &sale[i]);
    }

    for (int i = 0; i < n; i++) {
        inventory[i] = store[i] - sale[i];
    }

    int id;
    scanf("%d", &id);

    printf("%d\n", inventory[id - 1]);

    for (int i = 0; i < n; i++) {
        printf("%d ", inventory[i]);
    }

    return 0;
}
