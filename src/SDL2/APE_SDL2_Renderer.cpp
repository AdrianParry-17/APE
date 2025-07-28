#include "APE/SDL2/APE_SDL2_Renderer.h"
#include "SDL_video.h"

#include <algorithm>
#include <stdexcept>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL2_gfxPrimitives.h>

//* --- APE::SDL2::SDL2Renderer ---

APE::SDL2::SDL2Renderer::SDL2Renderer(SDL2Window* window) {
    if (!window)
        throw std::runtime_error("SDL2Renderer: Invalid SDL2Window to create!");
    
    std::size_t win_id = window->GetID();
    SDL_Window* sdl_window = SDL_GetWindowFromID(win_id);
    
    if (!sdl_window)
        throw std::runtime_error("SDL2Renderer: Invalid SDL2Window to create!");
    SDL_Renderer* renderer = SDL_GetRenderer(sdl_window);
    if (renderer)
        throw std::runtime_error("SDL2Renderer: An SDL2Window can only have one renderer!");

    m_data = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
}
APE::SDL2::SDL2Renderer::~SDL2Renderer() {
    if (m_data)
        SDL_DestroyRenderer(m_data);
}

APE::SDL2::SDL2DrawBlendMode APE::SDL2::SDL2Renderer::GetDrawBlendMode() const {
    if (!m_data) return SDL2DrawBlendMode::Invalid;
    SDL_BlendMode tmp = SDL_BLENDMODE_INVALID;
    SDL_GetRenderDrawBlendMode(m_data, &tmp);
    return static_cast<SDL2DrawBlendMode>(tmp);
}
void APE::SDL2::SDL2Renderer::SetDrawBlendMode(SDL2DrawBlendMode BlendMode) {
    if (m_data)
        SDL_SetRenderDrawBlendMode(m_data, static_cast<SDL_BlendMode>(BlendMode));
}

APE::Size APE::SDL2::SDL2Renderer::GetOutputSize() const {
    if (!m_data) return Size::Zero;
    int w = 0, h = 0;
    SDL_GetRendererOutputSize(m_data, &w, &h);
    return Size(w, h);
}
APE::Rectangle APE::SDL2::SDL2Renderer::GetViewport() const {
    if (!m_data) return Rectangle::Empty;
    SDL_Rect tmp = { 0, 0, 0, 0 };
    SDL_RenderGetViewport(m_data, &tmp);
    return Rectangle(tmp.x, tmp.y, tmp.w, tmp.h);
}
void APE::SDL2::SDL2Renderer::SetViewport(const APE::Rectangle& area) {
    if (!m_data || area.IsEmptyArea()) return;
    SDL_Rect tmp = { area.LeftSide(), area.TopSide(), abs(area.Width), abs(area.Height) };
    SDL_RenderSetViewport(m_data, &tmp);
}
void APE::SDL2::SDL2Renderer::ResetViewport() {
    if (m_data)
        SDL_RenderSetViewport(m_data, nullptr);
}


void APE::SDL2::SDL2Renderer::SetClipArea(const APE::Rectangle& area) {
    if (!m_data || area.IsEmptyArea()) return;
    SDL_Rect tmp = { area.LeftSide(), area.TopSide(), abs(area.Width), abs(area.Height) };
    SDL_RenderSetClipRect(m_data, &tmp);
}
APE::Rectangle APE::SDL2::SDL2Renderer::GetClipArea() const {
    if (!IsClipEnabled()) return Rectangle::Empty;
    SDL_Rect tmp = { 0, 0, 0, 0 };
    SDL_RenderGetClipRect(m_data, &tmp);
    return Rectangle(tmp.x, tmp.y, tmp.w, tmp.h);
}
void APE::SDL2::SDL2Renderer::DisableClip() {
    if (m_data)
        SDL_RenderSetClipRect(m_data, nullptr);
}
bool APE::SDL2::SDL2Renderer::IsClipEnabled() const {
    return m_data ? SDL_RenderIsClipEnabled(m_data) == SDL_TRUE : false;
}


void APE::SDL2::SDL2Renderer::Clear(const Color& color) {
    if (!m_data) return;
    SDL_SetRenderDrawColor(m_data, color.Red, color.Green, color.Blue, color.Alpha);
    SDL_RenderClear(m_data);
}
void APE::SDL2::SDL2Renderer::Present() {
    if (m_data)
        SDL_RenderPresent(m_data);
}


void APE::SDL2::SDL2Renderer::DrawPoint(const APE::Point& position) {
    if (m_data)
        SDL_RenderDrawPoint(m_data, position.X, position.Y);
}
void APE::SDL2::SDL2Renderer::DrawLine(const APE::Point& start, const APE::Point& end) {
    if (m_data)
        SDL_RenderDrawLine(m_data, start.X, start.Y, end.X, end.Y);
}

