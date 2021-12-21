//
// Created by Darek on 08.12.2021.
//

#ifndef NETSIM_PACKAGE_HPP
#define NETSIM_PACKAGE_HPP

#include "types.hpp"
#include <vector>
#include <algorithm>
#include <set>

class Package{
public:
    Package();

    explicit Package(ElementID id);
    Package(const Package &p) = default;
    Package(Package&& package) noexcept:id_(package.id_){};
    Package& operator=(const Package&) noexcept;
    ElementID get_id() const {return id_;};

    ~Package();
private:
    ElementID id_;
    static std::set<ElementID> ids_; //obecne id
    static std::set<ElementID> freed_ids_; //zwolnione i uzyte id
};



#endif //NETSIM_PACKAGE_HPP
