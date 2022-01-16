//
// Created by Darek on 08.12.2021.
//

#include "../include/package.hpp"
#include <stdexcept>

std::set<ElementID> Package::ids_={};
std::set<ElementID> Package::freed_ids_={};

Package::Package(){
    if(!Package::freed_ids_.empty()){
        ElementID id = *Package::freed_ids_.begin();
        for (auto el: Package::freed_ids_) {
            if(el<id){
                id =el;
            }
        }
        id_ = id;
        Package::ids_.insert(id);
    }
    else{
        ElementID id = *Package::ids_.begin();
        for (const auto el: Package::ids_) {
            if(el>id){
                id =el;
            }
        }
        id_ = id+1;
        Package::ids_.insert(id+1);
    }
}

Package::~Package(){
    freed_ids_.insert(id_);
    ids_.erase(id_);
}

Package::Package(ElementID id){
    id_ = id;
    ids_.insert(id);
    freed_ids_.erase(id);
}


Package &Package::operator=(Package const& other) noexcept {
    id_ = other.id_;

    return *this;

}
