#include "NeighborhoodFilter.h"
using namespace math;
using namespace imaging;


bool NeighborhoodFilter::isValid(unsigned int i, unsigned int j) {
	if (i < 0 || i >= img_height || j < 0 || j >= img_width) {
		return false;
	}
	return true;
}

void NeighborhoodFilter::initializeNewBuffer() {
	for (unsigned int i = 0; i < img_height; i++) {
		for (unsigned int j = 0; j < img_width; j++) {
			newBuffer[i*img_width + j] = newPixelValue(i, j);
		}
	}
}

void NeighborhoodFilter::initializeFilter() {
	for (unsigned int i = 0; i < img_height; i++) {
		for (unsigned int j = 0; j < img_width; j++) {
			(*image).setPixel(i, j, newBuffer[i*img_width + j]);
		}
	}
	delete[] newBuffer;
}