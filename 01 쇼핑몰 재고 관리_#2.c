#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

int main() {
    int n;
    scanf("%d", &n);

    int store[SIZE];
    int sale[SIZE];
    int inventory[SIZE];

    int totalStore = 0, totalSale = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &store[i]);
        totalStore += store[i];
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &sale[i]);
        totalSale += sale[i];
    }

    for (int i = 0; i < n; i++) {
        inventory[i] = store[i] - sale[i];
    }

    printf("재고수량 : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", inventory[i]);
    }
    printf("\n");

    double rate = (double) totalSale / totalStore * 100;
    printf("총 판매량 : %d (판매율 %.2f%%)\n", totalSale, rate);

    int maxSold = sale[0], minSold = sale[0];
    int maxID = 1, minID = 1;
    for (int i = 1; i < n; i++) {
        if (sale[i] > maxSold) {
            maxSold = sale[i];
            maxID = i + 1;
        }
        if (sale[i] < minSold) {
            minSold = sale[i];
            minID = i + 1;
        }
    }
    printf("가장 많이 판매된 상품 : ID %d, 판매량 %d\n", maxID, maxSold);
    printf("가장 적게 판매된 상품 : ID %d, 판매량 %d\n", minID, minSold);

    for (int i = 0; i < n; i++) {
        if (inventory[i] <= 2) {
            printf("상품 ID %d : 재고부족(%d)\n", i + 1, inventory[i]);
        }
    }

    return 0;
}

