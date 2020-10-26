#include <algorithm>
#include "SortingFilter.h"
using namespace math;
using namespace imaging;
using namespace std;

short SortingFilter::initializeRGB(unsigned int i, unsigned int j) {
	short SV = 0;
	for (short m = -1; m <= 1; m++) {
		for (short n = -1; n <= 1; n++) {
			if (isValid(i + m, j + n)) {
				r[SV] = img_buffer[(i + m)*img_width + j + n].r;
				g[SV] = img_buffer[(i + m)*img_width + j + n].g;
				b[SV] = img_buffer[(i + m)*img_width + j + n].b;
				SV++;
			}
		}
	}
	sort(r, r+SV-1);
	sort(g, g+SV-1);
	sort(b, b+SV-1);

	return SV;
}