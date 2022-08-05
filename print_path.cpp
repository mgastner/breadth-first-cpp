#include "print_path.hpp"
#include <iostream>

void print_path(
  Graph graph,
  std::string source_vertex,
  std::string target_vertex)
{
  if (source_vertex == target_vertex) {
    std::cout << source_vertex;
  } else if (graph[target_vertex].distance == infinity) {
    std::cout << "No path from " << source_vertex << " to " << target_vertex
              << " exists.";
  } else {
    print_path(graph, source_vertex, graph[target_vertex].parent);
    std::cout << " -> " << target_vertex;
  }
}
