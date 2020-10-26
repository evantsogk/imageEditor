#include<new>
#include <string>
#include "Array.h"
#include "Vec3.h"
#include "Serializable.h"
#include "ppm_format.h"
using namespace imaging;
using namespace std;
using namespace math;

Vec3<float> Image::getPixel(unsigned int x, unsigned int y) const {
    return buffer[x*width+y];
}

void Image::setPixel(unsigned int x, unsigned int y, Vec3<float> & value) {
	buffer[x*width+y]=value;
}

void Image::setData(const Vec3<float> * & data_ptr) {
	if (buffer==nullptr || width == 0 || height == 0)
		return;
	else {
		unsigned int i, j;
		for (i=0; i<height; i++) {
			for (j = 0; j < width; j++) {
				buffer[i*width + j] = data_ptr[i*width + j];
			}
		}
	}
}

Image::Image() : Array(0, 0){
	buffer = nullptr;
}

Image::Image(unsigned int width, unsigned int height) : Array(width, height){
	buffer = new Vec3<float>[width*height];
}

Image::Image(unsigned int width, unsigned int height, const Vec3<float> * data_ptr) : Array(width, height) {
	buffer = new Vec3<float>[width*height];
	this->setData(data_ptr);
}

Image::Image(const Image &src) : Array(src.width, src.height) {
	buffer = new Vec3<float>[width*height];
	const Vec3<float> * data_ptr = src.buffer;
	this->setData(data_ptr);
}

Image::~Image() {}

Image & Image::operator = (const Image & right) {
	if (&right == this)
		return *this;
	if (buffer != nullptr)
		delete[] buffer;
	width = right.width;
	height = right.height;
	buffer = new Vec3<float>[width*height];
	const Vec3<float> * data_ptr = right.buffer;
	this->setData(data_ptr);

	return *this;
}

bool Image::operator << (string filename) {
	Image * img = ReadPPM(filename.c_str());
	if (img==nullptr) return false;
	else return true;
}

bool Image::operator >> (string filename) {
	return WritePPM(*this, filename.c_str());
}

