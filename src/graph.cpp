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
  return g;
}