//
// Created by Darek on 08.12.2021.
//

#include "../include/package.hpp"
#include <stdexcept>

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
}

Package::Package(ElementID id){
    if(std::find(ids_.cbegin(), ids_.cend(), id) != ids_.cend()){
        throw std::invalid_argument("ID o numerze " + std::to_string(id) + " jest juz w uzyciu.");
    }

    id_ = id;
    ids_.push_back(id);
    if(std::find(freed_ids_.begin(), freed_ids_.end(), id) != freed_ids_.end()){
        freed_ids_.erase(std::find(freed_ids_.begin(), freed_ids_.end(), id));
    }
}

Package& Package::operator=(Package&& other) noexcept {
    if (id_ != blank_id_) {
        if (std::find(freed_ids_.begin(), freed_ids_.end(), id_) != freed_ids_.end()) {
            freed_ids_.erase(std::find(freed_ids_.begin(), freed_ids_.end(), id_));
        }
        ids_.erase(std::find(ids_.begin(), ids_.end(), id_));
    }
    id_ = other.id_;
    other.id_ = blank_id_;

    return *this;

}