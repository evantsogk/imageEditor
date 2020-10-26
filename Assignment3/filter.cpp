#include <string>
#include <vector>
#include "Vec3.h"
#include "Image.h"
#include "ppm_format.h"
#include "GrayFilter.h"
#include "ColorFilter.h"
#include "BlurFilter.h"
#include "DiffFilter.h"
#include "MedianFilter.h"
using namespace std;
using namespace imaging;
using namespace math;

int main(int argc, char *argv[]) {
	bool allGood = true; // its true if there is no problem with the command arguments
	vector<string> filters; // stores the names of the filters to be applied
	vector<float> rgb; // stores the rgb values of the filter color
	string str;
	if (argc == 1) {
		cout << "There are no command arguments!" << endl;
		allGood = false;
	}
	else if (argc <= 3) {
		allGood = false;
	}
	else {
		str = argv[argc - 1];
		if (str.length() < 4 || str.substr(str.length() - 4, 4).compare(".ppm")!=0) {
			cout << "No ppm file found!" << endl;
			allGood = false;
		}
		else { 
			bool filterName=false;
			for (unsigned int i = 1; i < argc - 1; i++) {
				str = argv[i];
				if (filterName) {
					if (str.compare("gray") == 0 || str.compare("color") == 0 || str.compare("blur") == 0 || str.compare("diff") == 0 || str.compare("median") == 0) {
						filterName = false;
						filters.push_back(str);
						if (str.compare("color") == 0) {
							for (unsigned int j = i + 1; j <= i + 3; j++) {
								str = argv[j];
								rgb.push_back(stof(str));
							}
							i += 3;
						}
					}
					else {
						cout << "Filter '" << str << "' is invalid! The valid filters are: gray, color, blur, diff and median." << endl;
						allGood = false;
						break;
					}
				}
				else {
					if (str.compare("-f") == 0) {
					    filterName = true;
					}
					else {
						cout << "Expected the argument '-f'. Found '" << str << "' instead." << endl;
						allGood = false;
						break;
                    }
				}
			}
		}
	}

	Image image;
	Image* img;
	if (allGood) {
		img = ReadPPM(argv[argc-1]);
		if (img != nullptr) {
			image = Image(img->getWidth(), img->getHeight(), img->getRawDataPtr());
			GrayFilter gray(image);
			ColorFilter color(image, 0, 0, 0);
			BlurFilter blur(image);
			DiffFilter diff(image);
			MedianFilter median(image);
			unsigned int j = 0;
			for (unsigned int i = 0; i < filters.size(); i++) {
				if (filters.at(i).compare("gray") == 0) {
					gray=GrayFilter(image);
					gray.initializeFilter();
				}
				if (filters.at(i).compare("color") == 0) {
						color = ColorFilter(image, rgb.at(j), rgb.at(j+1), rgb.at(j+2));
						color.initializeFilter();
						j += 3;
				}
				if (filters.at(i).compare("blur") == 0) {
					blur=BlurFilter(image);
					blur.initializeFilter();
				}
				if (filters.at(i).compare("diff") == 0) {
					diff=DiffFilter(image);
					diff.initializeFilter();
				}
				if (filters.at(i).compare("median") == 0) {
					median=MedianFilter(image);
					median.initializeFilter();
				}
			}
			string name = argv[argc - 1];
			string filteredName = name.substr(0, name.length() - 3);
			filteredName.append("filtered.ppm");
			image >> filteredName.c_str();
		}
	}
}