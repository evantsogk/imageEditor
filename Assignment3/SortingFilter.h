#ifndef _SortingFilter_
#define _SortingFilter_

#include <algorithm>
#include "NeighborhoodFilter.h"
using namespace math;

namespace imaging
{
	/*! This class derives from NeigborhoodFilter and is a base class for filters that need to sort the rgb values of pixels.
	*/
	class SortingFilter : public NeighborhoodFilter {

	protected:
		//! Arrays that store the rgb values of up to 9 pixels
		float r[9], g[9], b[9];
		
	public:
		/* It gives values to the member arrays according to the pixel values surrounding the pixel at (i, j) and sorts them.
		*
		* \param i is the (zero-based) horizontal index of the pixel.
		* \param j is the (zero-based) vertical index of the pixel.
		*/
		short initializeRGB(unsigned int i, unsigned int j);

		virtual Vec3<float> newPixelValue(unsigned int i, unsigned int j) = 0;
	};
} // namespace imaging

#endif
