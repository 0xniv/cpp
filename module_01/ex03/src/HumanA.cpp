#include "HumanA.hpp"
#include <string>

HumanA::HumanA() {}

HumanA::~HumanA() {}

const std::string& HumanA::getName() {
	return _name;
}

void HumanA::setName(const std::string& name) {
	_name = name;
}

void HumanA::setWeaponType(const std::string type) {
	my_weapon.setType(type);
}

const std::string& HumanA::getWeaponType() {
	return my_weapon.getType();
}