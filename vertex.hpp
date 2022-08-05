//
// Created by Michael Gastner on 4/8/22.
//

#ifndef BREADTH_FIRST_CPP_VERTEX_HPP
#define BREADTH_FIRST_CPP_VERTEX_HPP

#include <set>
#include <string>

// typedef const std::string Vertex;
// typedef const std::set<std::string> AdjacentVertices;
// typedef const std::pair<Vertex, AdjacentVertices> AdjacencyListEntry;
// typedef std::set<AdjacencyListEntry> AdjacencyList;

struct Vertex {
  std::string id;
  std::set<std::string> adjacent_vertices;

  // The default of std::string is an empty string. We use an empty string
  // as a sign that the parent is unknown.
  std::string parent;
  unsigned int distance;
};
std::set<Vertex> vertices(const std::string &adj_list_json_file);

#endif  // BREADTH_FIRST_CPP_VERTEX_HPP
