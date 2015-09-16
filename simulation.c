#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_COORDINATE 22.4

int simulation(double velocity) {
	
	/*xyz軸は配列にした方が良かった？*/
	double coordinate_x, coordinate_y, coordinate_z; // 座標
	double velocity_x, velocity_y, velocity_z; // 速度
	double force_x = 0, force_y = 0, force_z = 0; // 力
	int ifout_x, ifout_y, ifout_z;
	double massofgas = 1;
	 

	srand(time(NULL));

	/*初期座標決定*/
	coordinate_x = rand() % MAX_COORDINATE;
	coordinate_y = rand() % MAX_COORDINATE;
	coordinate_z = rand() % MAX_COORDINATE;
	
	/*ランダムな角度のラジアンを渡した。*/
	velocity_x = velocity * cos(((rand() % 360 + 1) * ((double)M_PI)) / 180.0);
	velocity_y = velocity * cos(((rand() % 360 + 1) * ((double)M_PI)) / 180.0);
	velocity_z = velocity * cos(((rand() % 360 + 1) * ((double)M_PI)) / 180.0);

	for(;;) {
		
		coordinate_x += velocity_x;
		coordinate_y += velocity_y;
		coordinate_z += velocity_z;

		/*はみ出し判定*/
		for(;;) {

			if(coordinate_x > MAX_COORDINATE || coordinate_x < 0) {
				coordinate_x -= velocity_x;
				velocity_x *= -1;
				ifout_x = 0;
				force_x += 2 * massofgas * velocity_x;
			}
			if(coordinate_y > MAX_COORDINATE || coordinate_y < 0) {
				coordinate_y -= velocity_y;
				velocity_y *= -1;
				ifout_y = 0;
				force_y += 2 * massofgas * velocity_y;
			}
			if(coordinate_z > MAX_COORDINATE || coordinate_z < 0) {
				coordinate_z -= velocity_z;
				velocity_z *= -1;
				ifout_z = 0;
				force_z += 2 * massofgas * velocity_z;
			}
			
			/*TODO もっと綺麗に書けないかな？*/
			if(!ifout_x && !ifout_y && !ifout_z) break;
		}
	
	printf("x方向にかかった力：%lf y方向にかかった力：%lf z方向にかかった力：%lf\n", force_x, force_y, force_z);

	}

	return 0;
}

