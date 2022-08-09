#include "graph.hpp"
#include "parse_arguments.hpp"
#include "print_path.hpp"
#include <queue>

int main(const int argc, const char *argv[])
{
  // Parse arguments
  std::string adj_list_json_file, source_vertex, target_vertex;
  auto arguments = parsed_arguments(
    argc,
    argv,
    adj_list_json_file,
    source_vertex,
    target_vertex);

  // Import data. All vertices are initialized as being undiscovered.
  auto g = graph(adj_list_json_file);

  // Are source vertex and target vertex in the graph?
  if (g.find(source_vertex) == g.end()) {
    std::cerr << "ERROR: Non-existing source vertex " << source_vertex
              << std::endl;
    std::exit(EXIT_FAILURE);
  }
  if (g.find(target_vertex) == g.end()) {
    std::cerr << "ERROR: Non-existing target vertex " << target_vertex
              << std::endl;
    std::exit(EXIT_FAILURE);
  }
  std::queue<std::string> q;

  // Discover the source
  q.push(source_vertex);
  g[source_vertex].distance = 0;

  // Breadth-first search
  while (g[target_vertex].distance == infinity && !q.empty()) {
    const auto u = q.front();
    q.pop();
    for (const auto &v : g[u].adjacent_vertices) {
      if (g[v].distance == infinity) {

        // Discover adjacent vertex
        q.push(v);
        g[v].distance = g[u].distance + 1;
        g[v].parent = u;
      }
    }
  }

  // Print path
  if (g[target_vertex].distance < infinity) {
    std::cout << "Path of length " << g[target_vertex].distance << ":\n\t";
  }
  print_path(g, source_vertex, target_vertex);
  std::cout << std::endl;
  return EXIT_SUCCESS;
}
