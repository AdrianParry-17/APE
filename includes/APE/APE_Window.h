#ifndef __APE_WINDOW_H__
#define __APE_WINDOW_H__

#include "APE_Builder.h"
#include "APE_Structure.h"
#include "APE_Define.h"

#include <string>
#include <type_traits>

namespace APE {
    /// @brief The IWindow, provide an interface to create an APE window type.
    class IWindow {
    public:
        IWindow() = default;
        virtual ~IWindow() = default;
        
        APE_NOT_COPY_ASSIGNABLE(IWindow)

        /// @brief Make the window visible.
        virtual void Show();
        /// @brief Make the window invisible.
        virtual void Hide();

        /// @brief Set the position of the window.
        /// @param position The new position to set.
        virtual void SetPosition(const Point& position);
        /// @brief Get the position of the window.
        /// @return The position of the window.
        virtual Point GetPosition() const;

        /// @brief Set the size of the window.
        /// @param size The new size to set.
        virtual void SetSize(const Size& size);
        /// @brief Get the size of the window.
        /// @return The size of the window.
        virtual Size GetSize() const;

        /// @brief Set the title of the window.
        /// @param title The new title of the window.
        virtual void SetTitle(const std::string& title);
        /// @brief Get the title of the window.
        /// @return The title of the window.
        virtual std::string GetTitle() const;
    };

    /// @brief The Window Builder template, provide a builder for APE window.
    /// @tparam WindowT The type of the window, must be derived from the IWindow
    template <typename WindowT>
    class WindowBuilder : public IObjectBuilder<WindowT> {
    protected:
        WindowT* CreateObject() override;
    public:
        /// @brief Set the visible state of the window.
        /// @param visible true to make it visible, false otherwise.
        WindowBuilder<WindowT>& SetVisible(bool visible);

        /// @brief Make the window visible.
        WindowBuilder<WindowT>& Show();
        /// @brief Make the window invisible.
        WindowBuilder<WindowT>& Hide();

        /// @brief Set the position of the window.
        /// @param position The position to set.
        WindowBuilder<WindowT>& SetPosition(const Point& position);
        /// @brief Set the size of the window.
        /// @param size The size to set.
        WindowBuilder<WindowT>& SetSize(const Size& size);
        /// @brief Set the title of the window.
        /// @param title The title to set.
        WindowBuilder<WindowT>& SetTitle(const std::string& title);
    };
}


template <typename WindowT>
WindowT* APE::WindowBuilder<WindowT>::CreateObject() {
    static_assert(
        std::is_base_of<IWindow, WindowT>::value && !std::is_same<WindowT, IWindow>::value,
        "APE::WindowBuilder: The type of the window must be derived from IWindow!"
    );

    return new WindowT;
}

template <typename WindowT>
APE::WindowBuilder<WindowT>& APE::WindowBuilder<WindowT>::Show() {
    WindowT* window = this->GetObject();
    if (window) static_cast<IWindow*>(window)->Show();
    return *this;
}
template <typename WindowT>
APE::WindowBuilder<WindowT>& APE::WindowBuilder<WindowT>::Hide() {
    WindowT* window = this->GetObject();
    if (window) static_cast<IWindow*>(window)->Hide();
    return *this;
}
template <typename WindowT>
APE::WindowBuilder<WindowT>& APE::WindowBuilder<WindowT>::SetVisible(bool visible) {
    return visible ? Show() : Hide();
}
template <typename WindowT>
APE::WindowBuilder<WindowT>& APE::WindowBuilder<WindowT>::SetPosition(const Point& position) {
    WindowT* window = this->GetObject();
    if (window) static_cast<IWindow*>(window)->SetPosition(position);
    return *this;
}
template <typename WindowT>
APE::WindowBuilder<WindowT>& APE::WindowBuilder<WindowT>::SetSize(const Size& size) {
    WindowT* window = this->GetObject();
    if (window) static_cast<IWindow*>(window)->SetSize(size);
    return *this;
}
template <typename WindowT>
APE::WindowBuilder<WindowT>& APE::WindowBuilder<WindowT>::SetTitle(const std::string& title) {
    WindowT* window = this->GetObject();
    if (window) static_cast<IWindow*>(window)->SetTitle(title);
    return *this;
}

#endif // __APE_WINDOW_H__