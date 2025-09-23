#include <stdio.h>

#define PRODUCT_COUNT 5

int main() {
    int inventory[PRODUCT_COUNT] = {0};
    int store[PRODUCT_COUNT] = {0};
    int sale[PRODUCT_COUNT] = {0};

    int menu, product, subMenu, q;

    while (1) {
        printf("\n[쇼핑몰 관리 프로그램]\n");
        printf("원하는 메뉴를 선택하세요.(1. 입고, 2. 판매, 3. 상품현황, 4. 종료)\n");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("(출력)입고수량 입력 : 전체 상품 입고수량 입력 1, 개별 상품 입력 2를 선택\n");
                scanf("%d", &subMenu);
                if (subMenu == 1) {
                    for (int i = 0; i < PRODUCT_COUNT; i++) {
                        scanf("%d", &q);
                        store[i] += q;
                        inventory[i] += q;
                    }
                } else if (subMenu == 2) {
                    printf("(입력)상품ID : ");
                    scanf("%d", &product);
                    if (product < 1 || product > PRODUCT_COUNT) {
                        printf("잘못된 상품 번호입니다.\n");
                        break;
                    }
                    printf("(출력)입고수량 : ");
                    scanf("%d", &q);
                    store[product - 1] += q;
                    inventory[product - 1] += q;
                } else {
                    printf("잘못된 선택입니다.\n");
                }
                break;

            case 2:
                printf("(출력)판매수량 입력 : 전체 상품 판매수량 입력 1, 개별 상품 입력 2를 선택\n");
                scanf("%d", &subMenu);
                if (subMenu == 1) {
                    for (int i = 0; i < PRODUCT_COUNT; i++) {
                        scanf("%d", &q);
                        if (q > inventory[i]) {
                            printf("상품 %d 재고 부족! 현재 재고: %d\n", i + 1, inventory[i]);
                            q = inventory[i];
                        }
                        sale[i] += q;
                        inventory[i] -= q;
                    }
                } else if (subMenu == 2) {
                    printf("(출력)상품ID : ");
                    scanf("%d", &product);
                    if (product < 1 || product > PRODUCT_COUNT) {
                        printf("잘못된 상품 번호입니다.\n");
                        break;
                    }
                    printf("(출력)판매수량 : ");
                    scanf("%d", &q);
                    if (q > inventory[product - 1]) {
                        printf("재고 부족! 현재 재고: %d\n", inventory[product - 1]);
                        q = inventory[product - 1];
                    }
                    sale[product - 1] += q;
                    inventory[product - 1] -= q;
                } else {
                    printf("잘못된 선택입니다.\n");
                }
                break;

            case 3: {
                printf("\n재고수량 : ");
                for (int i = 0; i < PRODUCT_COUNT; i++) {
                    printf("%d ", inventory[i]);
                }
                printf("\n");

                int total_sale = 0, total_store = 0;
                for (int i = 0; i < PRODUCT_COUNT; i++) {
                    total_sale += sale[i];
                    total_store += store[i];
                }

                printf("총 판매량 : %d ", total_sale);
                if (total_store > 0)
                    printf("(판매율 %.2f%%)\n", (double)total_sale / total_store * 100.0);
                else
                    printf("(판매율 0%%)\n");

                int maxID = 0, minID = 0;
                for (int i = 1; i < PRODUCT_COUNT; i++) {
                    if (sale[i] > sale[maxID]) maxID = i;
                    if (sale[i] < sale[minID]) minID = i;
                }
                printf("가장 많이 판매된 상품 : ID %d, 판매량 %d\n", maxID + 1, sale[maxID]);
                printf("가장 적게 판매된 상품 : ID %d, 판매량 %d\n", minID + 1, sale[minID]);

                for (int i = 0; i < PRODUCT_COUNT; i++) {
                    if (inventory[i] <= 2) {
                        printf("상품 ID %d : 재고부족(%d)\n", i + 1, inventory[i]);
                    }
                }

                break;
            }

            case 4:
                printf("프로그램을 종료합니다.\n");
                return 0;

            default:
                printf("잘못된 메뉴 선택입니다.\n");
        }
    }
}
