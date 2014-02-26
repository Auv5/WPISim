#ifndef COMPRESSOR_H_
#define COMPRESSOR_H_

class Compressor {
public:
    Compressor(int pressuresw_dio, int compspike_relay);

    void Start();
};

#endif
