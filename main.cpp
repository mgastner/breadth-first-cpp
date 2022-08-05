#include "parse_arguments.hpp"
#include "print_path.hpp"
#include "vertex_properties.hpp"
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
  auto v = vertices(adj_list_json_file);
  std::queue<std::string> q;

  // Discover the source
  q.push(source_vertex);
  v[source_vertex].distance = 0;

  // Breadth-first search
  while (!q.empty()) {
    auto focal_vertex = q.front();
    q.pop();
    for (const auto &adj_vertex : v[focal_vertex].adjacent_vertices) {
      if (v[adj_vertex].distance == std::numeric_limits<unsigned int>::max()) {
        q.push(adj_vertex);
        v[adj_vertex].distance = v[focal_vertex].distance + 1;
        v[adj_vertex].parent = focal_vertex;
      }
    }
  }

  // Output
  std::cout << "\n";

  if (target_vertex.empty()) {

    // If no target vertex is given, print distance and parent of all vertices
    for (const auto &[id, prop] : v) {
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
    print_path(source_vertex, target_vertex);
  }
  return EXIT_SUCCESS;
}
