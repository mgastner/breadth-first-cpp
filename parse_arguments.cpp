//
// Created by Michael Gastner on 4/8/22.
//

#include "parse_arguments.h"
#include <iostream>

argparse::ArgumentParser parsed_arguments(
  const int argc,
  const char *argv[],
  std::string &adj_list_json,
  std::string &start_vertex,
  std::string &end_vertex)
{
  // Create parser for arguments using argparse.
  // From https://github.com/p-ranav/argparse
  argparse::ArgumentParser arguments("breadth_first_cpp", "0.0");
  arguments.add_argument("adj_list_json")
    .default_value("none")
    .help("File path: JSON file");
  arguments.add_argument("start_vertex")
    .default_value("none")
    .help("Start vertex: key in JSON file (string)");
  arguments.add_argument("-e", "--end_vertex")
    .default_value("none")
    .help("End vertex: key in JSON file (string)");

  // Parse command line arguments
  try {
    arguments.parse_args(argc, argv);
  } catch (const std::runtime_error &err) {
    std::cerr << "ERROR: " << err.what() << std::endl;
    std::cerr << arguments;
    std::exit(1);
  }
  if (arguments.is_used("adj_list_json")) {
    adj_list_json = arguments.get("adj_list_json");
  } else {
    std::cerr << "ERROR: File path to adjacency list is unknown. "
              << "Use -h flag to see list of command-line arguments."
              << std::endl;
    _Exit(EXIT_FAILURE);
  }
  if (arguments.is_used("start_vertex")) {
    start_vertex = arguments.get("start_vertex");
  } else {
    std::cerr << "ERROR: start vertex of breadth-first search unknown. "
              << "Use -h flag to see list of command-line arguments."
              << std::endl;
    _Exit(EXIT_FAILURE);
  }
  if (arguments.is_used("end_vertex")) {
    end_vertex = arguments.get("end_vertex");
  }
  std::cout << "Reading adjacency list from " << adj_list_json << std::endl;
  std::cout << "Start vertex of breadth-first search: " << start_vertex
            << std::endl;
  if (!end_vertex.empty()) {
    std::cout << "End vertex: " << end_vertex << std::endl;
  }
  return arguments;
}