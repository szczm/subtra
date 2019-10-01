// SUBTRA Engine class source
// 2019 Matthias Scherba @szczm_

#include "Engine.hpp"

#include <SDL2/SDL.h>
#include <vector>
#include "GLCommon.hpp"

#include "Exception.hpp"
#include "Log.hpp"

void sub::Engine::init()
{
    // Init... stuff
    initSDL();
    initOpenGL();

    // Create main window and optimize it
	m_mainWindow.init("SUBTRA", 800, 600);
	m_mainWindow.maximize();

    m_testMesh.init();

    m_testShader.init("a", "b", "c");

    // std::cout << glGetString(GL_VERSION) << std::endl;
}

void sub::Engine::initOpenGL()
{
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
}

void sub::Engine::initSDL()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
        throw sub::Exception("Could not initialize SDL");
    }
}

void sub::Engine::run()
{
    bool running = true;

    while (running)
    {
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT ||
                (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE))
            {
                running = false;
            }

			if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_RESIZED)
			{
				m_mainWindow.resizeViewport(event.window.data1, event.window.data2);
			}
        }

        m_mainWindow.clear();
m_testShader.use();
        glEnableVertexAttribArray(0);
        m_testMesh.bind();
glVertexAttribPointer(
   0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
   3,                  // size
   GL_FLOAT,           // type
   GL_FALSE,           // normalized?
   0,                  // stride
   (void*)0            // array buffer offset
);
// Draw the triangle !
glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
glDisableVertexAttribArray(0);

        m_mainWindow.swap();

    }
}

void sub::Engine::shutdown()
{
	SDL_Quit();
}