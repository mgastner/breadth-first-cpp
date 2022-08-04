//
// Created by Michael Gastner on 4/8/22.
//

#ifndef BREADTH_FIRST_CPP_ADJACENCY_LIST_HPP
#define BREADTH_FIRST_CPP_ADJACENCY_LIST_HPP

#include <set>
#include <string>

typedef const std::string Vertex;
typedef const std::set<std::string> AdjacentVertices;
typedef const std::pair<Vertex, AdjacentVertices> AdjacencyListEntry;
typedef std::set<AdjacencyListEntry> AdjacencyList;

AdjacencyList adjacency_list(const std::string &adj_list_json_file);

#endif  // BREADTH_FIRST_CPP_ADJACENCY_LIST_HPP
