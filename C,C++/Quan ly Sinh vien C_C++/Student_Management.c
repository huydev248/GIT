#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#define MAX 100

struct SinhVien {
    int id;
    char ten[30];
    char gioiTinh[5];
    int tuoi;
    float diemToan;
    float diemLy;
    float diemHoa;
    float diemTB;
    char hocluc[10];
};

typedef struct SinhVien SV;

void printLine(int n);
int idLonNhat(SV a[], int n);
void nhapThongTinSV(SV* sv, int id);
void nhapSV(SV a[], int id, int n);
void CapNhatThongTinSV(SV* sv);
void CapNhatSV(SV a[], int id, int n);
int xoaTheoID(SV a[], int id, int n);
void timKiemTheoTen(SV a[], char ten[], int n);
void tinhDTB(SV* sv);
void xeploai(SV* sv);
void sapxeptheoDTB(SV a[], int n);
void sapxeptheoTen(SV a[], int n);
void showStudent(SV a[], int n);
int docFile(SV a[], char fileName[]);
void ghiFile(SV a[], int n, char fileName[]);
void pressAnyKey();

int main() {
    int key;
    char fileName[] = "sinhvien.txt";
    SV arraySV[MAX];
    int soluongSV = 0;
    int idCount = 0;

    // nhap danh sach sinh vien tu file
    soluongSV = docFile(arraySV, fileName);
    idCount = idLonNhat(arraySV, soluongSV);

    while (true) {
        printf("CHUONG TRINH QUAN LY SINH VIEN C/C++\n");
        printf("*************************MENU**************************\n");
        printf("**  1. Them sinh vien.                               **\n");
        printf("**  2. Cap nhat thong tin sinh vien boi ID.          **\n");
        printf("**  3. Xoa sinh vien boi ID.                         **\n");
        printf("**  4. Tim kiem sinh vien theo ten.                  **\n");
        printf("**  5. Sap xep sinh vien theo diem trung binh (GPA). **\n");
        printf("**  6. Sap xep sinh vien theo ten.                   **\n");
        printf("**  7. Hien thi danh sach sinh vien.                 **\n");
        printf("**  8. Ghi danh sach sinh vien vao file.             **\n");
        printf("**  0. Thoat                                         **\n");
        printf("*******************************************************\n");
        printf("Nhap tuy chon: ");
        scanf("%d", &key);
        switch (key) {
        case 1:
            printf("\n1. Them sinh vien.");
            idCount++;
            nhapSV(arraySV, idCount, soluongSV);
            printf("\nThem sinh vien thanh cong!");
            soluongSV++;
            pressAnyKey();
            break;
        case 2:
            if (soluongSV > 0) {
                int id;
                printf("\n2. Cap nhat thong tin sinh vien. ");
                printf("\n Nhap ID: "); 
                scanf("%d", &id);
                CapNhatSV(arraySV, id, soluongSV);
            }
            else {
                printf("\nDanh sach sinh vien trong!");
            }
            pressAnyKey();
            break;
        case 3:
            if (soluongSV > 0) {
                int id;
                printf("\n3. Xoa sinh vien.");
                printf("\n Nhap ID: "); 
                scanf("%d", &id);
                if (xoaTheoID(arraySV, id, soluongSV) == 1) {
                    printf("\nSinh vien co id = %d da bi xoa.", &id);
                    soluongSV--;
                }
            }
            else {
                printf("\nDanh sach sinh vien trong!");
            }
            pressAnyKey();
            break;
        case 4:
            if (soluongSV > 0) {
                printf("\n4. Tim kiem sinh vien theo ten.");
                char strTen[30];
                printf("\nNhap ten de tim kiem: "); 
                gets(strTen);
                timKiemTheoTen(arraySV, strTen, soluongSV);
            }
            else {
                printf("\nDanh sach sinh vien trong!");
            }
            pressAnyKey();
            break;
        case 5:
            if (soluongSV > 0) {
                printf("\n5. Sap xep sinh vien theo diem trung binh (GPA).");
                sapxeptheoDTB(arraySV, soluongSV);
                showStudent(arraySV, soluongSV);
            }
            else {
                printf("\nSanh sach sinh vien trong!");
            }
            pressAnyKey();
            break;
        case 6:
            if (soluongSV > 0) {
                printf("\n6. Sap xep sinh vien theo ten.");
                sapxeptheoTen(arraySV, soluongSV);
                showStudent(arraySV, soluongSV);
            }
            else {
                printf("\nDanh sach sinh vien trong!");
            }
            pressAnyKey();
            break;
        case 7:
            if (soluongSV > 0) {
                printf("\n7. Hien thi danh sach sinh vien.");
                showStudent(arraySV, soluongSV);
            }
            else {
                printf("\nDanh sach sinh vien trong!");
            }
            pressAnyKey();
            break;
        case 8:
            if (soluongSV > 0) {
                printf("\n8. Ghi danh sach sinh vien vao file.");
                ghiFile(arraySV, soluongSV, fileName);
            }
            else {
                printf("\nDanh sach sinh vien trong!");
            }
            printf("\nGhi danh sach sinh vien vao file %s thanh cong!", fileName);
            pressAnyKey();
            break;
        case 0:
            printf("\nBan da chon thoat chuong trinh!");
            _getch();
            return 0;
        default:
            printf("\nKhong co chuc nang nay!");
            printf("\nHay chon chuc nang trong hop menu.");
            pressAnyKey();
            break;
        }
    }
}

