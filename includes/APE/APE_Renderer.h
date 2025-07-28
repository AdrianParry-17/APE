#ifndef __APE_RENDERER_H__
#define __APE_RENDERER_H__

#include "APE/APE_Structure.h"
#include "APE_Define.h"
#include "APE_Color.h"
#include <vector>

namespace APE {
    /// @brief The Vertex struct, represent a two dimensional vertex.
    struct Vertex {
    public:
        /// @brief The Position of the Vertex. Default to Zero.
        Vector2 Position = Vector2::Zero;
        /// @brief The Color of the Vertex. Default to White.
        APE::Color Color = APE::KnownColor::White;
        /// @brief The Texture Position of the Vertex (from (0,0) to (1, 1)). Default to Zero.
        Vector2 TexturePosition = Vector2::Zero;

        Vertex() = default;
        Vertex(const Vector2& position, const APE::Color& color, const Vector2& texturePosition)
            : Position(position), Color(color), TexturePosition(texturePosition) {}
    };

    /// @brief The Sprite class, represent a two-dimensional sprite use for rendering.
    /// @note A sprite is made of triangles.
    class Sprite {
    private:
        std::vector<Vertex> m_vertices;
        std::vector<std::size_t> m_triangles;
    public:
        /// @brief Create a new empty Sprite.
        Sprite() = default;

        /// @brief Add a vertex to the sprite.
        /// @param vertex The vertex to add.
        void AddVertex(const Vertex& vertex);

        /// @brief Add a triangle by specifying indices of three vertices.
        /// @param i0 Index of the first vertex.
        /// @param i1 Index of the second vertex.
        /// @param i2 Index of the third vertex.
        void AddTriangle(std::size_t i0, std::size_t i1, std::size_t i2);

        /// @brief Count the number of vertices in the sprite.
        /// @return The number of vertices in the sprite.
        std::size_t VerticesCount() const;
        /// @brief Count the number of triangles indices in the sprite.
        /// @return The number of triangles indices in the sprite.
        std::size_t TrianglesCount() const;

        /// @brief Remove all vertices and triangles from the sprite.
        void Clear();

        /// @brief Get a const reference to the vertices.
        const std::vector<Vertex>& GetVertices() const;
        /// @brief Get a reference to the vertices.
        std::vector<Vertex>& GetVertices();

        /// @brief Get a const reference to the triangle indices.
        const std::vector<std::size_t>& GetTriangles() const;
        /// @brief Get a reference to the triangle indices.
        std::vector<std::size_t>& GetTriangles();
    };
    

    /// @brief The IRenderer, provide an interface to create an APE renderer type.
    class IRenderer {
    public:
        IRenderer() = default;
        virtual ~IRenderer() = default;
    
        APE_NOT_COPY_ASSIGNABLE(IRenderer)

        /// @brief Clear the renderer drawing area.
        /// @param color The clear color.
        virtual void Clear(const Color& color);
        /// @brief Display the drawing area to the output screen.
        virtual void Present();

        /// @brief Rendering a sprite to the drawing area.
        /// @param sprite The sprite to render.
        virtual void RenderSprite(const Sprite& sprite);
    };
}

#endif // __APE_RENDERER_H__