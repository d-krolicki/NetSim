//
// Created by Darek on 08.12.2021.
//

#ifndef NETSIM_STORAGE_TYPES_HPP
#define NETSIM_STORAGE_TYPES_HPP

enum class PackageQueueType{
    FIFO,
    LIFO
};

class IPackageStockpile{

};

class PackageQueue{
public:
    PackageQueue(PackageQueueType queue_type) : queue_type_(queue_type) {};
private:
    PackageQueueType queue_type_;
};



class IPackageQueue{
public:

private:

};


#endif //NETSIM_STORAGE_TYPES_HPP
