#ifndef __APE_SDL2_GRAPHICS_H__
#define __APE_SDL2_GRAPHICS_H__

#include "../APE_Graphics.h"
#include "APE_SDL2_Window.h"
#include "APE_SDL2_Renderer.h"
#include <memory>

namespace APE {
    namespace SDL2 {
        /// @brief The SDL2 Graphics Engine, provide a base APE graphics engine for SDL2.
        class SDL2GraphicsEngine : public IGraphicsEngine {
        private:
            std::shared_ptr<SDL2Window> m_window;
            std::shared_ptr<SDL2Renderer> m_renderer;

            bool m_isRunning = false;
        protected:
            /// @brief Create a new SDL2 Window.
            /// @note This will be used to create the main SDL2 window of the SDL2 Graphics Engine.
            /// The default behaviour will just create using 'new', overrided this for custom behaviours.
            virtual SDL2Window* CreateWindow();
            /// @brief Create a new SDL2 Renderer of the graphics engine main window.
            /// @param window The 
            virtual SDL2Renderer* CreateRenderer(SDL2Window* window);
        public:
            SDL2GraphicsEngine() = default;
            virtual ~SDL2GraphicsEngine() {}

            APE_NOT_COPY_ASSIGNABLE(SDL2GraphicsEngine)

            /// @brief Initialize the SDL2 Graphics Engine, must be called before using it.
            /// @return true on success, false on failure.
            bool Initialize() override;
            /// @brief Check if the SDL2 Graphics Engine is fully initialized.
            /// @return true if initialized, false otherwise.
            bool IsInitialized() const override;
            /// @brief De-initialize and shutdown the SDL2 Graphics Engine.
            void Shutdown() override;

            /// @brief Request to start the SDL2 Graphics Engine.
            void Start() override;
            /// @brief Request to stop the SDL2 Graphics Engine.
            void Stop() override;
            /// @brief Check if the SDL2 Graphics Engine is currently running
            /// @return true if currently running, false otherwise.
            bool IsRunning() const override;

            /// @brief Get the main window of the SDL2 Graphics Engine.
            std::weak_ptr<SDL2Window> GetWindow();
            /// @brief Get the renderer of the main window of the SDL2 Graphics Engine.
            std::weak_ptr<SDL2Renderer> GetRenderer();
        };
    }
}

#endif // __APE_SDL2_GRAPHICS_H__