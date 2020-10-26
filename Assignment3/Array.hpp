//------------------------------------------------------------
//
// C++ course assignment code 
//
// G. Papaioannou, 2016
//
//

#ifndef _ARRAY_IMPLEMENTATION_
#define _ARRAY_IMPLEMENTATION_

#include<new>

namespace math
{
	//--------------------------------------------------------------------------------------------
	// This file is included from the templated Array class header.
	// TODO: Provide its member function implementations here:
	//--------------------------------------------------------------------------------------------
	template <typename T> 
	void * getRawDataPtr() { return buffer; }

	template <typename T>
	T & Array<T>::operator () (int x, int y) {
		return buffer[x*width+y];
	}  

	template <typename T>
	const T & Array<T>::operator () (int x, int y) const {
		return buffer[x*width+y];
	}

	template <typename T>
	Array<T>::Array(unsigned int w, unsigned int h) : width(w), height(h) {
        buffer = new T[width*height];
	}  
    
	template <typename T>
	Array<T>::Array(const Array<T> & source) : width(source.width), height(source.height){
		buffer = new T[width*height];
		for (unsigned int i=0; i<height; i++) {
			for (unsigned int j=0; j<width; j++) {
				buffer[i*width+j]=source.buffer[i*width+j];
			}
		}
	}
	
	template <typename T>
	Array<T> & Array<T>::operator = (const Array<T> & source) {
	    if (&source == this)
		    return *this;
	    if (buffer != nullptr)
		    delete[] buffer;
	    width = source.width;
	    height = source.height;
	    buffer = new T[width*height];
		for (unsigned int i=0; i<height; i++) {
			for (unsigned int j=0; j<width; j++) {
				buffer[i*width+j]=source.buffer[i*width+j];
			}
		}
	}
	
	template <typename T>
	bool Array<T>::operator == (const Array<T> & right) const {
		if (width!=right.width || height!=right.height)
			return false;
		else {
			for (unsigned int i=0; i<height; i++) {
			    for (unsigned int j=0; j<width; j++) {
					if (buffer[i*width+j]!=right.buffer[i*width+j]) {
						return false;
					}
			    }
		    }
		}
		return true;
	}

	template <typename T>
	void resize(unsigned int new_width, unsigned int new_height) {
		if (buffer==nullptr)
			buffer=new T[new_width*new_height];
	    else {
			unsigned int min_width=new_width<width ? new_width : width;
			unsigned int min_height=new_height<height ? new_height : height;
			T* new_buffer=new T[new_width*new_height]();
			for (unsigned int i=0; i<min_height; i++) {
				for (unsigned int j=0; j<min_width; j++) {
					new_buffer[i*min_width+j]=buffer[i*width+j];
				}
			}
			delete[] buffer;
			buffer=new_buffer;
		}
		width=new_width;
		height=new_height;
	}	
	
	template <typename T>
	Array<T>::~Array() {}	

} // namespace math

#endif

