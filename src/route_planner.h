#pragma once
/*
These files contain a class stub for a RoutePlanner class which accepts a RouteModel along with start and end coordinates.
The RouteModel data, along with the start and end points will be used for A* search,
which will be implemented in these files. Have a look a the video below for a brief overview of the contents.
*/
#include <iostream>
#include <vector>
#include <string>
#include "route_model.h"


class RoutePlanner
{
  public:
    // Constructor
    RoutePlanner(RouteModel &model, float start_x, float start_y, float end_x, float end_y);
    float GetDistance() const {return distance;}
    void AStarSearch();
  
  private:
    float CalculateHValue(RouteModel::Node * node);
    std::vector<RouteModel::Node> ConstructFinalPath(RouteModel::Node *);
    RouteModel::Node * NextNode();
    RouteModel & m_Model;
    RouteModel::Node * start_node;
    RouteModel::Node * end_node;
    float distance;
    std::vector<RouteModel::Node *> open_list;
    bool CompareNodes(RouteModel::Node * a, RouteModel::Node * b);
    void AddNeighbors(RouteModel::Node * node);
};