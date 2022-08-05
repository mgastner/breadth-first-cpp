#include "parse_arguments.hpp"
#include "vertex_properties.hpp"
#include <queue>

int main(const int argc, const char *argv[])
{
  // Parse arguments
  std::string adj_list_json_file, end_vertex, start_vertex;
  auto arguments =
    parsed_arguments(argc, argv, adj_list_json_file, start_vertex, end_vertex);

  // Import data. All vertices are initialized as being undiscovered.
  auto v = vertices(adj_list_json_file);
  std::queue<std::string> q;

  // Discover the source
  q.push(start_vertex);
  v[start_vertex].distance = 0;

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
  return EXIT_SUCCESS;
}
