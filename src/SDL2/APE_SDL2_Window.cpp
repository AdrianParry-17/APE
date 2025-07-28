#include "APE/SDL2/APE_SDL2_Window.h"
#include "SDL_video.h"

//* --- APE::SDL2::SDL2Window ---

APE::SDL2::SDL2Window::SDL2Window() {
    m_data = SDL_CreateWindow(
        "Game Window",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        800, 500,
        SDL_WINDOW_HIDDEN
    );
}
APE::SDL2::SDL2Window::~SDL2Window() {
    if (m_data) SDL_DestroyWindow(m_data);
}

void APE::SDL2::SDL2Window::Show() {
    if (APE::SDL2::SDL2Window::m_data)
        SDL_ShowWindow(APE::SDL2::SDL2Window::m_data);
}
void APE::SDL2::SDL2Window::Hide() {
    if (APE::SDL2::SDL2Window::m_data)
        SDL_HideWindow(APE::SDL2::SDL2Window::m_data);
}

std::string APE::SDL2::SDL2Window::GetTitle() const {
    return APE::SDL2::SDL2Window::m_data ? SDL_GetWindowTitle(APE::SDL2::SDL2Window::m_data) : "";
}
void APE::SDL2::SDL2Window::SetTitle(const std::string& Title) {
    if (APE::SDL2::SDL2Window::m_data)
        SDL_SetWindowTitle(APE::SDL2::SDL2Window::m_data, Title.c_str());
}

APE::Point APE::SDL2::SDL2Window::GetPosition() const {
    if (!APE::SDL2::SDL2Window::m_data) return Point::Zero;
    int x = 0, y = 0;
    SDL_GetWindowPosition(APE::SDL2::SDL2Window::m_data, &x, &y);
    return Point(x, y);
}
void APE::SDL2::SDL2Window::SetPosition(const APE::Point& position) {
    if (APE::SDL2::SDL2Window::m_data)
        SDL_SetWindowPosition(APE::SDL2::SDL2Window::m_data, position.X, position.Y);
}

APE::Size APE::SDL2::SDL2Window::GetSize() const {
    if (!APE::SDL2::SDL2Window::m_data) return Size::Zero;
    int w = 0, h = 0;
    SDL_GetWindowSize(APE::SDL2::SDL2Window::m_data, &w, &h);
    return APE::Size(w, h);
}
void APE::SDL2::SDL2Window::SetSize(const APE::Size& size) {
    if (APE::SDL2::SDL2Window::m_data && !size.IsEmptyArea())
        SDL_SetWindowSize(APE::SDL2::SDL2Window::m_data, size.Width, size.Height);
}

double APE::SDL2::SDL2Window::GetRatio() const {
    if (!APE::SDL2::SDL2Window::m_data) return 0;
    int w = 0, h = 0;
    SDL_GetWindowSize(APE::SDL2::SDL2Window::m_data, &w, &h);
    if (w == 0 || h == 0) return 0;
    return (double)w / (double)h;
}

APE::SDL2::SDL2WindowFlags APE::SDL2::SDL2Window::GetFlags() const {
    return APE::SDL2::SDL2Window::m_data ? static_cast<SDL2WindowFlags>(SDL_GetWindowFlags(APE::SDL2::SDL2Window::m_data)) : SDL2WindowFlags::Unknown;
}
uint32_t APE::SDL2::SDL2Window::GetID() const {
    return APE::SDL2::SDL2Window::m_data ? SDL_GetWindowID(APE::SDL2::SDL2Window::m_data) : 0;
}

APE::Size APE::SDL2::SDL2Window::GetMinimumSize() const {
    if (!APE::SDL2::SDL2Window::m_data) return Size::Zero;
    int w = 0, h = 0;
    SDL_GetWindowMinimumSize(APE::SDL2::SDL2Window::m_data, &w, &h);
    return APE::Size(w, h);
}
void APE::SDL2::SDL2Window::SetMinimumSize(const APE::Size& size) {
    if (APE::SDL2::SDL2Window::m_data && !size.IsEmptyArea())
        SDL_SetWindowMinimumSize(APE::SDL2::SDL2Window::m_data, size.Width, size.Height);
}

