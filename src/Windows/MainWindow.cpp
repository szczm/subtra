// SUBTRA MainWindow class source
// 2019 Matthias Scherba @szczm_

#include "Windows/MainWindow.hpp"


void SUBTRA::MainWindow::Open()
{
    Open("SUBTRA", 800, 600);
    Maximize();
}