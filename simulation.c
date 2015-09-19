#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_COORDINATE 22

double simulation(double *velocity_simulation) {
	
	/*xyz軸は配列にした方が良かった？*/
	double coordinate_x, coordinate_y, coordinate_z; // 座標
	double velocity_x, velocity_y, velocity_z; // 速度
	double force_x = 0, force_y = 0, force_z = 0; // 力
	double massofgas = 1;
	int ifout = 0; 

	srand(time(NULL));

	/*初期座標決定*/
	coordinate_x = rand() % MAX_COORDINATE;
	coordinate_y = rand() % MAX_COORDINATE;
	coordinate_z = rand() % MAX_COORDINATE;
	
	/*ランダムな角度のラジアンを渡した。*/
	velocity_x = *velocity_simulation * cos(((rand() % 360 + 1) * ((double)M_PI)) / 180.0);
	velocity_y = *velocity_simulation * cos(((rand() % 360 + 1) * ((double)M_PI)) / 180.0);
	velocity_z = *velocity_simulation * cos(((rand() % 360 + 1) * ((double)M_PI)) / 180.0);

	for(;;ifout = 0) {
		
		coordinate_x += velocity_x;
		coordinate_y += velocity_y;
		coordinate_z += velocity_z;

		/*はみ出し判定*/

		for(;;) {

			if(coordinate_x > MAX_COORDINATE || coordinate_x < 0) {
				coordinate_x -= velocity_x;
				velocity_x *= -1;
				force_x += 2 * massofgas * fabs(velocity_x);
				ifout = 1;
			}
			if(coordinate_y > MAX_COORDINATE || coordinate_y < 0) {
				coordinate_y -= velocity_y;
				velocity_y *= -1;
				force_y += 2 * massofgas * fabs(velocity_y);
				ifout = 1;
			}
			if(coordinate_z > MAX_COORDINATE || coordinate_z < 0) {
				coordinate_z -= velocity_z;
				velocity_z *= -1;
				force_z += 2 * massofgas * fabs(velocity_z);
				ifout = 1;
			}
			
			/*TODO もっと綺麗に書けないかな？*/
			if(!(coordinate_x > MAX_COORDINATE) && !(coordinate_x < 0) 
				&& !(coordinate_y > MAX_COORDINATE) && !(coordinate_y < 0) 
				&& !(coordinate_z > MAX_COORDINATE) && !(coordinate_z < 0)) break;
		}
	
	if(ifout) {
		printf("x方向にかかった力：%lf y方向にかかった力：%lf z方向にかかった力：%lf\nx座標：%lf y座標：%lf z座標：%lf\n"
			, force_x, force_y, force_z, coordinate_x, coordinate_y, coordinate_z);
	}

	}

	return 0;
}
