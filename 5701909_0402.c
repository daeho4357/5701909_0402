#include <stdio.h>
#define MAX_TERMS 101

struct term {
    float coef;
    int expon;
} terms[MAX_TERMS] = { {4.0 ,3},{3.0 ,2},{2.0 ,1}, {1.0, 0},
                       {3.0, 2},{2.0, 1}, {8.0, 1} };

struct term terms2[MAX_TERMS] = { {7.0 ,6},{5.0 ,3},{9.0 ,2}, {1.0, 0},
                                   {5.0, 3},{2.0, 2}, {1.0, 1}, {10.0, 0} };

int avail = 0;

void print_poly(int s, int e);
void poly_multiply(int As, int Ae, int Bs, int Be, int* Csp, int* Cep);

int main(int argc, char* argv[]) {
    int Cs, Ce;

    printf("A = ");
    print_poly(0, 6);

    printf("B = ");
    print_poly(0, 7);

    poly_multiply(0, 6, 0, 7, &Cs, &Ce);

    printf("A * B = ");
    print_poly(Cs, Ce);

    return 0;
}

void poly_multiply(int As, int Ae, int Bs, int Be, int* Csp, int* Cep) {
    int c_start = 0;
    int result[MAX_TERMS * MAX_TERMS] = { 0 };
    for (int i = As; i <= Ae; i++) {
        for (int j = Bs; j <= Be; j++) {
            int expon = terms[i].expon + terms2[j].expon;
            result[expon] += terms[i].coef * terms2[j].coef;
        }
    }

    int count = 0;
    for (int i = MAX_TERMS - 1; i >= 0; i--) {
        if (result[i] != 0) {
            terms[count].coef = result[i];
            terms[count].expon = i;
            count++;
        }
    }
    *Csp = 0;
    *Cep = count - 1;
}

void print_poly(int s, int e) {
    for (int i = s; i < e; i++) {
        printf("%3.1fx^%d + ", terms[i].coef, terms[i].expon);
    }
    printf("%3.1f\n", terms[e].coef);
}




