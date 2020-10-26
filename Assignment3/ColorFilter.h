#ifndef _ColorFilter_
#define _ColorFilter_

#include "Image.h"
#include "Vec3.h"
#include "Filter.h"
#include "LocalFilter.h"
using namespace math;

namespace imaging
{
	/* ColorFilter is a local filter.
	*/
	class ColorFilter : public LocalFilter {
	private: 
		//! The rgb values of the color.
		float r, g, b;

	public:

		Vec3<float> newPixelValue(unsigned int i, unsigned int j);
		/*! Constructor.
		*
		* \param src is the reference of the image to which the filter will be applied.
		* \param red is the red value of the color.
		* \param green is the green value of the color.
		* \param blue is the blue value of the color.
		*/
		ColorFilter(Image &src, float red, float green, float blue);
	};
} // namespace imaging

#endif
