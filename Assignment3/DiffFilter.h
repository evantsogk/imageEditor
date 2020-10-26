#ifndef _DiffFilter_
#define _DiffFilter_
#include "SortingFilter.h"
using namespace math;

namespace imaging
{
	/* DiffFilter is a neigborhood and sorting filter.
	*/
	class DiffFilter : public SortingFilter {

    public:
        
		Vec3<float> newPixelValue(unsigned int i, unsigned int j);
		/*! Constructor.
		*
		* \param src is the reference of the image to which the filter will be applied.
		*/
		DiffFilter(Image &src);
	};
} // namespace imaging

#endif
