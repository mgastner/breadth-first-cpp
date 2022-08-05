#include "print_path.hpp"
#include <iostream>

void print_path(std::string source_vertex, std::string target_vertex)
{
  std::cout << "In " << __func__ << "(). Source vertex: " << source_vertex
            << ". Target vertex: " << target_vertex << "." << std::endl;
  if (source_vertex == target_vertex) {
    std::cout << source_vertex << "\n";
  }
}
