#include "APE/APE_Window.h"

#include <stdexcept>

void APE::IWindow::Show() {
    throw std::runtime_error("APE::IWindow::Show: Not implemented!");
}
void APE::IWindow::Hide() {
    throw std::runtime_error("APE::IWindow::Hide: Not implemented!");
}

void APE::IWindow::SetPosition(const Point& position) {
    throw std::runtime_error("APE::IWindow::SetPosition: Not implemented!");
}
APE::Point APE::IWindow::GetPosition() const {
    throw std::runtime_error("APE::IWindow::GetPosition: Not implemented!");
}

void APE::IWindow::SetSize(const Size& size) {
    throw std::runtime_error("APE::IWindow::SetSize: Not implemented!");
}
APE::Size APE::IWindow::GetSize() const {
    throw std::runtime_error("APE::IWindow::GetSize: Not implemented!");
}

void APE::IWindow::SetTitle(const std::string& title) {
    throw std::runtime_error("APE::IWindow::SetTitle: Not implemented!");
}
std::string APE::IWindow::GetTitle() const {
    throw std::runtime_error("APE::IWindow::GetTitle: Not implemented!");
}