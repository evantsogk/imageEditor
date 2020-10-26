#ifndef _GrayFilter_
#define _GrayFilter_

#include "Image.h"
#include "Vec3.h"
#include "Filter.h"
#include "LocalFilter.h"
using namespace math;

namespace imaging
{
	/* GrayFilter is a local filter.
	*/
	class GrayFilter : public LocalFilter {

	public:

		Vec3<float> newPixelValue(unsigned int i, unsigned int j);
		/*! Constructor.
		*
		* \param src is the reference of the image to which the filter will be applied.
		*/
		GrayFilter(Image &src);
	};
} // namespace imaging

#endif
