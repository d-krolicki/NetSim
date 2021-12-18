//
// Created by Darek on 08.12.2021.
//

#ifndef NETSIM_PACKAGE_HPP
#define NETSIM_PACKAGE_HPP

#include "types.hpp"

class Package{
public:
    Package(ElementID id) : id_(id) {};
    ElementID get_id() const {return id_;}
    ~Package();
private:
    ElementID id_;
};

#endif //NETSIM_PACKAGE_HPP
