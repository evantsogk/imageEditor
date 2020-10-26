#include "MedianFilter.h"
using namespace math;
using namespace imaging;

Vec3<float> MedianFilter::newPixelValue(unsigned int i, unsigned int j) {
	short SV = initializeRGB(i, j);
	float red = r[SV / 2];
	float green = g[SV / 2];
	float blue = b[SV / 2];
	return Vec3<float>(red, green, blue);
}

MedianFilter::MedianFilter(Image &src) {
	image = &src;
	img_width = src.getWidth();
	img_height = src.getHeight();
	img_buffer = image->getRawDataPtr();

	newBuffer = new Vec3<float>[img_width*img_height];
	initializeNewBuffer();
}