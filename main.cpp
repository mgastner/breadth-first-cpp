#include "adjacency_list.hpp"
#include "parse_arguments.hpp"

struct VertexProperties {

  // The default of std::string is an empty string. We use an empty string
  // as a sign that the parent is not known.
  std::string parent;

  // Largest possible unsigned int as symbol of infinite distance
  unsigned int distance = std::numeric_limits<unsigned int>::max();
};

int main(const int argc, const char *argv[])
{
  // Parse arguments
  std::string adj_list_json_file, end_vertex, start_vertex;
  argparse::ArgumentParser arguments =
    parsed_arguments(argc, argv, adj_list_json_file, start_vertex, end_vertex);

  // Import data
  const AdjacencyList adj_list = adjacency_list(adj_list_json_file);

  // Initialize all vertices as undiscovered
  std::map<std::string, VertexProperties> vertex_status;
  for (const auto &adj_list_entry : adj_list) {
    std::pair<std::string, VertexProperties> vertex_info =
      std::make_pair(adj_list_entry.first, VertexProperties());
    vertex_status.insert(vertex_info);
  }

  // Debug output
  for (auto &[id, prop] : vertex_status) {
    std::cout << "id = " << id << ", "
              << "parent = " << prop.parent << ", "
              << "distance = " << prop.distance << std::endl;
  }
  return EXIT_SUCCESS;
}