void printLine(int n) {
    printf("\r\n");
    for (int i = 0; i < n; i++) {
        printf("_");
    }
    printf("\r\n");
}

int idLonNhat(SV a[], int n) {
    int idMax = 0;
    if (n > 0) {
        idMax = a[0].id;
        for (int i = 0; i < n; i++) {
            if (a[i].id > idMax) {
                idMax = a[i].id;
            }
        }
    }
    return idMax;
}

void nhapThongTinSV(SV* sv, int id) {
    printf("\n Nhap ten: \r\n"); gets(sv->ten);
    printf("Nhap gioi tinh: \r\n"); gets(sv->gioiTinh);
    printf("Nhap tuoi: \r\n"); scanf("%d", sv->tuoi);
    printf("Nhap diem Toan: \r\n"); scanf("%d", sv->diemToan);
    printf("Nhap diem Ly: \r\n"); scanf("%d", sv->diemLy);
    printf("Nhap diem Hoa: \r\n"); scanf("%d", sv->diemHoa);
    sv->id = id;
    tinhDTB(&sv);
    xeploai(&sv);
}

void nhapSV(SV a[], int id, int n) {
    printLine(40);
    printf("\n Nhap sinh vien thu %d: \r\n", n + 1);
    nhapThongTinSV(&a[n], id);
    printLine(40);
}

void CapNhatThongTinSV(SV* sv) {
    printf("\n Nhap ten: \r\n"); gets(sv->ten);
    printf("Nhap gioi tinh: \r\n"); gets(sv->gioiTinh);
    printf("Nhap tuoi: \r\n"); scanf("%d", sv->tuoi);
    printf("Nhap diem Toan: \r\n"); scanf("%d", sv->diemToan);
    printf("Nhap diem Ly: \r\n"); scanf("%d", sv->diemLy);
    printf("Nhap diem Hoa: \r\n"); scanf("%d", sv->diemHoa);
    tinhDTB(&sv);
    xeploai(&sv);
}

void CapNhatSV(SV a[], int id, int n) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].id == id) {
            found = 1;
            printLine(40);
            printf("\n Cap nhat thong tin sinh vien co ID = %d\r\n", id);
            CapNhatThongTinSV(&a[i]);
            printLine(40);
            break;
        }
    }
    if (found == 0) {
        printf("\n Sinh vien co ID = %d khong ton tai\r\n", id);
    }
}

int xoaTheoID(SV a[], int id, int n) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].id == id) {
            found = 1;
            printLine(40);
            for (int j = 0; j < n; j++) {
                a[j] = a[j + 1];
            }
            printf("\n Da xoa SV co ID = %d", id);
            printLine(40);
            break;
        }
    }
    if (found == 0) {
        printf("\n Sinh vien co ID = %d khong ton tai", id);
        return 0;
    }
    else {
        return 1;
    }
}

