#include "parse_arguments.hpp"
#include <iostream>

argparse::ArgumentParser parsed_arguments(
  const int argc,
  const char *argv[],
  std::string &adj_list_json_file,
  std::string &source_vertex,
  std::string &target_vertex)
{
  // Create parser for arguments using argparse.
  // From https://github.com/p-ranav/argparse
  argparse::ArgumentParser arguments("breadth_first_cpp", "0.0");
  arguments.add_argument("adj_list_json_file")
    .default_value("none")
    .help("File path: JSON file");
  arguments.add_argument("source_vertex")
    .default_value("none")
    .help("Source vertex: key in JSON file (string)");
  arguments.add_argument("-t", "--target_vertex")
    .default_value("none")
    .help("Target vertex: key in JSON file (string)");

  // Parse command line arguments
  try {
    arguments.parse_args(argc, argv);
  } catch (const std::runtime_error &err) {
    std::cerr << "ERROR: " << err.what() << std::endl;
    std::cerr << arguments;
    std::exit(1);
  }
  if (arguments.is_used("adj_list_json_file")) {
    adj_list_json_file = arguments.get("adj_list_json_file");
  } else {
    std::cerr << "ERROR: File path to adjacency list is unknown. "
              << "Use -h flag to see list of command-line arguments."
              << std::endl;
    std::exit(EXIT_FAILURE);
  }
  if (arguments.is_used("source_vertex")) {
    source_vertex = arguments.get("source_vertex");
  } else {
    std::cerr << "ERROR: source vertex of breadth-first search unknown.\n"
              << "Use -h flag to see list of command-line arguments."
              << std::endl;
    std::exit(EXIT_FAILURE);
  }
  if (arguments.is_used("target_vertex")) {
    target_vertex = arguments.get("target_vertex");
  }
  std::cout << "Reading adjacency list from " << adj_list_json_file
            << std::endl;
  std::cout << "Source vertex of breadth-first search: " << source_vertex
            << std::endl;
  if (!target_vertex.empty()) {
    std::cout << "Target vertex: " << target_vertex << std::endl;
  }
  return arguments;
}