APE::Size APE::SDL2::SDL2Window::GetMaximumSize() const {
    if (!APE::SDL2::SDL2Window::m_data) return Size::Zero;
    int w = 0, h = 0;
    SDL_GetWindowMaximumSize(APE::SDL2::SDL2Window::m_data, &w, &h);
    return APE::Size(w, h);
}
void APE::SDL2::SDL2Window::SetMaximumSize(const APE::Size& Size) {
    if (APE::SDL2::SDL2Window::m_data && !Size.IsEmptyArea())
        SDL_SetWindowMaximumSize(APE::SDL2::SDL2Window::m_data, Size.Width, Size.Height);
}

bool APE::SDL2::SDL2Window::IsResizable() const {
    return (static_cast<uint64_t>(GetFlags()) & SDL_WINDOW_RESIZABLE) != 0;
}
void APE::SDL2::SDL2Window::EnableResizing() {
    if (APE::SDL2::SDL2Window::m_data)
        SDL_SetWindowResizable(APE::SDL2::SDL2Window::m_data, SDL_TRUE);
}
void APE::SDL2::SDL2Window::DisableResizing() {
    if (APE::SDL2::SDL2Window::m_data)
        SDL_SetWindowResizable(APE::SDL2::SDL2Window::m_data, SDL_FALSE);
}

bool APE::SDL2::SDL2Window::IsVisible() const {
    return (static_cast<uint64_t>(APE::SDL2::SDL2Window::GetFlags()) & SDL_WINDOW_SHOWN) != 0;
}


bool APE::SDL2::SDL2Window::IsFullscreen() const {
    return (static_cast<uint64_t>(GetFlags()) & SDL_WINDOW_FULLSCREEN) != 0;
}
void APE::SDL2::SDL2Window::MakeFullscreen(bool RealFullscreen) {
    if (APE::SDL2::SDL2Window::m_data)
        SDL_SetWindowFullscreen(APE::SDL2::SDL2Window::m_data, RealFullscreen ? SDL_WINDOW_FULLSCREEN : SDL_WINDOW_FULLSCREEN_DESKTOP);
}
void APE::SDL2::SDL2Window::RestoreFromFullscreen() {
    if (APE::SDL2::SDL2Window::m_data)
        SDL_RestoreWindow(APE::SDL2::SDL2Window::m_data);
}

bool APE::SDL2::SDL2Window::IsBordered() const {
    return (static_cast<uint64_t>(GetFlags()) & SDL_WINDOW_BORDERLESS) == 0;
}
void APE::SDL2::SDL2Window::MakeBordered() {
    if (APE::SDL2::SDL2Window::m_data)
        SDL_SetWindowBordered(APE::SDL2::SDL2Window::m_data, SDL_TRUE);
}
void APE::SDL2::SDL2Window::MakeBorderless() {
    if (APE::SDL2::SDL2Window::m_data)
        SDL_SetWindowBordered(APE::SDL2::SDL2Window::m_data, SDL_FALSE);
}

void APE::SDL2::SDL2Window::EnableAlwaysOnTop() {
    if (APE::SDL2::SDL2Window::m_data)
        SDL_SetWindowAlwaysOnTop(APE::SDL2::SDL2Window::m_data, SDL_TRUE);
}
void APE::SDL2::SDL2Window::DisableAlwaysOnTop() {
    if (APE::SDL2::SDL2Window::m_data)
        SDL_SetWindowAlwaysOnTop(APE::SDL2::SDL2Window::m_data, SDL_FALSE);
}
bool APE::SDL2::SDL2Window::IsAlwaysOnTop() const {
    return (static_cast<uint64_t>(GetFlags()) & SDL_WINDOW_ALWAYS_ON_TOP) != 0;
}

void APE::SDL2::SDL2Window::RaiseWindow() {
    if (APE::SDL2::SDL2Window::m_data)
        SDL_RaiseWindow(APE::SDL2::SDL2Window::m_data);
}

//* --- APE::SDL2::SDL2WindowBuilder ---

/// @brief Set the visible state of the window.
/// @param visible true to make it visible, false otherwise.
APE::SDL2::SDL2WindowBuilder& APE::SDL2::SDL2WindowBuilder::SetVisible(bool visible) {
    return visible ? Show() : Hide();
}
APE::SDL2::SDL2WindowBuilder& APE::SDL2::SDL2WindowBuilder::Show() {
    SDL2Window* window = GetObject();
    if (window) window->Show();
    return *this;
}
APE::SDL2::SDL2WindowBuilder& APE::SDL2::SDL2WindowBuilder::Hide() {
    SDL2Window* window = GetObject();
    if (window) window->Hide();
    return *this;
}

