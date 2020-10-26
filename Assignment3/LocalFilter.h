#ifndef _LocalFilter_
#define _LocalFilter_

#include "Vec3.h"
#include "Image.h"
#include "Filter.h"
using namespace math;

namespace imaging
{
	/*! This class derives from Filter and is a base class for filters that apply to single pixels
	* without checking the values of other pixels.
	*
	* It defines the method initializeFilter() that is same for all sub-classes.
	*/
	class LocalFilter : public Filter {

	public:
		void initializeFilter();

		virtual Vec3<float> newPixelValue(unsigned int i, unsigned int j) = 0;
	};
} // namespace imaging

#endif
