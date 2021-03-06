/*
The MIT License (MIT)

Copyright (c) 2013-2015 SRS(ossrs)

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef FLV_AAC_ENCODER_HPP
#define FLV_AAC_ENCODER_HPP

#include "rtmp_codec_define.h"
#include <srs_core.hpp>

#include <string>

#include <srs_kernel_codec.hpp>

class SrsStream;


/**
* encode data to aac file.
*/
class FlvAacEncoder
{
private:
    SrsAacObjectType aac_object;
    int8_t aac_sample_rate;
    int8_t aac_channels;
    bool got_sequence_header;

    std::string aac_sequence_header;

private:
    SrsStream* tag_stream;
public:
    FlvAacEncoder();
    ~FlvAacEncoder();
public:
    /**
    * initialize the underlayer file stream.
    * @remark user can initialize multiple times to encode multiple aac files.
    * @remark, user must free the fs, aac encoder never close/free it.
    */
    virtual int initialize();
public:
    /**
    * encode audio/video packet.
    * @remark assert data is not NULL.
    */
    int encode_audio(char* data, int size, char* outdata, int* outsize);
    int encode_audio2(char* data, int size, char* outdata, int* outsize);
};


#endif

