#include "Weapon.hpp"

Weapon::Weapon() {}

Weapon::~Weapon() {}

const std::string& Weapon::getType() const {
	return _type;
}

void	Weapon::setType(const std::string& name) {
	_type = name;
}