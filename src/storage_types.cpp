//
// Created by Darek on 08.12.2021.
//

#include "../include/storage_types.hpp"

bool IPackageStockpile::empty() const {
    return false;
}


size_t IPackageStockpile::size() const {
    return false;
}


void IPackageStockpile::push(Package&&) {
}


IPackageStockpile::~IPackageStockpile() {

}
