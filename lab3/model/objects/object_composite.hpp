#ifndef OBJECTCOMPOSITE_HPP
#define OBJECTCOMPOSITE_HPP

#include "objects/object.hpp"
#include "vector/vector.h"
#include "vector/vector_iterator.hpp"
//#include <vector>

class Composite: public Object
{
public:
    Composite() = default;

    virtual bool add(std::shared_ptr<Object> obj);
    virtual bool remove(VectorIterator<std::shared_ptr<Object>> &it);
    bool isComposite() const override;

    Vector<std::shared_ptr<Object>> getObjects();

    virtual void transform(const std::shared_ptr<Matrix4x4> matrix) override;
    virtual void accept(std::shared_ptr<Visitor> visitor) override;
private:
    Vector<std::shared_ptr<Object>> _objects;
};

#endif // OBJECTCOMPOSITE_HPP
