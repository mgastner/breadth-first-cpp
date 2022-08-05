//
// Created by Michael Gastner on 4/8/22.
//

#ifndef BREADTH_FIRST_CPP_VERTEX_PROPERTIES_HPP
#define BREADTH_FIRST_CPP_VERTEX_PROPERTIES_HPP

#include <map>
#include <set>
#include <string>

struct VertexProperties {
  std::set<std::string> adjacent_vertices;

  // The default of std::string is an empty string. We use an empty string
  // as a sign that the parent is unknown.
  std::string parent;
  unsigned int distance;
};
std::map<std::string, VertexProperties> vertices(
  const std::string &adj_list_json_file);

#endif  // BREADTH_FIRST_CPP_VERTEX_PROPERTIES_HPP
