#include "mse_cpu.h"

void mse_forward_cpu(float *inp, float *out, int sz_out){
    float error, mse = 0;
    for (int i=0; i<sz_out; i++){
        error = inp[i]-out[i];
        error *= error;
        mse += error/sz_out;
    }
    out[sz_out] = mse;
}

void mse_backward_cpu(float *inp, float *out, int sz_out){
    for (int i=0; i<sz_out; i++){
        inp[i] = 2*(inp[i]-out[i])/sz_out;
    }
}

MSE_CPU::MSE_CPU(int _sz_out){
    sz_out = _sz_out;
}

void MSE_CPU::forward(float *_inp, float *_out){
    inp = _inp;
    out = _out;
    mse_forward_cpu(inp, out, sz_out);
}

void MSE_CPU::backward(){
    mse_backward_cpu(inp, out, sz_out);
}