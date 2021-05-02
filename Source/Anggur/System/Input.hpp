#pragma once

#include <Anggur/Math/Vector.hpp>
#include "Event/Event.hpp"
#include "Core.hpp"

namespace Anggur {

class Input
{
public:
    static void Initialize();
    static void PreUpdate();
    static void Update();

    static bool IsKeyPressed(Key key);
    static bool IsKeyHeld(Key key);
    static bool IsKeyReleased(Key key);

    static bool IsScancodePressed(int i);
    static bool IsScancodeHeld(int i);
    static bool IsScancodeReleased(int i);

    static bool IsMousePressed(Mouse button);
    static bool IsMouseHeld(Mouse button);
    static bool IsMouseReleased(Mouse button);

    static void SetMousePos(const Vector& pos);
    static Vector GetMousePos();
    static Vector GetMouseWheel();

    friend class Application;

private:
    static SDL_Window* mRawWindow;

    static const Uint8* mKeyCurrState;
    static Uint8 mKeyPrevState[SDL_NUM_SCANCODES];

    static Uint32 mMouseCurrState;
    static Uint32 mMousePrevState;
    static Vector mMousePos;
    static Vector mMouseWheel;
};

}

