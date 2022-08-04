//
// Created by Michael Gastner on 4/8/22.
//

#include "read_adj_list.hpp"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

void read_adj_list(const std::string &adj_list_json_file)
{
  std::cout << "In " << __func__ << "()" << std::endl;

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
  } catch (nlohmann::json::parse_error& e) {
    std::cerr << "ERROR: "
              << e.what()
              << ".\nexception id: "
              << e.id
              << "\nbyte position of error: "
              << e.byte
              << std::endl;
    _Exit(3);
  }
}