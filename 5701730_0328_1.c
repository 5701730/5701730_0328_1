#include <stdio.h>
#define MAX_DEGREE 10//다항식의 최대의 차수를 정의



typedef struct {//다항식 구초체 정의
	int degree;//다항식 차수를 저장하는 변수
	float coef[MAX_DEGREE];//각 차수에 해당하는 계수를 저장하는 배열이다.
} polynomial;


void print_poly(polynomial p) {
	for (int i = p.degree; i > 0; i--)
		printf("%3.1fx^%d +", p.coef[p.degree - i], i);
    printf("%3.1f \n", p.coef[p.degree]);
}


polynomial poly_mult(polynomial A, polynomial B)
{
	polynomial C;//결과를 저장할 구조체 변수
	int i, j;

	for (i = 0; i < A.degree + B.degree + 1; i++) C.coef[i] = 0;//초기화
	C.degree = A.degree + B.degree;

	for (i = 0; i < A.degree + 1; i++)//다항식 곱셈
		for (j = 0; j < B.degree + 1; j++)
			C.coef[i + j] += A.coef[i] * B.coef[j];

	return C;
}
polynomial poly_mult_2(polynomial D, polynomial F) {
	polynomial G;//결과 다항식을 저장하는 구조체 변수
	int i, j;

	for (i = 0; i < D.degree + F.degree + 1; i++) G.coef[i] = 0;//초기화
	G.degree = D.degree + F.degree;

	for (i = 0; i < D.degree + 1; i++)//다항식 곱셈
		for (j = 0; j < F.degree + 1; j++)
			G.coef[i + j] += D.coef[i] * F.coef[j];

	return G;
}


main() {

	polynomial a = { 3,{4,3,2,1} };
	polynomial b = { 2,{3,2,8} };
	polynomial d = { 6,{7,0,0,5,9,0,1} };
	polynomial f = { 3,{5,2,1,10} };

	polynomial c;
	polynomial g;
	//첫 번째 문제 계산
	print_poly(a);
	print_poly(b);
	c = poly_mult(a, b);
	printf("--------------------------------\n");
	print_poly(c);
	printf("\n");
	//두 번째 문제 계산
	print_poly(d);
	print_poly(f);
	g = poly_mult_2(d,f);
	printf("--------------------------------\n");
	print_poly(g);

	return 0;
}


