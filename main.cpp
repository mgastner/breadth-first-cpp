#include "parse_arguments.hpp"
#include "vertex_properties.hpp"
#include <queue>

int main(const int argc, const char *argv[])
{
  // Parse arguments
  std::string adj_list_json_file, end_vertex, start_vertex;
  argparse::ArgumentParser arguments =
    parsed_arguments(argc, argv, adj_list_json_file, start_vertex, end_vertex);

  // Import data. All vertices are initialized as being undiscovered.
  const std::map<std::string, VertexProperties> v =
    vertices(adj_list_json_file);

  // Debug output
  for (auto &[id, prop] : v) {
    std::cout << "id = " << id << ", "
              //<< "prop.adjacent_vertices = " << prop.adjacent_vertices << ", "
              << "prop.parent = " << prop.parent << ", "
              << "prop.distance = " << prop.distance << std::endl;
  }

  // Initialize queue
  std::queue<std::string> q;
  q.push(start_vertex);
  return EXIT_SUCCESS;
}
