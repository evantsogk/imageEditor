#ifndef _Filter_
#define _Filter_

#include "Image.h"
#include "Vec3.h"
using namespace math;

namespace imaging
{
	/*! Base abstract class for all image filters.
	*/
	class Filter {
	    protected: 
			//! The image to which a filter will be applied
			Image* image;
			//! The image's width and height
			unsigned int img_width, img_height;
			//! A pointer to the image's buffer.
			Vec3<float>* img_buffer;

	    public:
			/* Applies a filter to the image.
			*/
			virtual void initializeFilter ()=0;
			/* Calculates the new value of a single pixel according to the type of filter.
			 *
			 * This method is defined in each specific filter class.
			 *
			 *  \param i is the (zero-based) horizontal index of the pixel.
			 *  \param j is the (zero-based) vertical index of the pixel.
			 *
			 *  \return the new pixel value.
			*/
			virtual Vec3<float> newPixelValue(unsigned int i, unsigned int j) = 0;
	};
} // namespace imaging

#endif
