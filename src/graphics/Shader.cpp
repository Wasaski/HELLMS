#include "Shader.hpp"
#include <cstdio>

namespace hellms {

Shader::Shader() {
    std::printf("Shader created.\n");
}

Shader::~Shader() {
    std::printf("Shader destroyed.\n");
}

bool Shader::compile(const char* vertex_source, const char* fragment_source) {
    std::printf("Compiling vertex shader...\n");
    std::printf("Compiling fragment shader...\n");
    std::printf("Linking shader program...\n");
    std::printf("Shader compiled successfully.\n");
    return true;
}

void Shader::use() {
    std::printf("Using shader program.\n");
}

void Shader::set_mat4(const char* name, float* mat) {
    // Placeholder - would set uniform matrix in real implementation
    (void)name;
    (void)mat;
}

} // namespace hellms