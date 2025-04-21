#ifndef PROTOTYPEREGISTRY_HPP
#define PROTOTYPEREGISTRY_HPP
#include <map>
#include <memory>
#include <string>
#include "Prototype.hpp"


class PrototypeRegistry {
    std::map<std::string, std::unique_ptr<Prototype> > prototypes;

public:
    void registerPrototype(const std::string &name, std::unique_ptr<Prototype> proto) {
        prototypes[name] = std::move(proto);
    }

    std::unique_ptr<Prototype> clonePrototype(const std::string &name) {
        if (!prototypes.contains(name)) {
            return nullptr;
        }
        return prototypes[name]->clone();
    }
};

#endif //PROTOTYPEREGISTRY_HPP
