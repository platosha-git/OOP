#include "objects/model/mesh/mesh.hpp"

void Mesh::addPoint(Point &point)
{
    points.push_back(point);
}

void Mesh::addEdge(Edge &edge)
{
    time_t t_time = time(NULL);
    if (edge.getBegin() >= points.get_size() || edge.getEnd() >= points.get_size())
    {
        throw ErrorModelBuild(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time), "Wrong point number");
    }
    edges.push_back(edge);
}

void Mesh::transform(const std::shared_ptr<Matrix4x4> mtr)
{
    int n = points.get_size();
    for (int i = 0; i < n; i++)
    {
        points[i].transform(mtr);
    }
}

Vector<std::pair<Point, Point>> Mesh::getLines()
{
    Vector<std::pair<Point, Point>> lines;
    int n = edges.get_size();
    for (int i = 0; i < n; i++)
    {
        std::pair<Point, Point> tmp = std::make_pair(points[edges[i].getBegin()], points[edges[i].getEnd()]);
        lines.push_back(tmp);
    }

    return lines;
}



