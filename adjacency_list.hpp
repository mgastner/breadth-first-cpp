//
// Created by Michael Gastner on 4/8/22.
//

#ifndef BREADTH_FIRST_CPP_ADJACENCY_LIST_HPP
#define BREADTH_FIRST_CPP_ADJACENCY_LIST_HPP

#include <set>
#include <string>

typedef std::string Vertex;
typedef std::set<std::string> AdjacentVertices;
typedef std::pair<Vertex, AdjacentVertices> AdjacencyList;

AdjacencyList adjacency_list(const std::string &adj_list_json_file);

#endif  // BREADTH_FIRST_CPP_ADJACENCY_LIST_HPP
