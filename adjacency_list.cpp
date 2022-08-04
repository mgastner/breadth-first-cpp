//
// Created by Michael Gastner on 4/8/22.
//

#include "adjacency_list.hpp"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

AdjacencyList adjacency_list(const std::string &adj_list_json_file)
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
    _Exit(EXIT_FAILURE);
  }

  // Create adjacency list
  std::set<AdjacencyListEntry> adj_list;
  for (auto &[vertex, adj_vertices_json] : j.items()) {
    std::cout << "vertex: " << vertex
              << ", adj_vertices_json:" << adj_vertices_json << '\n';
    AdjacentVertices adj_vertices =
      static_cast<AdjacentVertices>(adj_vertices_json);
    AdjacencyListEntry adj_list_entry = std::make_pair(vertex, adj_vertices);
    adj_list.insert(adj_list_entry);
  }
  return adj_list;
}