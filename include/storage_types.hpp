//
// Created by Darek on 08.12.2021.
//

#ifndef NETSIM_STORAGE_TYPES_HPP
#define NETSIM_STORAGE_TYPES_HPP

#include "package.hpp"

#include <list>
#include <set>
#include <deque>
#include <functional>

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
    virtual ~IPackageStockpile() = default;

    virtual const_iterator begin() const = 0;
    virtual const_iterator cbegin() const = 0;
    virtual const_iterator end() const = 0;
    virtual const_iterator cend() const = 0;
};

class IPackageQueue : public IPackageStockpile{
public:
    virtual Package pop() = 0;
    virtual PackageQueueType get_queue_type() const = 0;
    virtual ~IPackageQueue(){};
};

class PackageQueue : public IPackageQueue{
public:
    explicit PackageQueue(PackageQueueType queue_type = PackageQueueType::LIFO) : queue_type_(queue_type) {};

    bool empty() const override {return deque_.empty();}
    size_t size() const override {return deque_.size();}
    void push(Package &&p) override {deque_.emplace_back(std::move(p));}

    PackageQueueType get_queue_type() const override {return queue_type_;}
    Package pop() override;

    ~PackageQueue(){};

    const_iterator begin() const override {return deque_.begin();}
    const_iterator cbegin() const override {return deque_.cbegin();}
    const_iterator end() const override {return deque_.end();}
    const_iterator cend() const override {return deque_.cend();}
private:
    PackageQueueType queue_type_;
    std::list<Package> deque_;
};






#endif //NETSIM_STORAGE_TYPES_HPP
