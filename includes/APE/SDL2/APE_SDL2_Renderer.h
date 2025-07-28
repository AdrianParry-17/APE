#ifndef __APE_SDL2_RENDERER_H__
#define __APE_SDL2_RENDERER_H__

#include "../APE_Renderer.h"

#include <SDL2/SDL_render.h>

namespace APE {
    namespace SDL2 {
        /// @brief The SDL2 Draw Blend Mode enum class, the mode use for blending operation of SDL2 Renderer.
        enum class SDL2DrawBlendMode {
            None = SDL_BLENDMODE_NONE,
            AlphaBlend = SDL_BLENDMODE_BLEND,
            Additive = SDL_BLENDMODE_ADD,
            Modulate = SDL_BLENDMODE_MOD,
            Multiply = SDL_BLENDMODE_MUL,
            Invalid = SDL_BLENDMODE_INVALID
        };

        /// @brief The SDL2 Renderer class, provide an APE renderer that wrap the SDL2 renderer.
        class SDL2Renderer : public IRenderer {
        private:
            SDL_Renderer* m_data = nullptr;
        public:
            /// @brief Get the current draw blend mode of the SDL2 Renderer.
            /// @return The current draw blend mode of the SDL2 Renderer, or Invalid on failed.
            SDL2DrawBlendMode GetDrawBlendMode() const;
            /// @brief Set the current draw blend mode of the SDL2 Renderer.
            /// @param blendMode The draw blend mode to set.
            void SetDrawBlendMode(SDL2DrawBlendMode blendMode);

            /// @brief Get the output size of the SDL2 Renderer.
            /// @return The output size of the SDL2 Renderer, or Size::Zero on failed.
            Size GetOutputSize() const;

            /// @brief Get the current drawing area of the SDL2 Renderer.
            /// @return The current drawing area of the SDL2 Renderer, or Rectangle::Empty on failed.
            Rectangle GetViewport() const;
            /// @brief Set the drawing area of the SDL2 Renderer.
            /// @param area The Rectangle represent the drawing area to set, will not set if the area is empty.
            void SetViewport(const Rectangle& area);
            /// @brief Reset the drawing area to the entire drawing surface.
            void ResetViewport();

            /// @brief Set the current clip area of the SDL2 Renderer.
            /// @param area The area to set, will do nothing if empty.
            /// @note Clip area is differents from viewport, since viewport is the output area (meaning drawing at
            /// (0, 0) is at the top-left point of the viewport), while clip area will simply not draw a point
            /// that outside the clip area.
            void SetClipArea(const Rectangle& area);
            /// @brief Get the current clip area of the SDL2 Renderer.
            /// @return The clip area of the SDL2 Renderer, or Rectangle::Empty if not clipped.
            /// @note Clip area is differents from viewport, since viewport is the output area (meaning drawing at
            /// (0, 0) is at the top-left point of the viewport), while clip area will simply not draw a point
            /// that outside the clip area.
            Rectangle GetClipArea() const;
            /// @brief Disable clipping for the SDL2 Renderer.
            void DisableClip();
            /// @brief Check if the SDL2 Renderer has clipping enabled.
            /// @return true if clipping is enabled, false otherwise.
            bool IsClipEnabled() const;

            /// @brief Clear the entire drawing area.
            /// @param color The clear color to use.
            void Clear(const Color& color) override;
            /// @brief Display the drawing area to the output.
            void Present() override;

            /// @brief Draw a point at specific position.
            /// @param position The position of the point to draw.
            void DrawPoint(const Point& position);

            /// @brief Draw a line to the drawing area.
            /// @param start The position of the start point.
            /// @param end The position of the end point.
            void DrawLine(const Point& start, const Point& end);

            /// @brief Draw a rectangle to the drawing area.
            /// @param area The area of the Rectangle to draw, will not draw if the area is empty.
            void DrawRectangle(const Rectangle& area);
            /// @brief Draw a rounded-corner rectangle to the drawing area.
            /// @param area The area of the Rectangle to draw, will not draw if the area is empty.
            /// @param radius The radius of the rounded-corner.
            void DrawRoundedRectangle(const Rectangle& area, int radius);

            /// @brief Fill a rectangle to the drawing area.
            /// @param area The area of the Rectangle to draw, will not draw if the area is empty.
            void FillRectangle(const Rectangle& area);
            /// @brief Fill a rounded-corner rectangle to the drawing area.
            /// @param area The area of the Rectangle to draw, will not draw if the area is empty.
            /// @param radius The radius of the rounded-corner.
            void FillRoundedRectangle(const Rectangle& area, int radius);

            /// @brief Draw a circle to the drawing area.
            /// @param center The position of the center of the circle.
            /// @param radius The radius of the circle, will not draw if this value is 0.
            void DrawCircle(const Point& center, int radius);
            /// @brief Draw an ellipse to the drawing area.
            /// @param center The position of the center of the ellipse.
            /// @param radiusX The radius of the ellipse in the x direction, will not draw if this value is 0.
            /// @param radiusY The radius of the ellipse in the y direction, will not draw if this value is 0.
            void DrawEllipse(const Point& center, int radiusX, int radiusY);

            /// @brief Fill a circle to the drawing area.
            /// @param center The position of the center of the circle.
            /// @param radius The radius of the circle, will not fill if this value is 0.
            void FillCircle(const Point& center, int radius);
            /// @brief Fill an ellipse to the drawing area.
            /// @param center The position of the center of the ellipse.
            /// @param radiusX The radius of the ellipse in the x direction, will not fill if this value is 0.
            /// @param radiusY The radius of the ellipse in the y direction, will not fill if this value is 0.
            void FillEllipse(const Point& center, int radiusX, int radiusY);

            /// @brief Rendering a sprite to the drawing area.
            /// @param sprite The sprite to render.
            void RenderSprite(const Sprite& sprite) override;
        };
    }
}

#endif // __APE_SDL2_RENDERER_H__