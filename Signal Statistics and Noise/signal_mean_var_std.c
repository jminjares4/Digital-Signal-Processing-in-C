#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// create macro for signal length
#define SIGNAL_LENGTH 320
// call waveform.c global variable
extern double InputSignal_f32_1kHz_15kHz[SIGNAL_LENGTH];

// calculate signal mean
double calc_signal_mean(double * sig_src_arr, int signal_length);
// calculate signal variance
double calc_signal_variance(double * sig_src_arr, double signal_mean, int signal_length);
// calculate signal standard deviation
double calc_signal_std(double signal_variance);

int main(int argc, char ** argv){

    // Mean
    double mean = calc_signal_mean(InputSignal_f32_1kHz_15kHz, SIGNAL_LENGTH);
    // display mean 
    printf("Mean: %lf\n", mean);

    // Variance
    double variance = calc_signal_variance(InputSignal_f32_1kHz_15kHz, mean,SIGNAL_LENGTH);
    // display variance 
    printf("Variance: %lf\n", variance);
    
    // Standard Deviation
    double std_dev = calc_signal_std(variance);
    // display variance 
    printf("Standard Deviation: %lf\n", std_dev);

    return EXIT_SUCCESS;
}

double calc_signal_mean(double * sig_src_arr, int signal_length){
    // create local mean variable
    double mean = 0.0;
    // iterate over the signal length and store into mean
    for(int i = 0; i < signal_length; i++)  mean += sig_src_arr[i];
    // return mean
    return mean/(double)signal_length;
}

double calc_signal_variance(double * sig_src_arr, double signal_mean, int signal_length){
    // create local variance variable
    double variance = 0.0;
    // iterate over the signal
    // variance = variance + (signal@i - mean)^2
    for(int i = 0; i < signal_length; i++) variance += pow(sig_src_arr[i]-signal_mean, 2);
    // return the variance
    return variance/(double)(signal_length - 1);
}

double calc_signal_std(double signal_variance){
    return sqrt(signal_variance);
}