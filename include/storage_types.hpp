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
    virtual bool empty() const = 0;
    virtual size_t size() const = 0;
    virtual void push(Package&&) = 0;
    virtual ~IPackageStockpile() = 0;
};

class IPackageQueue{
public:
    virtual Package pop() = 0;
    virtual PackageQueueType get_queue_type() const = 0;
};

class PackageQueue{
public:
    PackageQueue(PackageQueueType queue_type) : queue_type_(queue_type) {};
private:
    PackageQueueType queue_type_;
};






#endif //NETSIM_STORAGE_TYPES_HPP
