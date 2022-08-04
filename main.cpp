#include "parse_arguments.h"
#include <iostream>

int main(const int argc, const char *argv[])
{
  // Parse arguments
  std::string adj_list_json, end_vertex, start_vertex;
  argparse::ArgumentParser arguments =
    parsed_arguments(argc, argv, adj_list_json, start_vertex, end_vertex);
  return EXIT_SUCCESS;
}
