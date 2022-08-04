//
// Created by Michael Gastner on 4/8/22.
//

#ifndef BREADTH_FIRST_CPP_PARSE_ARGUMENTS_H
#define BREADTH_FIRST_CPP_PARSE_ARGUMENTS_H

#include "argparse.hpp"

argparse::ArgumentParser parsed_arguments(
  const int argc,
  const char *argv[],
  std::string &adj_list_json,
  unsigned int &start_vertex,
  unsigned int &end_vertex);

#endif  // BREADTH_FIRST_CPP_PARSE_ARGUMENTS_H
