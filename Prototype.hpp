#ifndef PROTOTYPE_HPP
#define PROTOTYPE_HPP


class Prototype {
public:
    virtual ~Prototype() = default;

    virtual std::unique_ptr<Prototype> clone() const = 0;

    virtual void display() const = 0;
};

#endif //PROTOTYPE_HPP
