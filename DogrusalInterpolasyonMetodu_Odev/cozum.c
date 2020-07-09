#include <stdio.h>

const float GERCEK_KOK = 2.69064744;

float abs(float f) { // mutlak değer fonksiyonu
	if(f < 0) return f * -1;
	return f;
}
float f(float x) {
	// return x^3 - 2x^2 - 5
	return x * x * x - 2 * x * x - 5;
}

float formul(float a, float b) {
	return (a * f(b) - b * f(a)) / (f(b) - f(a));
}

float evaluate(float a, float b, float x) {
	static int n = 0;
	if((abs(GERCEK_KOK - x) < 0.01)) return x; // Durma koşulu
	n++;
	x = formul(a,b);
	printf("%d\t\t%.3f\t%.3f\t%.3f\t%.3f\n", n, a, b, x, GERCEK_KOK - x);
	if(f(x) < 0) a = x;
	else b = x;
	evaluate(a, b, x);
}

int main()
{
	float a = 2, b = 3;
	printf("Iterasyon(#)\ta\tb\tx\tHata\n");
	printf("********************************************\n");

	if(f(a) * f(b) < 0) { // İterasyona geçilebilir.
		printf("Kok : %.4f\n", evaluate(a, b, 0));
		printf("********************************************\n");
	}

	return 0;
}
