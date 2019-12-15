// SUBTRA MainWindow class header
// 2019 Matthias Scherba @szczm_

#pragma once

#include "Window.hpp"


namespace SUBTRA
{
    // Move default main window properties away from construction site
    class MainWindow : public Window
    {
        public:

        MainWindow() = default;
        ~MainWindow() = default;

        void Open();

        private:

        using Window::Open;
    };
}