//
// Created by 김혁진 on 14/10/2019.
//

#include "shared_ref.h"

namespace ptr {
shared_ref::shared_ref() {
	this->_mgr = empty_mgr;
}

shared_ref::shared_ref(student* student) {
	if (this->ptr_map[student] == nullptr) {
		this->_mgr = new mgr(student);
		this->ptr_map[student] = this->_mgr;
		this->ptr_map.insert(std::make_pair(student, this->_mgr));
    	}
	else {
		this->_mgr = empty_mgr;
	}
}

shared_ref::shared_ref(const shared_ref& shared) { //copy생성자
	this->_mgr = shared._mgr;
	this->increase();
}

shared_ref::~shared_ref() {	//소멸자
	this->release();
}

//_mgr이 존재할 때, count를 줄여주고 count가 0이 되면 ptr_map에서 _mgr에 해당하는 value(key로 검색)를 nullptr로 바꿔주고 _mgr을 삭제함, 기본적으로 _mgr은 nullptr로 바꿔줌
void shared_ref::release() {	
	if (this->_mgr != nullptr) {
		this->_mgr->count--;
	}
	if (this->_mgr->count == 0) {
		this->ptr_map[this->_mgr->ptr] = nullptr;
		this->_mgr->~mgr();
	}
	this->_mgr = new mgr();
}

student *shared_ref::get() const {
	if (this->_mgr == nullptr) {
		return nullptr;
	}
	else {
		return this->_mgr->ptr;
	}
}

//_mgr이 존재할 때, _mgr안의 count를 증가시켜줌
void shared_ref::increase() {
	if (this->_mgr != nullptr) {
		this->_mgr->count++;
	}
}

shared_ref &shared_ref::operator=(const shared_ref &r) {
    if (this != &r) {
	this->release();
	this->_mgr = r._mgr;
	this->increase();
	return *this;
    }

    return *this;
}

student *shared_ref::operator->() {
	if (this->_mgr == nullptr) {
		return nullptr;
	}

	else {
		return this->_mgr->ptr;
	}
}

int shared_ref::count() {
	if (_mgr) {
		return _mgr->count;
	}
	return 0;
}

}
