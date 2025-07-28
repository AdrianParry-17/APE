#ifndef __APE_SDL2_WINDOW_H__
#define __APE_SDL2_WINDOW_H__

#include "../APE_Structure.h"
#include "../APE_Window.h"

#include <SDL2/SDL_video.h>

namespace APE {
    namespace SDL2 {
        class SDL2Renderer;

        /// @brief The SDL2 Window Flags enum, use to identify the flags of an SDL2 window.
        enum class SDL2WindowFlags {
            /// @brief Unknown flags.
            Unknown = 0,

            /// @brief The window is fullscreen.
            Fullscreen = SDL_WINDOW_FULLSCREEN,
            /// @brief The window is usable with OpenGL context.
            OpenGL = SDL_WINDOW_OPENGL,
            /// @brief The window is visible.
            Shown = SDL_WINDOW_SHOWN,
            /// @brief The window is not visible.
            Hidden = SDL_WINDOW_HIDDEN,
            /// @brief The window has no border decoration.
            Borderless = SDL_WINDOW_BORDERLESS,
            /// @brief The window can be resized by the user.
            Resizable = SDL_WINDOW_RESIZABLE,
            /// @brief The window is minimized.
            Minimized = SDL_WINDOW_MINIMIZED,
            /// @brief The window is maximized.
            Maximized = SDL_WINDOW_MAXIMIZED,
            /// @brief The window has grabbed mouse input.
            MouseGrabbed = SDL_WINDOW_MOUSE_GRABBED,
            /// @brief The window has input focus.
            InputFocus = SDL_WINDOW_INPUT_FOCUS,
            /// @brief The window has mouse focus.
            MouseFocus = SDL_WINDOW_MOUSE_FOCUS,
            /// @brief The window is fullscreen in desktop mode (fullscreen but take the desktop size as window size).
            FullscreenDesktop = SDL_WINDOW_FULLSCREEN_DESKTOP,
            Foreign = SDL_WINDOW_FOREIGN,
            /// @brief The window is created in high-DPI mode (if supported).
            AllowHighDPI = SDL_WINDOW_ALLOW_HIGHDPI,
            /// @brief The window has mouse captured.
            MouseCapture = SDL_WINDOW_MOUSE_CAPTURE,
            /// @brief The window is always be above others.
            AlwaysOnTop = SDL_WINDOW_ALWAYS_ON_TOP,
            /// @brief The window is not added to the taskbar.
            SkipTaskbar = SDL_WINDOW_SKIP_TASKBAR,
            /// @brief The window is treated as a utility window.
            Utility = SDL_WINDOW_UTILITY,
            /// @brief The window is treated as a tooltip.
            Tooltip = SDL_WINDOW_TOOLTIP,
            /// @brief The window is treated as a popup menu.
            PopupMenu = SDL_WINDOW_POPUP_MENU,
            /// @brief The window has grabbed keyboard input.
            KeyboardGrabbed = SDL_WINDOW_KEYBOARD_GRABBED,
            /// @brief The window is usable with Vulkan surface.
            Vulkan = SDL_WINDOW_VULKAN,
            /// @brief The window is usable with Metal view.
            Metal = SDL_WINDOW_METAL
        };
        APE_DEFINE_ENUM_OPERATORS(SDL2WindowFlags)

        /// @brief The SDL2 Window class, provide an APE window that wrap the SDL2 window.
        class SDL2Window : public IWindow {
        private:
            SDL_Window* m_data = nullptr;
        public:
            /// @brief Create a new SDL2 Window.
            SDL2Window();
            virtual ~SDL2Window();

            APE_NOT_COPY_ASSIGNABLE(SDL2Window)

            /// @brief Get the title of the SDL2 Window.
            /// @return The title of the SDL2 Window, or an empty string ("") on failed or there's no title.
            std::string GetTitle() const override;
            /// @brief Set the title of the SDL2 Window.
            /// @param title The title of the SDL2 Window.
            void SetTitle(const std::string& title) override;
            
            /// @brief Get the position of the SDL2 Window.
            /// @return The position of the SDL2 Window, or Point::Zero on failed.
            Point GetPosition() const override;
            /// @brief Set the position of the SDL2 Window.
            /// @param position The position to set.
            void SetPosition(const Point& position) override;
            
            /// @brief Get the size of the SDL2 Window.
            /// @return The size of the SDL2 Window, or Size::Zero on failed.
            Size GetSize() const override;
            /// @brief Set the size of the SDL2 Window.
            /// @param size The size to set, will not set if the given size area is 0.
            void SetSize(const Size& size) override;

            /// @brief Make the SDL2 Window visible.
            void Show() override;
            /// @brief Make the SDL2 Window not visible.
            void Hide() override;

            /// @brief Get the flags of the SDL2 Window.
            /// @return The flags of the SDL2 Window, or SDL2WindowFlags::Unknown on failed.
            SDL2WindowFlags GetFlags() const;
            /// @brief Get the numeric ID of the SDL2 Window.
            /// @return The numeric ID of the SDL2 Window, or 0 on failed.
            /// @note The ID is use by SDL2 to identify the window.
            uint32_t GetID() const;
        
            /// @brief Get the ratio of the SD2 Window size (Width/Height).
            /// @return The ratio of the window size, or 0 on failed.
            double GetRatio() const;

            /// @brief Get the minimum size of the SDL2 Window.
            /// @return The minimum size of the window, or Size::Zero on failed.
            Size GetMinimumSize() const;
            /// @brief Set the minimum size of the SDL2 Window.
            /// @param size The minimum size to set, will not set if the given size area is 0.
            void SetMinimumSize(const Size& size);

