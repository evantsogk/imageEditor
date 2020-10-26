#include "LocalFilter.h"
using namespace math;
using namespace imaging;

void LocalFilter::initializeFilter() {
	Vec3<float> pixel;
	for (unsigned int i = 0; i < img_height; i++) {
		for (unsigned int j = 0; j < img_width; j++) {
			pixel = newPixelValue(i, j);
			(*image).setPixel(i, j, pixel);
		}
	}
}