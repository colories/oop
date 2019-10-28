//
// Created by 김혁진 on 14/10/2019.
//

#include "shared_mut.h"

namespace ptr {

	shared_mut::shared_mut() {
    		_mgr = new mgr();
	}

	shared_mut::shared_mut(Object* _obj) {
    		_mgr = new mgr(_obj);
	}

	shared_mut::~shared_mut() {
    		release();
	}

	void shared_mut::increase() {
		// 현재 객체의 mgr에 있는 object ptr을 1 증가시켜 반환
		(_mgr->count)++;
	}

	Object* shared_mut::get() const {
		if (_mgr->ptr == nullptr) {
			return nullptr;
		}

		else {
			return _mgr->ptr;
		}
	}	

	void shared_mut::release() {
		// 현재 객체의 mgr의 count가 0이 아니면 count를 1 감소
		if(_mgr->count != 0) {
			(_mgr->count--);
		}
		
		if(_mgr->count == 0) {
			_mgr->~mgr();
		}
	}	

	int shared_mut::count() {
		// 현재 객체의 mgr의 count를 반환
		return _mgr->count;
	}

	shared_mut shared_mut::operator+(const shared_mut &shared) {
		int l = (*(_mgr->ptr)).get();
		int s = (*(shared._mgr->ptr)).get();
		// 현재 객체의 val값에 shared_mut의 val 값을 더하여 반환
		return shared_mut (new Object(l + s));
	}

	shared_mut shared_mut::operator-(const shared_mut &shared) {
		int l = (*(_mgr->ptr)).get();
		int s = (*(shared._mgr->ptr)).get();

		// 현재 객체의 val값에 shared_mut의 val 값을 뺴서 반환
		return shared_mut (new Object(l - s));
	}

	shared_mut shared_mut::operator*(const shared_mut &shared) {
		int l = (*(_mgr->ptr)).get();
		int s = (*(shared._mgr->ptr)).get();
		
		// 현재 객체의 val값에 shared_mut의 val 값을 곱하여 반환
		return shared_mut (new Object(l * s));
	}

	shared_mut shared_mut::operator/(const shared_mut &shared) {
		int l = (*(_mgr->ptr)).get();
		int s = (*(shared._mgr->ptr)).get();

		// 현재 객체의 val값에 shared_mut의 val 값을 나누어 반환
		return shared_mut (new Object(l / s));
	}

	Object* shared_mut::operator->() {
		// 현재 객체의 mgr의 object ptr을 반환
		return _mgr->ptr;
	}

	shared_mut& shared_mut::operator=(const shared_mut &r) {
		release();
		this->_mgr = r._mgr;
		this->increase();

		return *this;
	}
} // end of namespace ptr