            /// @brief Get the maximum size of the SDL2 Window.
            /// @return The maximum size of the window, or Size::Zero on failed.
            Size GetMaximumSize() const;
            /// @brief Set the maximum size of the SDL2 Window.
            /// @param size The maximum size to set, will not set if the given size area is 0.
            void SetMaximumSize(const Size& size);

            /// @brief Check if the SDL2 Window is resizable by the user.
            /// @return true if the window is resizable, false otherwise (also on failed).
            bool IsResizable() const;
            /// @brief Make the SDL2 Window can be resized by the user.
            void EnableResizing();
            /// @brief Make the SDL2 Window cannot be resized by the user.
            void DisableResizing();
        
            /// @brief Check if the SDL2 Window is visible.
            /// @return true if the window is visible, false otherwise (also on failed).
            bool IsVisible() const;
            /// @brief Check if the SDL2 Window is fullscreen.
            /// @return true if the window is fullscreen, false otherwise (also on failed.)
            bool IsFullscreen() const;
            /// @brief Make the SDL2 Window fullscreen.
            /// @param realFullscreen If this false (default), will take the desktop size as the window size (fake fullscreen).
            /// @note In most case, fake fullscreen is what you usually want.
            void MakeFullscreen(bool realFullscreen = false);
            /// @brief Restore the SDL2 Window from fullscreen.
            void RestoreFromFullscreen();

            /// @brief Check if the SDL2 Window have a border.
            /// @return true if the window is bordered, false otherwise.
            bool IsBordered() const;
            /// @brief Make the SDL2 Window bordered (have a border).
            void MakeBordered();
            /// @brief Make the SDL2 Window borderless (didn't have a border).
            void MakeBorderless();

            /// @brief Make the SDL2 Window always above others window.
            void EnableAlwaysOnTop();
            /// @brief Disable the always on top mode of the SDL2 Window.
            void DisableAlwaysOnTop();
            /// @brief Check if the SDL2 Window is always above others.
            /// @return true if the window is always on top, false otherwise.
            bool IsAlwaysOnTop() const;

            /// @brief Raise the window to above other and set the input focus to it.
            void RaiseWindow();
        };

        /// @brief The SDL2 Window Builder, provide a builder for SDL2 Window.
        class SDL2WindowBuilder : public WindowBuilder<SDL2Window> {
        public:
            /// @brief Set the visible state of the window.
            /// @param visible true to make it visible, false otherwise.
            SDL2WindowBuilder& SetVisible(bool visible);

            /// @brief Make the window visible.
            SDL2WindowBuilder& Show();
            /// @brief Make the window invisible.
            SDL2WindowBuilder& Hide();

            /// @brief Set the position of the window.
            /// @param position The position to set.
            SDL2WindowBuilder& SetPosition(const Point& position);
            /// @brief Set the size of the window.
            /// @param size The size to set.
            SDL2WindowBuilder& SetSize(const Size& size);
            /// @brief Set the title of the window.
            /// @param title The title to set.
            SDL2WindowBuilder& SetTitle(const std::string& title);

            /// @brief Set the minimum size of the SDL2 Window.
            /// @param size The minimum size to set, will not set if the given size area is 0.
            SDL2WindowBuilder& SetMinimumSize(const Size& size);

            /// @brief Set the maximum size of the SDL2 Window.
            /// @param size The maximum size to set, will not set if the given size area is 0.
            SDL2WindowBuilder& SetMaximumSize(const Size& size);

            /// @brief Set the resizable state of the SDL2 Window.
            /// @param resizable true to allow it to be resized by the user, false to disallow.
            SDL2WindowBuilder& SetResizableState(bool resizable);
            /// @brief Make the SDL2 Window can be resized by the user.
            SDL2WindowBuilder& EnableResizing();
            /// @brief Make the SDL2 Window cannot be resized by the user.
            SDL2WindowBuilder& DisableResizing();
        
            /// @brief Make the SDL2 Window fullscreen.
            /// @param realFullscreen If this false (default), will take the desktop size as the window size (fake fullscreen).
            /// @note In most case, fake fullscreen is what you want.
            SDL2WindowBuilder& MakeFullscreen(bool realFullscreen = false);
            /// @brief Restore the SDL2 Window from fullscreen.
            SDL2WindowBuilder& RestoreFromFullscreen();

            /// @brief Set the bordered state of the SDL2 Window.
            /// @param bordered true to make the window bordered, false to make it borderless.
            SDL2WindowBuilder& SetBorderedState(bool bordered);
            /// @brief Make the SDL2 Window bordered (have a border).
            SDL2WindowBuilder& MakeBordered();
            /// @brief Make the SDL2 Window borderless (didn't have a border).
            SDL2WindowBuilder& MakeBorderless();

            /// @brief Set the always on top state of the SDL2 Window.
            /// @param always_on_top true to make the window always above others, false to disable it.
            SDL2WindowBuilder& SetAlwaysOnTopState(bool always_on_top);
            /// @brief Make the SDL2 Window always above others window.
            SDL2WindowBuilder& EnableAlwaysOnTop();
            /// @brief Disable the always on top mode of the SDL2 Window.
            SDL2WindowBuilder& DisableAlwaysOnTop();

            /// @brief Raise the window to above other and set the input focus to it.
            SDL2WindowBuilder& RaiseWindow();
        };
    }
}

#endif // __APE_SDL2_WINDOW_H__