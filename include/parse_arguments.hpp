#ifndef BREADTH_FIRST_CPP_PARSE_ARGUMENTS_HPP
#define BREADTH_FIRST_CPP_PARSE_ARGUMENTS_HPP

#include "argparse.hpp"

argparse::ArgumentParser parsed_arguments(
  int argc,
  const char *argv[],
  std::string &adj_list_json_file,
  std::string &source_vertex,
  std::string &target_vertex);

#endif  // BREADTH_FIRST_CPP_PARSE_ARGUMENTS_HPP
