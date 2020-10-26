#ifndef _MedianFilter_
#define _MedianFilter_
#include "SortingFilter.h"
using namespace math;

namespace imaging
{
	class MedianFilter : public SortingFilter {

	public:

		Vec3<float> newPixelValue(unsigned int i, unsigned int j);
		/*! Constructor.
		*
		* \param src is the reference of the image to which the filter will be applied.
		*/
		MedianFilter(Image &src);
	};
} // namespace imaging

#endif
