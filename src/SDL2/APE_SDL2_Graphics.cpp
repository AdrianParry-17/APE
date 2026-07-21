#include "APE/SDL2/APE_SDL2_Graphics.h"

#include <SDL2/SDL.h>
#include <memory>

bool APE::SDL2::SDL2GraphicsEngine::Initialize() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        return false;

    SDL2Window* window = new SDL2Window;
    SDL2Renderer* renderer = new SDL2Renderer(window);

    m_window = std::shared_ptr<SDL2Window>(
        SDL2WindowBuilder()
            .Hide()
            .SetTitle("Game Window")
            .SetSize(Size(800, 500))
            .SetPosition(Point(SDL_WINDOWPOS_CENTERED))
            .Build());
    m_renderer = std::shared_ptr<SDL2Renderer>(renderer);

    return true;
}
bool APE::SDL2::SDL2GraphicsEngine::IsInitialized() const {
    return (bool)m_window && (bool)m_renderer;
}
void APE::SDL2::SDL2GraphicsEngine::Shutdown() {
    m_renderer.reset();
    m_window.reset();
}

void APE::SDL2::SDL2GraphicsEngine::Start() {
    if (!IsInitialized() || IsRunning())
        return;

    m_isRunning = true;
    SDL_Event e;
    
    GetWindow().lock()->Show();
    while (m_isRunning) {
        while (SDL_PollEvent(&e) != 0) {
            switch (e.type) {
            case SDL_QUIT:
                Stop();
                break;
            default:
                break;
            }
        }

        GetRenderer().lock()->Clear(KnownColor::Wisteria);
        GetRenderer().lock()->Present();
    }
    GetWindow().lock()->Hide();
}
void APE::SDL2::SDL2GraphicsEngine::Stop() {
    m_isRunning = false;
}
bool APE::SDL2::SDL2GraphicsEngine::IsRunning() const {
    return m_isRunning;
}

std::weak_ptr<APE::SDL2::SDL2Window> APE::SDL2::SDL2GraphicsEngine::GetWindow() {
    
}