void timKiemTheoTen(SV a[], char ten[], int n) {
    SV arrayFound[MAX];
    char tenSV[30];
    int found = 0;
    for (int i = 0; i < n; i++) {
        strcpy(tenSV, a[i].ten);
        if (strstr(_strupr(tenSV), _strupr(ten))) {
            arrayFound[found] = a[i];
            found++;
        }
    }
    showStudent(arrayFound, found);
}

void tinhDTB(SV* sv) {
    sv->diemTB = (sv->diemToan + sv->diemLy + sv->diemHoa) / 3;
}

void xeploai(SV* sv) {
    if (sv->diemTB >= 8) strcpy(sv->hocluc, "Gioi");
    else if (sv->diemTB >= 6.5) strcpy(sv->hocluc, "Kha");
    else if (sv->diemTB >= 5) strcpy(sv->hocluc, "Trung Binh");
    else strcpy(sv->hocluc, "Yeu");
}

void sapxeptheoDTB(SV a[], int n) {
    SV tmp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i].diemTB > a[j].diemTB) {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}

void sapxeptheoTen(SV a[], int n) {
    SV tmp;
    char tenSV1[30];
    char tenSV2[30];
    for (int i = 0; i < n; i++) {
        strcpy(tenSV1, a[i].ten);
        for (int j = i + 1; j < n; j++) {
            strcpy(tenSV2, a[j].ten);
                if (strcmp(_strupr(tenSV1), _strupr(tenSV2)) > 0) {
                    tmp = a[i];
                    a[i] = a[j];
                    a[j] = tmp;
                }
        }
    }
}

void showStudent(SV a[], int n) {
    printLine(100);
    printf("\n\STT\tID\tHo va ten\tGioi tinh\tTuoi\tToan\tLy\tHoa\tDiem TB\tHoc luc");
    for (int i = 0; i < n; i++) {
        // in sinh vien thu i ra man hinh
        printf("\n %d", i + 1);
        printf("\t%d", a[i].id);
        printf("\t%s", a[i].ten);
        printf("\t\t%s", a[i].gioiTinh);
        printf("\t\t%d", a[i].tuoi);
        printf("\t%.2f\t%.2f\t%.2f", a[i].diemToan, a[i].diemLy, a[i].diemHoa);
        printf("\t%.2f", a[i].diemTB);
        printf("\t%s", a[i].hocluc);
    }
    printLine(100);
}

int docFile(SV a[], char fileName[]) {
    FILE* fp;
    int i = 0;
    fp = fopen(fileName, "r");
    printf("Chuan bi doc file: "); 
    puts(fileName);
    // doc thong tin sinh vien
    while (fscanf(fp, "%5d%30s%5s%5d%10f%10f%10f%10f%10s\n", &a[i].id, &a[i].ten,
        &a[i].gioiTinh, &a[i].tuoi, &a[i].diemToan, &a[i].diemLy, &a[i].diemHoa,
        &a[i].diemTB, &a[i].hocluc) != EOF) {
        i++;
        printf("Doc ban ghi thu: %d\r\n", i);
    }
    printf(" So luong sinh vien co san trong file la: %d", i);
    printf("\r\n");
    // tra ve so luong sinh vien duoc doc tu file
    return i;
    fclose(fp);
}

void ghiFile(SV a[], int n, char fileName[]) {
    FILE* fp;
    fp = fopen(fileName, "w");
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%5d%30s%5s%5d%10f%10f%10f%10f%10s\n", a[i].id, a[i].ten, a[i].gioiTinh,
            a[i].tuoi, a[i].diemToan, a[i].diemLy, a[i].diemHoa, a[i].diemTB, a[i].hocluc);
    }
    fclose(fp);
}

void pressAnyKey() {
    printf("\n\nBam phim bat ky de tiep tuc...");
    _getch();
    system("cls");
}