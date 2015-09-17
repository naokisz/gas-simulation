#include <stdio.h>
#include "simulation.c"

int main(void) {

	double velocity_main; // 速度

	printf("気体シュミレーション\n");
	printf("気体の速度を入力してください。＞");
	scanf("%lf", &velocity_main);

	simulation(&velocity_main);

	return 0;
}
