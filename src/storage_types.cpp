//
// Created by Darek on 08.12.2021.
//

#include "../include/storage_types.hpp"

Package PackageQueue::pop(){
    Package p;
    switch(queue_type_){
        case PackageQueueType::FIFO:
            p = std::move(deque_.front());
            deque_.pop_front();
            break;
        case PackageQueueType::LIFO:
            p = std::move(deque_.back());
            deque_.pop_back();
            break;
    }
    return p;
}
