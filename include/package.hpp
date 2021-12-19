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

    explicit Package(ElementID);

    Package(const Package &p) = default;
    Package(Package&&) noexcept;
    Package& operator=(Package&) = delete;
    Package& operator=(Package&&) noexcept;

    ElementID get_id() const {return id_;}

    ~Package();
private:
    ElementID id_ = blank_id_;
    inline static std::vector<ElementID> ids_;
    inline static std::vector<ElementID> freed_ids_;
    static const ElementID blank_id_ = -1;
};



#endif //NETSIM_PACKAGE_HPP
