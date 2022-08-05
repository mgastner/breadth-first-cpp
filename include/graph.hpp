#ifndef BREADTH_FIRST_CPP_VERTEX_PROPERTIES_HPP
#define BREADTH_FIRST_CPP_VERTEX_PROPERTIES_HPP

#include <map>
#include <set>
#include <string>

constexpr auto infinity = std::numeric_limits<unsigned int>::max();
struct VertexProperties {
  std::set<std::string> adjacent_vertices;

  // The default of std::string is an empty string. We use an empty string
  // as a sign that the parent is unknown.
  unsigned int distance;
  std::string parent;
};
typedef std::map<std::string, VertexProperties> Graph;
Graph graph(const std::string &adj_list_json_file);

#endif  // BREADTH_FIRST_CPP_VERTEX_PROPERTIES_HPP
