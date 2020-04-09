#pragma once

#include <limits>
#include <cmath>
#include <unordered_map>
#include "model.h"
#include <iostream>

class RouteModel : public Model {

  public:
    class Node : public Model::Node {
      public:
        // Public Node variables and methods
        Node * parent = nullptr;
        float h_value = std::numeric_limits<float>::max();
        float g_value = 0.0;
        bool visited = false;
        std::vector<Node*> neighbors;
      
        float distance(RouteModel::Node other_node) const {
          // std::cout << "I am here 2\n";
          // std::cout << "my x is: " << x << " my y is: " << y << " other x: " << other_node.x << " other y: " << other_node.y << "\n";
          // std::cout << std::sqrt(std::pow((x - other_node.x), 2) + std::pow((y - other_node.y), 2)) << "\n";
          return std::sqrt(std::pow((x - other_node.x), 2) + std::pow((y - other_node.y), 2));
        }

        void FindNeighbors();

        // constructors
        Node(){}
        Node(int idx, RouteModel * search_model, Model::Node node) : Model::Node(node), parent_model(search_model), index(idx) {}
      
      private:
        // Private Node variables and methods
        int index;
        RouteModel* parent_model = nullptr;
        Node * FindNeighbor(std::vector<int> node_indices);
    };

    // Public RouteModel variables and methods
    RouteModel(const std::vector<std::byte> &xml);  
    std::vector<Node> path; // This variable will eventually store the 
                            // path that is found by the A* search.
    
    std::vector<Node> &SNodes() {
      return m_Nodes;
    }

    std::unordered_map<int, std::vector<const Model::Road*>> &GetNodeToRoadMap() {
      return node_to_road;
    }
    Node &FindClosestNode(float x, float y);
    
  private:
    // Private RouteModel variables and methods
    std::vector<Node> m_Nodes;
    std::unordered_map<int, std::vector<const Model::Road*>> node_to_road;
    void CreateNodeToRoadHashmap();
};