//
// Created by Darek on 08.12.2021.
//

#ifndef NETSIM_STORAGE_TYPES_HPP
#define NETSIM_STORAGE_TYPES_HPP

#include <list>
#include "package.hpp"

enum class PackageQueueType{
    FIFO,
    LIFO
};

class IPackageStockpile{
public:
    using const_iterator = std::list<Package>::const_iterator;
    virtual bool empty() const;
    virtual size_t size() const;
    void push(Package&&);
    ~IPackageStockpile();
};

class IPackageQueue{
public:

private:

};

class PackageQueue{
public:
    PackageQueue(PackageQueueType queue_type) : queue_type_(queue_type) {};
private:
    PackageQueueType queue_type_;
};






#endif //NETSIM_STORAGE_TYPES_HPP

