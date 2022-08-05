//
// Created by Michael Gastner on 4/8/22.
//

#include "vertex.hpp"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

bool operator<(const Vertex &lhs, const Vertex &rhs)
{
  return lhs.id < rhs.id;
}

std::set<Vertex> vertices(const std::string &adj_list_json_file)
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
  std::set<Vertex> v;
  for (auto &[id, adj_vertices_json] : j.items()) {
    v.insert(
      {id,
       adj_vertices_json,
       "",  // Empty string as a sign that the parent is unknown.

       // Largest possible unsigned int as symbol of infinite distance.
       std::numeric_limits<unsigned int>::max()});
  }
  return v;
}