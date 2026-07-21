#include "APE/APE_Renderer.h"

//* --- APE::Sprite ---

void APE::Sprite::AddVertex(const APE::Vertex& vertex) {
    m_vertices.push_back(vertex);
}

void APE::Sprite::AddTriangle(std::size_t i0, std::size_t i1, std::size_t i2) {
    m_triangles.push_back(i0);
    m_triangles.push_back(i1);
    m_triangles.push_back(i2);
}

void APE::Sprite::Clear() {
    m_vertices.clear();
    m_triangles.clear();
}

std::size_t APE::Sprite::VerticesCount() const { return m_vertices.size(); }
std::size_t APE::Sprite::TrianglesCount() const { return m_triangles.size(); }

const std::vector<APE::Vertex>& APE::Sprite::GetVertices() const { return m_vertices; }
std::vector<APE::Vertex>& APE::Sprite::GetVertices() { return m_vertices; }

const std::vector<std::size_t>& APE::Sprite::GetTriangles() const { return m_triangles; }
std::vector<std::size_t>& APE::Sprite::GetTriangles() { return m_triangles; }