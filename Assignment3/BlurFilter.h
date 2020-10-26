#ifndef _BlurFilter_
#define _BlurFilter_

#include "Image.h"
#include "Vec3.h"
#include "NeighborhoodFilter.h"
using namespace math;

namespace imaging
{
	/* Blur filter is a neighborhood filter.
	*/
	class BlurFilter : public NeighborhoodFilter {

	public:

		Vec3<float> newPixelValue(unsigned int i, unsigned int j);
		/*! Constructor.
		*
		* \param src is the reference of the image to which the filter will be applied.
		*/
		BlurFilter(Image &src);
	};
} // namespace imaging

#endif

