/* This file is part of the Pangolin Project.
 * http://github.com/stevenlovegrove/Pangolin
 *
 * Copyright (c) 2011 Steven Lovegrove
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef PANGOLIN_DISPLAY_GLUT_H
#define PANGOLIN_DISPLAY_GLUT_H

#include <pangolin/platform.h>
#include <pangolin/glinclude.h>

#include <string>

namespace pangolin
{

//! @brief Create GLUT window and bind Pangolin to it.
//! All GLUT initialisation is taken care of. This prevents you
//! from needing to call BindToContext() and TakeGlutCallbacks().
void CreateGlutWindowAndBind(std::string window_title, int w = 640, int h = 480, unsigned int mode = GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH );

//! @brief Applies any post-render events if they are defined,
//! swaps buffers and processes events. Also resets viewport to
//! entire window and disables scissoring.
void FinishGlutFrame();

//! @brief Swaps OpenGL Buffers and processes input events
void SwapGlutBuffersProcessGlutEvents();

//! @brief Allow Pangolin to take GLUT callbacks for its own uses
//! Not needed if you instantiated a window through CreateWindowAndBind().
void TakeGlutCallbacks();

}

#endif // PANGOLIN_DISPLAY_GLUT_H
