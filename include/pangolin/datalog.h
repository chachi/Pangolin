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

#ifndef PANGOLIN_DATALOG_H
#define PANGOLIN_DATALOG_H

#include <vector>
#include <string>

namespace pangolin
{

class DataLog
{
public:
    DataLog(size_t circ_buffer_rows = 10000 );
    ~DataLog();
    
    void Log(float v);
    void Log(float v1, float v2);
    void Log(float v1, float v2, float v3);
    void Log(float v1, float v2, float v3, float v4);
    void Log(float v1, float v2, float v3, float v4, float v5);
    void Log(float v1, float v2, float v3, float v4, float v5, float v6);
    void Log(unsigned int N, const float * vals);
    void Log(const std::vector<float> & vals);
    void SetLabels(const std::vector<std::string> & labels);
    void Clear();
    void Save(std::string filename);
    
    const std::vector<std::string>& Labels() const;
    
    // Utilities for accessing circular buffer
    size_t Stride() const;
    float* CircBlock0() const;
    float* CircBlock1() const;

protected:
    // Size of circular buffer
    size_t circ_buffer_rows;
    size_t circ_buffer_stride;
    
    // Pointer to circular buffer data
    float* data;
    
    // Total number of points logged. If n > circ_buffer_rows,
    // then not all data is still available.
    size_t n;

    // Text labels associated with data.    
    std::vector<std::string> labels;
};

}

#endif // PANGOLIN_DATALOG_H
