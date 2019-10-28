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
		(this->_mgr->count)++;
	}

	Object* shared_mut::get() const {
		if (this->_mgr->ptr == nullptr) {
			return nullptr;
		}
		else {
			return this->_mgr->ptr;
		}	
	}	

	void shared_mut::release() {
		if(this->_mgr->count != 0) {
			(this->_mgr->count)--;
		}

		if(this->_mgr->count == 0) {
			this->_mgr->~mgr();
		}

		this->_mgr = new mgr();
	}	

	int shared_mut::count() {
		return this->_mgr->count;
	}

	shared_mut shared_mut::operator+(const shared_mut &shared) {
		Object l = *(this->_mgr->ptr);
		Object s = *(shared._mgr->ptr);

		return shared_mut (new Object(l.get() + s.get()));
	}

	shared_mut shared_mut::operator-(const shared_mut &shared) {
		Object l = *(this->_mgr->ptr);
		Object s = *(shared._mgr->ptr);

		return shared_mut (new Object(l.get() - s.get()));
	}

	shared_mut shared_mut::operator*(const shared_mut &shared) {
		Object l = *(this->_mgr->ptr);
		Object s = *(shared._mgr->ptr);

		return shared_mut (new Object(l.get() * s.get()));
	}

	shared_mut shared_mut::operator/(const shared_mut &shared) {
		Object l = *(this->_mgr->ptr);
		Object s = *(shared._mgr->ptr);

		return shared_mut (new Object(l.get()/s.get()));
	}

	Object* shared_mut::operator->() {
		return this->_mgr->ptr;
	}

	shared_mut& shared_mut::operator=(const shared_mut &r) {
		release();
		this->_mgr = r._mgr;
		this->increase();

		return *this;
	}
} // end of namespace ptr