APE::SDL2::SDL2WindowBuilder& APE::SDL2::SDL2WindowBuilder::SetPosition(const Point& position) {
    SDL2Window* window = GetObject();
    if (window) window->SetPosition(position);
    return *this;
}
APE::SDL2::SDL2WindowBuilder& APE::SDL2::SDL2WindowBuilder::SetSize(const Size& size) {
    SDL2Window* window = GetObject();
    if (window) window->SetSize(size);
    return *this;
}
APE::SDL2::SDL2WindowBuilder& APE::SDL2::SDL2WindowBuilder::SetTitle(const std::string& title) {
    SDL2Window* window = GetObject();
    if (window) window->SetTitle(title);
    return *this;
}

APE::SDL2::SDL2WindowBuilder& APE::SDL2::SDL2WindowBuilder::SetMinimumSize(const Size& size) {
    SDL2Window* window = GetObject();
    if (window) window->SetMinimumSize(size);
    return *this;
}
APE::SDL2::SDL2WindowBuilder& APE::SDL2::SDL2WindowBuilder::SetMaximumSize(const Size& size) {
    SDL2Window* window = GetObject();
    if (window) window->SetMaximumSize(size);
    return *this;
}

APE::SDL2::SDL2WindowBuilder& APE::SDL2::SDL2WindowBuilder::SetResizableState(bool resizable) {
    return resizable ? EnableResizing() : DisableResizing();
}
APE::SDL2::SDL2WindowBuilder& APE::SDL2::SDL2WindowBuilder::EnableResizing() {
    SDL2Window* window = GetObject();
    if (window) window->EnableResizing();
    return *this;
}
APE::SDL2::SDL2WindowBuilder& APE::SDL2::SDL2WindowBuilder::DisableResizing() {
    SDL2Window* window = GetObject();
    if (window) window->DisableResizing();
    return *this;
}

APE::SDL2::SDL2WindowBuilder& APE::SDL2::SDL2WindowBuilder::MakeFullscreen(bool realFullscreen) {
    SDL2Window* window = GetObject();
    if (window) window->MakeFullscreen(realFullscreen);
    return *this;
}
APE::SDL2::SDL2WindowBuilder& APE::SDL2::SDL2WindowBuilder::RestoreFromFullscreen() {
    SDL2Window* window = GetObject();
    if (window) window->RestoreFromFullscreen();
    return *this;
}

APE::SDL2::SDL2WindowBuilder& APE::SDL2::SDL2WindowBuilder::SetBorderedState(bool bordered) {
    return bordered ? MakeBordered() : MakeBorderless();
}
APE::SDL2::SDL2WindowBuilder& APE::SDL2::SDL2WindowBuilder::MakeBordered() {
    SDL2Window* window = GetObject();
    if (window) window->MakeBordered();
    return *this;
}
APE::SDL2::SDL2WindowBuilder& APE::SDL2::SDL2WindowBuilder::MakeBorderless() {
    SDL2Window* window = GetObject();
    if (window) window->MakeBorderless();
    return *this;
}

APE::SDL2::SDL2WindowBuilder& APE::SDL2::SDL2WindowBuilder::SetAlwaysOnTopState(bool always_on_top) {
    return always_on_top ? EnableAlwaysOnTop() : DisableAlwaysOnTop();
}
APE::SDL2::SDL2WindowBuilder& APE::SDL2::SDL2WindowBuilder::EnableAlwaysOnTop() {
    SDL2Window* window = GetObject();
    if (window) window->EnableAlwaysOnTop();
    return *this;
}
APE::SDL2::SDL2WindowBuilder& APE::SDL2::SDL2WindowBuilder::DisableAlwaysOnTop() {
    SDL2Window* window = GetObject();
    if (window) window->DisableAlwaysOnTop();
    return *this;
}

APE::SDL2::SDL2WindowBuilder& APE::SDL2::SDL2WindowBuilder::RaiseWindow() {
    SDL2Window* window = GetObject();
    if (window) window->RaiseWindow();
    return *this;
}