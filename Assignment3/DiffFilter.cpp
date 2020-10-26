#include "DiffFilter.h"
using namespace math;
using namespace imaging;

Vec3<float> DiffFilter::newPixelValue(unsigned int i, unsigned int j) {
	short SV = initializeRGB(i, j);
	float red = r[SV] - r[0];
	float green = g[SV] - g[0];
	float blue = b[SV] - b[0];
	return Vec3<float>(red, green, blue);
}

DiffFilter::DiffFilter(Image &src) {
	image = &src;
	img_width = src.getWidth();
	img_height = src.getHeight();
	img_buffer = image->getRawDataPtr();

	newBuffer = new Vec3<float>[img_width*img_height];
	initializeNewBuffer();
}