//
// Created by Darek on 08.12.2021.
//

#ifndef NETSIM_FACTORY_HPP
#define NETSIM_FACTORY_HPP
#include "nodes.hpp"
#include <iostream>

enum class NodeColor{
    UNVISITED, VISITED, VERIFIED
};

template <typename Node>
class NodeCollection{
public:

    using container_t = typename std::list<Node>;
    using iterator = typename container_t::iterator;
    using const_iterator = typename container_t::const_iterator;

    NodeCollection<Node>::iterator find_by_id(ElementID id_) { return std::find_if(mContainer.begin(), mContainer.end(), [id_](const auto& elem){ return id_ == elem.get_id();});}
    NodeCollection<Node>::const_iterator find_by_id(ElementID id_) const { return std::find_if(mContainer.cbegin(), mContainer.cend(), [id_](const auto& elem){ return id_ == elem.get_id();}); }

    iterator begin(){ return mContainer.begin(); }
    iterator end(){ return mContainer.end(); }
    const_iterator begin() const{ return mContainer.cbegin(); }
    const_iterator cbegin() const{ return mContainer.cbegin(); }
    const_iterator end() const{ return mContainer.cend(); }
    const_iterator cend() const{ return mContainer.cend(); }

    void add(Node& node) { mContainer.emplace_back(std::move(node));}
    void remove_by_id(ElementID id_)
    {
        auto it = find_by_id(id_);
        if(it != mContainer.end())
        {
            mContainer.erase(it);
        }
    }
private:
    container_t mContainer;
};

class Factory{
public:
    void add_ramp(Ramp&& r){Ramps.add(r);}
    void remove_ramp(ElementID id){Ramps.remove_by_id(id);}
    NodeCollection<Ramp>::iterator find_ramp_by_id(ElementID id){return Ramps.find_by_id(id);}
    NodeCollection<Ramp>::const_iterator find_ramp_by_id(ElementID id) const {return Ramps.find_by_id(id);}
    NodeCollection<Ramp>::const_iterator ramp_cbegin() const{return Ramps.cbegin();}
    NodeCollection<Ramp>::const_iterator ramp_cend() const{return Ramps.cend();}
    NodeCollection<Ramp>::const_iterator ramp_begin() const{return Ramps.begin();}
    NodeCollection<Ramp>::const_iterator ramp_end() const{return Ramps.end();}

    void add_worker(Worker&& w){Workers.add(w);}
    void remove_worker(ElementID id){this -> remove_receiver(Workers,id);}
    NodeCollection<Worker>::iterator find_worker_by_id(ElementID id){return Workers.find_by_id(id);}
    NodeCollection<Worker>::const_iterator find_worker_by_id(ElementID id) const{return Workers.find_by_id(id);}
    NodeCollection<Worker>::const_iterator worker_cbegin()const{return Workers.cbegin();}
    NodeCollection<Worker>::const_iterator worker_cend()const{return Workers.cend();}
    NodeCollection<Worker>::const_iterator worker_begin()const{return Workers.begin();}
    NodeCollection<Worker>::const_iterator worker_end()const{return Workers.end();}

    void add_storehouse(Storehouse&& s){Storehouses.add(s);}
    void remove_storehouse(ElementID id){this -> remove_receiver(Storehouses,id);}
    NodeCollection<Storehouse>::iterator find_storehouse_by_id(ElementID id){return Storehouses.find_by_id(id);}
    NodeCollection<Storehouse>::const_iterator find_storehouse_by_id(ElementID id) const{return Storehouses.find_by_id(id);}
    NodeCollection<Storehouse>::const_iterator storehouse_cbegin()const{return Storehouses.cbegin();}
    NodeCollection<Storehouse>::const_iterator storehouse_cend()const{return Storehouses.cend();}
    NodeCollection<Storehouse>::const_iterator storehouse_begin()const{return Storehouses.begin();}
    NodeCollection<Storehouse>::const_iterator storehouse_end()const{return Storehouses.end();}

    bool is_consistent();
    void do_deliveries(Time);
    void do_package_passing();
    void do_work(Time);
private:
    template <typename Node>
    void remove_receiver(NodeCollection<Node>& collection, ElementID id) {
        std::for_each(Ramps.begin(), Ramps.end(), [id](Ramp &ramp)
        {
            auto ramp_receivers = ramp.receiver_preferences_.get_preferences();

            for (auto receiver = ramp_receivers.begin(); receiver != ramp_receivers.end(); receiver++) {

                if(receiver->first->get_id()==id) {
                    ramp.receiver_preferences_.remove_receiver(receiver->first);
                }
            }
        });

        std::for_each(Workers.begin(), Workers.end(), [id](Worker &worker) {
            auto worker_receivers = worker.receiver_preferences_.get_preferences();

            for (auto receiver = worker_receivers.begin(); receiver != worker_receivers.end(); receiver++) {

                if(receiver->first->get_id()==id) {
                    worker.receiver_preferences_.remove_receiver(receiver->first);
                }
            }

        });
        collection.remove_by_id(id);
    }
    NodeCollection<Ramp> Ramps;
    NodeCollection<Worker> Workers;
    NodeCollection<Storehouse> Storehouses;
};
//////////////
enum class ElementType{
    LOADING_RAMP, WORKER, STORHOUSE, LINK
};

struct ParsedLineData {
    ElementType element_type;
    std::map<std::string, std::string> parameters;
};

ParsedLineData parse_line(const std::string& line);
Factory load_factory_structure(std::istream& is);
void save_factory_structure(Factory& factory, std::ostream& os);

#endif //NETSIM_FACTORY_HPP
