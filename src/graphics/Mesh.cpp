#include "Mesh.hpp"
#include <cstdio>
#include <fstream>

namespace hellms {

Mesh::Mesh() {
    std::printf("Mesh created.\n");
}

Mesh::~Mesh() {
    std::printf("Mesh destroyed.\n");
}

bool Mesh::load_obj(const char* filepath) {
    std::printf("Loading OBJ mesh: %s\n", filepath);
    // Simple check - try to open the file
    std::ifstream file(filepath);
    if (file.is_open()) {
        file.close();
        std::printf("Mesh file found.\n");
        return true;
    }
    std::printf("Mesh file not found.\n");
    return false;
}

void Mesh::draw() {
    // Placeholder - real implementation would issue draw commands
    std::printf("Mesh: drawing.\n");
}
} // namespace hellms