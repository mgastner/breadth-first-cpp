#include "adjacency_list.hpp"
#include "parse_arguments.hpp"

int main(const int argc, const char *argv[])
{
  // Parse arguments
  std::string adj_list_json_file, end_vertex, start_vertex;
  argparse::ArgumentParser arguments =
    parsed_arguments(argc, argv, adj_list_json_file, start_vertex, end_vertex);

  // Import data
  AdjacencyList adj_list = adjacency_list(adj_list_json_file);
  return EXIT_SUCCESS;
}
