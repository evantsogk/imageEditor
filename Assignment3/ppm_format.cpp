#include <iostream>
#include <string>
#include <fstream>
#include<new>
#include "ppm_format.h"
#include "Vec3.h"
using namespace std;
using namespace math;
using namespace imaging;
Image * imaging::ReadPPM(const char * filename) {
	char * cdata;
	unsigned int width, height;

	ifstream file(filename, ios::binary);

	if (file.fail()) {
		cerr << "Error opening file." << endl;
		return nullptr;
	}

	string type;
	file >> type;
	if (type != "P6") {
		cerr << "Only P6 is supported." << endl;
		file.close();
		return nullptr;
	}

	file >> width;
	file >> height;
	unsigned int maxValue;
	file >> maxValue;
	if (maxValue>255) {
		cerr << "Only 1 byte channels are supported."<<endl;
		file.close();
		return nullptr;
	}
	
	cdata = new char[3*width*height+1];
	file.read(cdata, 3 * width*height+1);
    file.close();

    Vec3<float>* data = new Vec3<float>[width*height];

	unsigned int i=0, j=0;
	float r, g, b;
	Vec3<float> pixel;
	while (j<width*height) {
		r=static_cast<unsigned char>(cdata[++i])/255.f;
		g=static_cast<unsigned char>(cdata[++i])/255.f;
		b=static_cast<unsigned char>(cdata[++i])/255.f;
		pixel = Vec3<float>(r, g, b);
		data[j] = pixel;
		j++;
	}
	
	Image img(width, height, data);
	delete[] data;
	delete[] cdata;
	
	return &img;
}

bool imaging::WritePPM(Image & image, const char * filename) {
	ofstream file(filename, ios::binary);
	if (!file) {
		cerr<<"Cannot open file"<<endl;
		return false;
	}
	unsigned int width = image.getWidth();
	unsigned int height = image.getHeight();
	Vec3<float> * buffer = image.getRawDataPtr();

	file<<"P6"<<endl<<width<<endl<<height<<endl<<255<<endl;
	
	char * cdata=new char[3*width*height];
	unsigned int j=0;
	for (unsigned int i=0; i<width*height; i++) {
		cdata[j]=buffer[i].r*255;
		cdata[j+1]=buffer[i].g*255;
		cdata[j+2]=buffer[i].b*255;
		j+=3;
	}
	
	file.write(cdata, 3*width*height);
	
	if (file.fail()) {
		cerr<<"Could not write data"<<endl;
		return false;
	}
	
	file.close();
	return true;
}

