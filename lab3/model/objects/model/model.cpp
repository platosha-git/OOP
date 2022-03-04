#include "model.hpp"

Model::Model(char *name): mesh(new Mesh)
{
    this->name = name;
}

void Model::addPoint(Point &point)
{
    mesh->addPoint(point);
}

void Model::addEdge(Edge &edge)
{
    mesh->addEdge(edge);
}

void Model::transform(const std::shared_ptr<Matrix4x4> mtr)
{
    mesh->transform(mtr);
}

void Model::accept(std::shared_ptr<Visitor> visitor)
{
    visitor->visit(*this);
}

std::shared_ptr<Mesh> Model::getMesh()
{
    return mesh;
}
