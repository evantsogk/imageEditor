#ifndef _IMAGE
#define _IMAGE

#include "Array.h"
#include "Vec3.h"
#include "Serializable.h"
using namespace math;
/*! The imaging namespace contains every class or function associated with the image storage, compression and manipulation.
*/
namespace imaging
{
	/*! It is the class that represents a generic data container for an image.
	*
	* It inherits the Array class to hold the buffer of the pixel values and it provides methods for accessing them.
	* The size of the buffer variable holding these data is width*height and each pixel is represented by a Vec3<float> object.
	*
    * It also implements the methods of the interface Serializable that allow to read and write image files.
	*/
	class Image : public Array<Vec3<float>>, public Serializable {
		
	public:                          
		/*! Obtains a pointer to the internal data.
		*/
		Vec3<float> * getRawDataPtr() { return buffer; }
		/*! Obtains the color of the image at location (x,y).
		*
		* This method does NOT do any bound checkings.
		*
		*  \param x is the (zero-based) horizontal index of the pixel to get.
		*  \param y is the (zero-based) vertical index of the pixel to get.
		*
		*  \return The color of the (x,y) pixel as a Vec3<float> object.
		*/
		Vec3<float> getPixel(unsigned int x, unsigned int y) const;
		/*! Sets the color for an (x,y) pixel.
		*
		* This method does NOT do any bound checkings.
		*
		*  \param x is the (zero-based) horizontal index of the pixel to set.
		*  \param y is the (zero-based) vertical index of the pixel to set.
		*  \param value is the new color for the (x,y) pixel.
		*/
		void setPixel(unsigned int x, unsigned int y, Vec3<float> & value); 
		/*! Copies the image data from an external raw buffer to the internal image buffer.
		*
		*  The member function ASSUMES that the input buffer is of a size compatible with the internal storage of the
		*  Image object and that the data buffer has been alreeady allocated. If the image buffer is not allocated or the
		*  width or height of the image are 0, the method should exit immediately.
		*
		*  \param data_ptr is the reference to the preallocated buffer from where to copy the data to the Image object.
		*/
		void setData(const Vec3<float> * & data_ptr);            
		/*! Changes the internal image data storage size.
		*
		* If the one or both of the given dimensions are smaller, the image should be clipped
		* by discarding the remaining pixels in the rows and/or columns outside the margins.
		* If the new dimensions are larger, pad the old pixels with zero values (black color).
		* If the image is not yet allocated (zero width and height), allocate the internal buffer and
		* set the image size according to the given dimensions.
		*
		* \param new_width is the user-provided width to resize the image storage to.
		* \param new_height is the user-provided height to resize the image storage to.
		*/
		void resize(unsigned int new_width, unsigned int new_height);
		/*! Default constructor.
		*
		* By default, the dimensions of the image should be zero and the buffer must be set to nullptr.
		*/
		Image();											     	
		/*! Constructor with width and height specification.
		*
		* \param width is the desired width of the new image.
		* \param height is the desired height of the new image.
		*/
		Image(unsigned int width, unsigned int height);
		/*! Constructor with data initialization.
		*
		* \param width is the desired width of the new image.
		* \param height is the desired height of the new image.
		* \param data_ptr is the source of the data to copy to the internal image buffer.
		*
		* \see setData
		*/
		Image(unsigned int width, unsigned int height, const Vec3<float> * data_ptr);
		/*! Copy constructor.
		*
		* \param src is the source image to replicate in this object.
		*/
		Image(const Image &src);
		/*! The Image destructor.
		*/
		~Image();
		/*! Copy assignment operator.
		*
		* \param right is the source image.
		*/
		Image & operator = (const Image & right);
		/*! Reads an image.
		*/
		bool operator << (std::string filename);
		/*! Writes an image.
		*/
		bool operator >> (std::string filename); 

	};

} //namespace imaging

#endif