void APE::SDL2::SDL2Renderer::DrawRectangle(const APE::Rectangle& area) {
    if (!m_data || area.IsEmptyArea()) return;
    SDL_Rect tmp = { area.LeftSide(), area.TopSide(), abs(area.Width), abs(area.Height) };
    SDL_RenderDrawRect(m_data, &tmp);
}
void APE::SDL2::SDL2Renderer::DrawRoundedRectangle(const APE::Rectangle& area, int radius) {
    if (!m_data || area.IsEmptyArea()) return;
    if (radius <= 0) return DrawRectangle(area);
    
    uint8_t r = 0, g = 0, b = 0, a = 0;
    SDL_GetRenderDrawColor(m_data, &r, &g, &b, &a);

    roundedRectangleRGBA(m_data,
        area.LeftSide(), area.TopSide(), area.RightSide(), area.BottomSide(), radius,
        r, g, b, a);
}

void APE::SDL2::SDL2Renderer::FillRectangle(const APE::Rectangle& area) {
    if (!m_data) return;
    SDL_Rect tmp = { area.LeftSide(), area.TopSide(), abs(area.Width), abs(area.Height) };
    SDL_RenderFillRect(m_data, &tmp);
}
void APE::SDL2::SDL2Renderer::FillRoundedRectangle(const APE::Rectangle& area, int radius) {
    if (!m_data) return;
    if (radius <= 0) return FillRectangle(area);

    uint8_t r = 0, g = 0, b = 0, a = 0;
    SDL_GetRenderDrawColor(m_data, &r, &g, &b, &a);

    roundedBoxRGBA(m_data,
        area.LeftSide(), area.TopSide(), area.RightSide(), area.BottomSide(), radius,
        r, g, b, a);
}

void APE::SDL2::SDL2Renderer::DrawCircle(const APE::Point& center, int radius) {
    if (!m_data || radius == 0) return;

    uint8_t r = 0, g = 0, b = 0, a = 0;
    SDL_GetRenderDrawColor(m_data, &r, &g, &b, &a);

    circleRGBA(m_data, center.X, center.Y, radius, r, g, b, a);
}
void APE::SDL2::SDL2Renderer::DrawEllipse(const APE::Point& center, int radiusX, int radiusY) {
    if (!m_data || radiusX == 0 || radiusY == 0) return;

    uint8_t r = 0, g = 0, b = 0, a = 0;
    SDL_GetRenderDrawColor(m_data, &r, &g, &b, &a);

    ellipseRGBA(m_data, center.X, center.Y, radiusX, radiusY, r, g, b, a);
}

void APE::SDL2::SDL2Renderer::FillCircle(const APE::Point& center, int radius) {
    if (!m_data || radius == 0) return;

    uint8_t r = 0, g = 0, b = 0, a = 0;
    SDL_GetRenderDrawColor(m_data, &r, &g, &b, &a);

    filledCircleRGBA(m_data, center.X, center.Y, radius, r, g, b, a);
}
void APE::SDL2::SDL2Renderer::FillEllipse(const APE::Point& center, int radiusX, int radiusY) {
    if (!m_data || radiusX == 0 || radiusY == 0) return;

    uint8_t r = 0, g = 0, b = 0, a = 0;
    SDL_GetRenderDrawColor(m_data, &r, &g, &b, &a);

    filledEllipseRGBA(m_data, center.X, center.Y, radiusX, radiusY, r, g, b, a);
}

void APE::SDL2::SDL2Renderer::RenderSprite(const Sprite& sprite) {
    if (!m_data || sprite.TrianglesCount() < 3 || sprite.VerticesCount() <= 0) return;

    auto& s_vertices = sprite.GetVertices();
    auto& s_triangles = sprite.GetTriangles();

    std::vector<SDL_Vertex> vertices(s_vertices.size());
    std::vector<int> indices(s_triangles.size());

    std::copy(s_triangles.begin(), s_triangles.end(), indices.begin());
    std::transform(s_vertices.begin(), s_vertices.end(), vertices.begin(), [](const Vertex& vertex) {
        return SDL_Vertex{
            SDL_FPoint{(float)vertex.Position.X, (float)vertex.Position.Y},
            SDL_Color{vertex.Color.Red, vertex.Color.Green, vertex.Color.Blue, vertex.Color.Alpha},
            SDL_FPoint{(float)vertex.TexturePosition.X, (float)vertex.TexturePosition.Y}
        };
    });

    SDL_RenderGeometry(
        m_data, nullptr,
        vertices.data(), vertices.size(),
        indices.empty() ? nullptr : indices.data(), indices.size()
    );
}