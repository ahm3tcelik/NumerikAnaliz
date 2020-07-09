#include <stdio.h>

const float GERCEK_KOK = 2.69064744;

float abs(float f) { // mutlak değer fonksiyonu
	if(f < 0) return f * -1;
	return f;
}
float dxf(float x) { // f'(x)
	// return 3x^2 - 4x
	return 3 * x * x - 4 * x;
}
float f(float x) { // f(x)
	// return x^3 - 2x^2 - 5
	return x * x * x - 2 * x * x - 5;
}

float formul(float x) {
	return x - f(x) / dxf(x);
}

float evaluate(float x) {
	static int n = 0;
	if(abs(formul(x) - x) < 0.01) return x; // Durma koşulu
	n++;
	printf("%d\t\t%.3f\t%.3f\t%.3f\n", n, x, formul(x), abs(formul(x) - x));
	evaluate(formul(x));
}

int main()
{
	float a = 2, b = 3;
	printf("Iterasyon(#)\tXn\tX(n+1)\tHata\n");
	printf("********************************************\n");

	if(f(a) * f(b) < 0) { // İterasyona geçilebilir.
		printf("Kok : %.3f\n", evaluate(a));
		printf("********************************************\n");
	}

	return 0;
}
