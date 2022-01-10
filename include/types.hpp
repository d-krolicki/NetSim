//
// Created by Darek on 08.12.2021.
//

#ifndef NETSIM_TYPES_HPP
#define NETSIM_TYPES_HPP
#include <functional>

using ElementID = int;
using Time = int;
using TimeOffset = int;
using ProbabilityGenerator = std::function<double()>;

#endif //NETSIM_TYPES_HPP
