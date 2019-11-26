//
// Created by 김혁진 on 14/10/2019.
//

#include "unique_immut.h"

namespace ptr {

	unique_immut::unique_immut() {
		_mgr = new mgr();
	}	

	unique_immut::unique_immut(Object *obj) {
    		_mgr = new mgr(obj);
	}	

	unique_immut::unique_immut(const unique_immut &immut) {
		if (immut._mgr) {
        		int val = immut._mgr->ptr->get();
        		_mgr = new mgr(val);
    		}
	}	

	unique_immut::~unique_immut() {
		release();
	}

	Object* unique_immut::get() const {
		if (this->_mgr->ptr == nullptr) {
			return nullptr;
		}
		else {
			return this->_mgr->ptr;
		}
	}

	void unique_immut::release() {
		if (this->_mgr->ptr != nullptr) {
			this->_mgr->~mgr();
		}
	}

	unique_immut unique_immut::operator+(unique_immut &unique) {
		int l = (*(this->_mgr->ptr)).get();
		int u = (*(unique._mgr->ptr)).get();
		release();
		unique.release();
		
		return unique_immut(new Object(l + u));
	}

	unique_immut unique_immut::operator-(unique_immut &unique) {
		int l = (*(this->_mgr->ptr)).get();
		int u = (*(unique._mgr->ptr)).get();
		release();
		unique.release();
		
		return unique_immut(new Object(l - u));
	}	

	unique_immut unique_immut::operator*(unique_immut &unique) {
		int l = (*(this->_mgr->ptr)).get();
		int u = (*(unique._mgr->ptr)).get();
		release();
		unique.release();
		
		return unique_immut(new Object(l * u));
	}

	unique_immut unique_immut::operator/(unique_immut &unique) {
		int l = (*(this->_mgr->ptr)).get();
		int u = (*(unique._mgr->ptr)).get();
		release();
		unique.release();
		
		return unique_immut(new Object(l / u));
	}

	Object* unique_immut::operator->() {
		return this->_mgr->ptr;
	}

	unique_immut& unique_immut::operator=(unique_immut &r) {
		if (this == &r) {
			std::cout << "operator = " << std::endl;
			return *this;
		}
		

		this->release();
		*this = r;
	
		return *this;
	}
} // end of namespace ptr
