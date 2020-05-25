#ifndef __FUNCTION_H__
#define __FUNCTION_H__

template <typename T>
void SafeDelete(T& _ptr) {
	if (_ptr) {
		delete _ptr;
		_ptr = nullptr;
	}
}

template <typename T>
void SafeDelete_Array(T& _ptr) {
	if (_ptr) {
		delete[] _ptr;
		_ptr = nullptr;
	}
}

#endif // !__FUNCTION_H__
