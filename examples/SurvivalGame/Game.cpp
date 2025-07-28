#include "APE/APE_Structure.h"
#include "APE/SDL2/APE_SDL2_Window.h"
#include <SDL2/SDL_video.h>
#include <memory>


int main() {
    std::shared_ptr<APE::SDL2::SDL2Window> window(APE::SDL2::SDL2WindowBuilder()
        .SetTitle("Game Window")
        .SetSize(APE::Size(800, 500))
        .SetPosition(APE::Point(SDL_WINDOWPOS_CENTERED))
        .SetBorderedState(true)
        .SetVisible(true)
        .Build()
    );

    return 0;
}