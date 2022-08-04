//
// Created by Michael Gastner on 4/8/22.
//

#include "parse_arguments.h"
#include <iostream>

argparse::ArgumentParser parsed_arguments(
  const int argc,
  const char *argv[],
  std::string &adj_list_json,
  unsigned int &start_vertex,
  unsigned int &end_vertex)
{
  std::cout << "In parsed_arguments()" << std::endl;

  // Create parser for arguments using argparse.
  // From https://github.com/p-ranav/argparse
  argparse::ArgumentParser arguments("breadth_first_cpp", "0.0");
  return arguments;
}