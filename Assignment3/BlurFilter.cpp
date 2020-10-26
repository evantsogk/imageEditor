#include "BlurFilter.h"
#include <new>
using namespace math;
using namespace imaging;

Vec3<float> BlurFilter::newPixelValue(unsigned int i, unsigned int j) {
    Vec3<float> pixel;
	short SV=0;
	for (short m = -1; m <= 1; m++) {
		for (short n = -1; n <= 1; n++) {
			if (isValid(i + m, j + n)) {
				SV++;
				pixel = pixel+img_buffer[(i + m)*img_width + j + n];
			}
		}
	}

	return pixel/SV;
}

BlurFilter::BlurFilter(Image &src) {
	image = &src;
	img_width = src.getWidth();
    img_height = src.getHeight();
	img_buffer = image->getRawDataPtr();

	newBuffer = new Vec3<float>[img_width*img_height];
    initializeNewBuffer();
}
