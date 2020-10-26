#ifndef _NeighborhoodFilter_
#define _NeighborhoodFilter_

#include "Vec3.h"
#include "Image.h"
#include "Filter.h"
using namespace math;

namespace imaging
{
	/*! This class derives from Filter and is a base class for filters that apply to pixels according to the values
	* of the pixels surrounding them.
	*/
	class NeighborhoodFilter : public Filter {

	protected:
		//! Just a temporary buffer to store the new pixel values after applying the filter
		Vec3<float>* newBuffer;
    public:
		/*! Checks if the coordinates i, j are inside the bounds of the image.
		*
		* It defines the method initializeFilter() that is same for all sub-classes.
		*
		* \param i is the (zero-based) horizontal index.
		* \param j is the (zero-based) vertical index.
		*
		* \return true if the coordinates are inside the bounds of the image.
		*/
		bool isValid(unsigned int i, unsigned int j);
		/*! Fills the buffer with all the image pixels after changing each one of them according to the filter,
		* using the method newPixelValue.
		*/
		void initializeNewBuffer();

		void initializeFilter();

		virtual Vec3<float> newPixelValue(unsigned int i, unsigned int j) = 0;
	};
} // namespace imaging

#endif
