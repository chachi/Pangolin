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

#include <pangolin/datalog.h>
#include <stdexcept>
#include <cstring>

namespace pangolin
{

DataLog::DataLog(size_t circ_buffer_rows)
    : circ_buffer_rows(circ_buffer_rows),
      circ_buffer_stride(0),
      data(NULL)
{
}

DataLog::~DataLog()
{
    Clear();
}

void DataLog::SetLabels(const std::vector<std::string>& new_labels)
{
    labels = new_labels;
}

void DataLog::Clear()
{
    if(data) {
        delete[] data;
        data = NULL;
    }
}

const std::vector<std::string>& DataLog::Labels() const
{
    return labels;
}

void DataLog::Save(std::string filename)
{
//    if( sequences.size() > 0 )
//    {
//        ofstream f(filename.c_str());
//        for( int n=sequences[0].IndexBegin(); n < sequences[0].IndexEnd(); ++n )
//        {
//            f << setprecision(12) << sequences[0][n];
//            for( unsigned s=1; s < sequences.size(); ++s )
//                f << ", " << sequences[s][n];
//            f << endl;
//        }
//        f.close();
//    }
}

size_t DataLog::Stride() const
{
    return circ_buffer_stride;
}

float* DataLog::CircBlock0() const
{
//    const size_t n_stored = std::min(n,circ_buffer_rows);
//    const size_t start = (n-n_stored) % circ_buffer_rows;
//    const size_t end = n % circ_buffer_rows;
    throw std::runtime_error("Not implemented");
}

float* DataLog::CircBlock1() const
{
    throw std::runtime_error("Not implemented");    
}

void DataLog::Log(unsigned int N, const float * vals)
{
    // We implicitly also store datum id at start
    const size_t NP = N+1;
    
    // Make sure data buffer is initialized
    if(!data) {
        // Create appropriate buffer and zero
        circ_buffer_stride = NP;
        data = new float[circ_buffer_rows*circ_buffer_stride];
        memset(data,0,sizeof(float)*circ_buffer_rows*circ_buffer_stride);
    }else if(NP > circ_buffer_stride) {
        // Resize array (maintaining data)
        throw std::runtime_error("Not Implemented.");
    }
    
    // Where data should go
    const size_t next_idx = n % circ_buffer_rows;
    float* next = data+next_idx;
    
    // Clear slot and insert datum id and data.
    memset(next, 0, circ_buffer_stride);
    *next = n;    
    memcpy(next+1, vals, N);
    ++n;
}

void DataLog::Log(const std::vector<float> & vals)
{
    Log(vals.size(), &vals[0]);
}

void DataLog::Log(float v)
{
    const float vs[] = {v};
    Log(1,vs);
}

void DataLog::Log(float v1, float v2)
{
    const float vs[] = {v1,v2};
    Log(2,vs);
}

void DataLog::Log(float v1, float v2, float v3)
{
    const float vs[] = {v1,v2,v3};
    Log(3,vs);
}
void DataLog::Log(float v1, float v2, float v3, float v4)
{
    const float vs[] = {v1,v2,v3,v4};
    Log(4,vs);
}
void DataLog::Log(float v1, float v2, float v3, float v4, float v5)
{
    const float vs[] = {v1,v2,v3,v4,v5};
    Log(5,vs);
}
void DataLog::Log(float v1, float v2, float v3, float v4, float v5, float v6)
{
    const float vs[] = {v1,v2,v3,v4,v5,v6};
    Log(6,vs);
}

}
