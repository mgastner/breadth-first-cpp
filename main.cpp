#include "parse_arguments.h"
#include <iostream>

int main(const int argc, const char *argv[])
{
  std::string adj_list_json;
  unsigned int start_vertex, end_vertex;

  argparse::ArgumentParser arguments =
    parsed_arguments(argc, argv, adj_list_json, start_vertex, end_vertex);

  std::cout << "Hello, World!" << std::endl;
  return 0;
}
