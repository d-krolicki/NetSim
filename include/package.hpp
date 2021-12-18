//
// Created by Darek on 08.12.2021.
//

#ifndef NETSIM_PACKAGE_HPP
#define NETSIM_PACKAGE_HPP

#include "types.hpp"
#include <vector>
#include <algorithm>

class Package{
public:
    explicit Package();

    Package(Package&&) {};  //konstruktor przenoszący

    //@TODO: Package(ElementID) - co to robi? zaimplementować

    ElementID get_id() const {return id_;}
    ~Package();
private:
    ElementID id_;
    static std::vector<ElementID> ids_;
    static std::vector<ElementID> freed_ids_;
};

Package::Package(){
    ElementID id = 1;
    if(ids_.empty()){   //jezeli ids_ jest puste
        ids_.push_back(id);
    }
    else if(not(freed_ids_.empty())){
        ids_.push_back(*std::min_element(freed_ids_.begin(), freed_ids_.end()));    //jezeli mamy jakies zwolnione id
    }
    else{    //gdy freed_ids_ jest puste, to id =  max(ids_) + 1
        ids_.push_back(*std::max_element(ids_.begin(), ids_.end()) + 1);
    }
}

Package::~Package(){
    ElementID id = get_id();
    if(not(std::find(freed_ids_.cbegin(), freed_ids_.cend(), id) != freed_ids_.cend())){    //jezeli id nie ma jeszcze w freed_ids_ (na ewentualne potrzeby testow)
        freed_ids_.push_back(id);   //dodajemy ID do wolnych
    }
    ids_.erase(std::find(ids_.begin(), ids_.end(), id));    //usuwamy ID z zajetych

    /*@TODO: tutaj ma jeszcze zwalniac pamiec, ale jak?*/
}

#endif //NETSIM_PACKAGE_HPP
