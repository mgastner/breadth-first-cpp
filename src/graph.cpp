#include "graph.hpp"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

Graph graph(const std::string &adj_list_json_file)
{
  // Open file
  std::ifstream in_file(adj_list_json_file);
  if (!in_file) {
    throw std::system_error(
      errno,
      std::system_category(),
      "failed to open " + adj_list_json_file);
  }

  // Parse JSON
  nlohmann::json j;
  try {
    in_file >> j;
  } catch (nlohmann::json::parse_error &e) {
    std::cerr << "ERROR: " << e.what() << ".\nexception id: " << e.id
              << "\nbyte position of error: " << e.byte << std::endl;
    std::exit(EXIT_FAILURE);
  }

  // Create map from vertex ID to vertex properties
  Graph g;
  for (const auto &[id, adj_vertices_json] : j.items()) {
    g[id] = {
      adj_vertices_json,
      infinity,
      ""  // Empty string as a sign that the parent is unknown
    };
  }

  // Do all adjacent vertices exist?
  std::set<std::string> focal_vertices;
  std::set<std::string> adj_vertices;
  for (const auto &[id, prop] : g) {
    focal_vertices.insert(id);
    for (const auto &a : prop.adjacent_vertices) {
      adj_vertices.insert(a);
    }
  }
  std::set<std::string> diff;
  std::set_difference(
    adj_vertices.begin(),
    adj_vertices.end(),
    focal_vertices.begin(),
    focal_vertices.end(),
    std::inserter(diff, diff.end()));
  if (!diff.empty()) {
    std::cerr << "ERROR: Non-existing adjacent vertices:\n\t";
    for (const auto &d : diff) {
      std::cerr << " " << d;
    }
    std::cerr << std::endl;
    std::exit(EXIT_FAILURE);
  }
  return g;
}