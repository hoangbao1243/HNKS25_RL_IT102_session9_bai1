#include <stdio.h>
#include <string.h>

struct VeMayBay {
    char maPNR[10];
    char tenHanhKhach[50];
    char hangVe[15];
    float trongLuongHanhLy;
    long phiPhuThu;
};

int main() {
    struct VeMayBay ve[50];
    int n, i, found = 0;
    char pnr[10];

    do {
        printf("Nhap so luong ve (1 - 50): ");
        scanf("%d", &n);
        while (getchar() != '\n');
    } while (n < 1 || n > 50);

    for (i = 0; i < n; i++) {
        printf("\n--- Nhap thong tin ve thu %d ---\n", i + 1);

        printf("Nhap ma PNR: ");
        fgets(ve[i].maPNR, sizeof(ve[i].maPNR), stdin);
        ve[i].maPNR[strcspn(ve[i].maPNR, "\n")] = '\0';

        printf("Nhap ho ten hanh khach: ");
        fgets(ve[i].tenHanhKhach, sizeof(ve[i].tenHanhKhach), stdin);
        ve[i].tenHanhKhach[strcspn(ve[i].tenHanhKhach, "\n")] = '\0';

        printf("Nhap hang ve: ");
        fgets(ve[i].hangVe, sizeof(ve[i].hangVe), stdin);
        ve[i].hangVe[strcspn(ve[i].hangVe, "\n")] = '\0';

        printf("Nhap trong luong hanh ly (kg): ");
        scanf("%f", &ve[i].trongLuongHanhLy);
        while (getchar() != '\n');

        if (ve[i].trongLuongHanhLy > 7)
            ve[i].phiPhuThu = (long)((ve[i].trongLuongHanhLy - 7) * 50000);
        else
            ve[i].phiPhuThu = 0;
    }

    printf("\n=== DANH SACH VE MAY BAY ===\n");
    printf("%-5s %-10s %-25s %-12s %-12s %-15s\n",
           "STT", "MA PNR", "HO TEN", "HANG VE", "HANH LY", "PHI PHU THU");

    for (i = 0; i < n; i++) {
        printf("%-5d %-10s %-25s %-12s %-12.1f %-15ld\n",
               i + 1, ve[i].maPNR, ve[i].tenHanhKhach,
               ve[i].hangVe, ve[i].trongLuongHanhLy, ve[i].phiPhuThu);
    }

    printf("\n=== CAP NHAT THONG TIN HANH LY ===\n");
    printf("Nhap ma PNR can cap nhat: ");
    fgets(pnr, sizeof(pnr), stdin);
    pnr[strcspn(pnr, "\n")] = '\0';

    for (i = 0; i < n; i++) {
        if (strcmp(ve[i].maPNR, pnr) == 0) {
            found = 1;

            printf("Tim thay ve cua hanh khach: %s\n", ve[i].tenHanhKhach);
            printf("Nhap trong luong hanh ly moi (kg): ");
            scanf("%f", &ve[i].trongLuongHanhLy);

            if (ve[i].trongLuongHanhLy > 7)
                ve[i].phiPhuThu = (long)((ve[i].trongLuongHanhLy - 7) * 50000);
            else
                ve[i].phiPhuThu = 0;

            printf("Cap nhat thanh cong! Phi phu thu moi: %ld VND\n",
                   ve[i].phiPhuThu);
            break;
        }
    }

    if (!found)
        printf("Khong tim thay ma PNR hop le!\n");
    else {
        printf("\n=== DANH SACH VE MAY BAY SAU CAP NHAT ===\n");
        printf("%-5s %-10s %-25s %-12s %-12s %-15s\n",
               "STT", "MA PNR", "HO TEN", "HANG VE", "HANH LY", "PHI PHU THU");

        for (i = 0; i < n; i++) {
            printf("%-5d %-10s %-25s %-12s %-12.1f %-15ld\n",
                   i + 1, ve[i].maPNR, ve[i].tenHanhKhach,
                   ve[i].hangVe, ve[i].trongLuongHanhLy, ve[i].phiPhuThu);
        }
    }

    return 0;
}