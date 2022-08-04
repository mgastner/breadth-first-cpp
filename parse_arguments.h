//
// Created by Michael Gastner on 4/8/22.
//

#ifndef BREADTH_FIRST_CPP_PARSE_ARGUMENTS_H
#define BREADTH_FIRST_CPP_PARSE_ARGUMENTS_H

#include "argparse.hpp"

argparse::ArgumentParser parsed_arguments(
  int argc,
  const char *argv[],
  std::string &adj_list_json,
  std::string &start_vertex,
  std::string &end_vertex);

#endif  // BREADTH_FIRST_CPP_PARSE_ARGUMENTS_H
