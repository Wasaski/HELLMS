class Mesh;

namespace hellms {

class Mesh {
public:
    Mesh();
    ~Mesh();

    bool load_obj(const char* filepath);
    void draw();
};
} // namespace hellms