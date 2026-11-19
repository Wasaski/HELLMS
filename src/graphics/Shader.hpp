class Shader;

namespace hellms {

class Shader {
public:
    Shader();
    ~Shader();

    bool compile(const char* vertex_source, const char* fragment_source);
    void use();
    void set_mat4(const char* name, float* mat);
};

} // namespace hellms