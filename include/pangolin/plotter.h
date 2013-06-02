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

#ifndef PLOTTER_H
#define PLOTTER_H

#include <pangolin/datalog.h>
#include <pangolin/gl.h>
#include <pangolin/view.h>
#include <pangolin/handler.h>

namespace pangolin
{

class Plotter;

Plotter& CreatePlotter(const std::string& name, DataLog* log = 0);

const static int draw_modes_n = 2;
const static int draw_modes[] = {GL_LINE_STRIP, GL_POINTS};

class Plotter : public View, Handler
{
public:
    Plotter(DataLog* log, float left=0, float right=600, float bottom=-1, float top=1, float tickx=30, float ticky=0.5 );

    void ResetView();
    
    void ScreenToPlot(int x, int y);
    void SetMode(unsigned mode, bool track=true);
    void SetViewOrigin(float x0, float y0);
    void SetLineThickness(float t);    

    void Render();
    
    void Keyboard(View&, unsigned char key, int x, int y, bool pressed);
    void Mouse(View&, MouseButton button, int x, int y, bool pressed, int mouse_state);
    void MouseMotion(View&, int x, int y, int mouse_state);
    void Special(View&, InputSpecial inType, float x, float y, float p1, float p2, float p3, float p4, int button_state);
        
protected:
//    void DrawSequence(const DataSequence& seq);
//    void DrawSequence(const DataSequence& x,const DataSequence& y);
//    void DrawSequenceHistogram(const DataLog::SequenceContainer& seq);
    void DrawTicks();
        
    DataLog* log;
    bool track_front;
    float int_x_dflt[2];
    float int_y_dflt[2];
    float int_x[2];
    float int_y[2];
    float vo[2]; //view offset
    float ticks[2];
    int last_mouse_pos[2];
    int mouse_state;
    float mouse_xy[2];
    float lineThickness;
    
    int draw_mode;
    
    enum PLOT_MODES { TIME_SERIES, XY, STACKED_HISTOGRAM};
    static const unsigned modes_n = 3;
    unsigned plot_mode;
    const static unsigned int show_n = 9;
    bool show[show_n];
};

} // namespace pangolin

#endif // PLOTTER_H
