#include <stdio.h>
#include <stdlib.h>
#include <portaudio.h>
#include <ini.h>
#include "config_load.h"

/*
 * 
 */

int main(int argc, char** argv) {
    char *errbuf = "2.22";
    double unerrbuf;
    unerrbuf = strtof(errbuf,NULL);
    printf("errbuf: %lf", unerrbuf);
    inputConfig  config;
    inputConfig* confptr = &config;
    
    if (ini_parse("config.ini", handler, &config) < 0) {
        printf("Can't load 'test.ini'\n");
        return 1;
    }
    
    /*FOR TESTING*/
    printf("config.inputParameters.channelCount = %d \n", config.inputParameters.channelCount);
    printf("config.inputParameters.device = %d \n", config.inputParameters.device);
    printf("config.inputParameters.sampleFormat = %lu \n", config.inputParameters.sampleFormat);
    printf("config.inputParameters.suggestedLatency = %lf \n",(double) config.inputParameters.suggestedLatency);

    /*FOR TESTING*/   
    return (EXIT_SUCCESS);
}

