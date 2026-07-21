#ifndef __APE_GRAPHICS_H__
#define __APE_GRAPHICS_H__

#include "APE_Define.h"

namespace APE {
    /// @brief The IGraphicsEngine template, provide an interface for create a APE graphics engine type.
    class IGraphicsEngine {
    public:
        IGraphicsEngine() = default;
        virtual ~IGraphicsEngine() = default;

        APE_NOT_COPY_ASSIGNABLE(IGraphicsEngine)

        /// @brief Initialize the Graphics Engine.
        /// @return true on success, false on failure.
        /// @note This required overrided, since it'll return false as default.
        virtual bool Initialize() { return false; }
        /// @brief Check if the Graphics Engine has successfully initialized.
        /// @return true if initialized, false otherwise.
        /// @note This required overrided, since it'll return false as default.
        virtual bool IsInitialized() const { return false; }
        /// @brief De-initialize and shut down the Graphics Engine.
        virtual void Shutdown() {}

        /// @brief Request the Graphics Engine to start.
        virtual void Start() {}
        /// @brief Request the Graphics Engine to stop.
        virtual void Stop() {}
        /// @brief Check if the Graphics Engine is currently running.
        /// @return true if currently running, false otherwise.
        /// @note This required overrided, since it'll return false as default.
        virtual bool IsRunning() const { return false; }
    };
}

#endif // __APE_GRAPHICS_H__