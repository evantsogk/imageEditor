#include "GrayFilter.h"
using namespace math;
using namespace imaging;

Vec3<float> GrayFilter::newPixelValue(unsigned int i, unsigned int j) {
	float m = (img_buffer[i*img_width+j].r + img_buffer[i*img_width + j].g + img_buffer[i*img_width + j].b) / 3;
	Vec3<float> newPixel(m, m, m);
	return newPixel;
}

GrayFilter::GrayFilter(Image &src) {
	image = &src;
	img_width = src.getWidth();
	img_height = src.getHeight();
	img_buffer = image->getRawDataPtr();
}