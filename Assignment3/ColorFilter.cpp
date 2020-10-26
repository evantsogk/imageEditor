#include "ColorFilter.h"
using namespace math;
using namespace imaging;

Vec3<float> ColorFilter::newPixelValue(unsigned int i, unsigned int j) {
	Vec3<float> newPixel(r*img_buffer[i*img_width + j].r, g*img_buffer[i*img_width + j].g, b*img_buffer[i*img_width + j].b);
	return newPixel;
}

ColorFilter::ColorFilter(Image &src, float red, float green, float blue) : r(red), g(green), b(blue) {
	image = &src;
	img_width = src.getWidth();
	img_height = src.getHeight();
	img_buffer = image->getRawDataPtr();
}