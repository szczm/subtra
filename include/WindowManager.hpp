// SUBTRA Window Manager class header
// 2020 Matthias Scherba @szczm_

#pragma once

#include "Window.hpp"
#include "Windows/MainWindow.hpp"

namespace SUBTRA
{
    class WindowManager final
    {
        public:

        WindowManager () = default;
        ~WindowManager ();

        void Init ();

        void ProcessEvent (SDL_Event a_event);
        void Update ();

        void Shutdown ();


        private:

        void InitGLAD ();
        void InitSDL ();
        void InitOpenGL ();
        void InitIMGUI ();

        MainWindow m_mainWindow {};
    };
}