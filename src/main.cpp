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
  if (!target_vertex.empty() && g.find(target_vertex) == g.end()) {
    std::cerr << "ERROR: Non-existing target vertex " << target_vertex
              << std::endl;
    std::exit(EXIT_FAILURE);
  }

  // Discover the source
  std::queue<std::string> q;
  q.push(source_vertex);
  g[source_vertex].distance = 0;

  // Breadth-first search
  while (!q.empty()) {
    const auto focal_vertex = q.front();
    q.pop();
    for (const auto &adj_vertex : g[focal_vertex].adjacent_vertices) {
      if (g[adj_vertex].distance == std::numeric_limits<unsigned int>::max()) {
        q.push(adj_vertex);
        g[adj_vertex].distance = g[focal_vertex].distance + 1;
        g[adj_vertex].parent = focal_vertex;
      }
    }
  }

  // Output
  if (target_vertex.empty()) {

    // If no target vertex is given, print distances and parents of all
    // vertices
    std::cout << "\n";
    for (const auto &[id, prop] : g) {
      std::cout << "vertex ID: " << id << "\n\tdistance from source: ";
      if (prop.distance == infinity) {
        std::cout << "infinity";
      } else {
        std::cout << prop.distance;
      }
      std::cout << "\n\t";
      if (prop.parent.empty()) {
        std::cout << "No parent";
      } else {
        std::cout << "Parent: " << prop.parent;
      }
      std::cout << std::endl;
    }
  } else {

    // If a target vertex is known, print path
    if (g[target_vertex].distance < infinity) {
      std::cout << "Path of length " << g[target_vertex].distance << ":\n\t";
    }
    print_path(g, source_vertex, target_vertex);
    std::cout << std::endl;
  }
  return EXIT_SUCCESS;
}
