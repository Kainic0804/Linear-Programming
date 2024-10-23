#include<stdio.h>

#define MaxVariables 1000 // Giới hạn 1000 biến
#define MaxConstrains 1000 // Giới hạn 1000 hàm ràng buộc

double tabular[MaxConstrains + 1][MaxVariables + MaxConstrains + 1]; // Số lượng slack variables thêm vào bằng số MaxConstrains
                                                                    // +1 do cần 1 hàng chứa biến, 1 cột chứa RHS

int main(){
    int n, m;  // Số biến và số ràng buộc
    scanf("%d %d", &n, &m);
    double mangluuhammuctieu[n];

    // Nhập giá trị hàm mục tiêu C
    for(int k = 1; k <= n; k++){
        scanf("%lf", &tabular[0][k]);
        tabular[0][k] = -tabular[0][k]; // Chuyển dấu do hàm mục tiêu chuyển vế
    }

    // Nhập giá trị các ràng buộc A
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            scanf("%lf", &tabular[i][j]);
        }
        tabular[i][n + i] = 1;  // Thêm biến bù (slack)
    }

    // Nhập giá trị vector B (RHS)
    for(int i = 1; i <= m; i++){
        scanf("%lf", &tabular[i][n + m + 1]);
    }

    while (1) {
        int pivotCol = PivotColumn(m, n);
        if (pivotCol == -1) break;  // Đã tối ưu

        int pivotRow = PivotRow(m, n, pivotCol);
        if (pivotRow == -1) {       // Vô nghiệm
            printf("UNBOUNDED\n");
            return 0;
        }

        Pivoting(m, n, pivotCol, pivotRow);  // Thực hiện pivot
    }

    // Xuất kết quả
    printf("%d\n", n);
    for (int i = 1; i <= n; i++) {
        double value = 0;
        for (int j = 1; j <= m; j++) {
            if (tabular[j][i] == 1) {
                value = tabular[j][n + m + 1];
                break;
            }
        }
        printf("%.2lf ", value);
    }
    printf("\n");
    printf("%lf", tabular[0][n + m +1]);
    return 0;
}

// Tìm cột để pivot
int PivotColumn(int m, int n){
    double min = 0;
    int vitricot = -1;

    for(int i = 1; i <= n + m; i++){
        if(tabular[0][i] < min){
            min = tabular[0][i];
            vitricot = i;
        }
    }
    return vitricot;
}

// Tìm hàng để pivot
int PivotRow(int m, int n, int vitricot){
    int vitrihang = -1;
    double RatioMin = 1e9;
    for(int i = 1; i <= m; i++){
        if(tabular[i][vitricot] > 0){
            double Ratio = tabular[i][n + m + 1] / tabular[i][vitricot];
            if(Ratio < RatioMin){
                RatioMin = Ratio;
                vitrihang = i;
            }
        }
    }
    return vitrihang;
}

// Thực hiện quá trình pivoting
void Pivoting(int m, int n, int vitricot, int vitrihang){
    double pivot = tabular[vitrihang][vitricot];
    for(int i = 1; i <= n + m + 1; i++){
        tabular[vitrihang][i] /= pivot;
    }

    for(int i = 0; i <= m; i++){
        if(i != vitrihang){
            double y = tabular[i][vitricot];
            for(int j = 1; j <= n + m + 1; j++){
                tabular[i][j] -= y * tabular[vitrihang][j];
            }
        }
    }
}
