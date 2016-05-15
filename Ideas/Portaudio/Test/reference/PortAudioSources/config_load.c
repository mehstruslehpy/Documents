#include <stdio.h>
#include <string.h>
#include <portaudio.h>
#include <ini.h>

typedef struct {
    PaStreamParameters inputParameters;
    PaStreamParameters outputParameters;
} inputConfig;

int handler(void* user, const char* section, const char* name,
        const char* value) {
    //char* sampfmt = NULL;
    inputConfig* pconfig = (inputConfig*) user;

    /*INPUT PARAM SECTION*/
#define MATCH(s, n) strcmp(section, s) == 0 && strcmp(name, n) == 0


    //MATCH("inputParameters", "channel");
    //pconfig->inputParameters.channelCount = atoi(value);
    //MATCH("inputParameters", "device");
    //pconfig->inputParameters.device = (int) atoi(value);
    //MATCH("inputParameters", "hostApiSpecificStreamInfo");
    //pconfig->inputParameters.hostApiSpecificStreamInfo = NULL;
    //MATCH("inputParameters", "sampleFormat");
    //pconfig->inputParameters.sampleFormat = (PaSampleFormat) atol(value);
    //MATCH("inputParameters", "suggestedLatency");
    //pconfig->inputParameters.suggestedLatency = atof(value);
    //MATCH("inputParameters", "hostApiSpecificStreamInfo");
    //pconfig->inputParameters.hostApiSpecificStreamInfo = NULL;


    //#define MATCH(s, n) strcmp(section, s) == 0 && strcmp(name, n) == 0

    if (MATCH("inputParameters", "channel")) {
        pconfig->inputParameters.channelCount = atoi(value);
    } else if (MATCH("inputParameters", "device")) {
        pconfig->inputParameters.device = (int) atoi(value);
    } else if (MATCH("inputParameters", "hostApiSpecificStreamInfo")) {
        pconfig->inputParameters.hostApiSpecificStreamInfo = NULL;
    } else if (MATCH("inputParameters", "sampleFormat")) {
        pconfig->inputParameters.sampleFormat = (PaSampleFormat) atol(value);
    } else if (MATCH("inputParameters", "suggestedLatency")) { 
        double x = (float) strtod(value);
        pconfig->inputParameters.suggestedLatency = x;
    } else if (MATCH("inputParameters", "hostApiSpecificStreamInfo")) {
        pconfig->inputParameters.hostApiSpecificStreamInfo = NULL;

    } else {

        return 0; /* unknown section/name, error */
    }



    /*OUTPUT PARAM SECTION*/
    //    MATCH("outputParameters", "channel");
    //    pconfig->outputParameters.channelCount = atoi(value);
    //    MATCH("outputParameters", "device");
    //    pconfig->outputParameters.device = (int) atoi(value);
    //    MATCH("outputParameters", "channel");
    //    pconfig->outputParameters.hostApiSpecificStreamInfo = NULL;
    //    MATCH("outputParameters", "channel");
    //    pconfig->outputParameters.sampleFormat =(PaSampleFormat) atol(value);
    //    MATCH("outputParameters", "channel");
    //    pconfig->outputParameters.suggestedLatency = atof(value);
    //    MATCH("outputParameters", "channel");
    //   pconfig->outputParameters.hostApiSpecificStreamInfo = NULL;


    if (MATCH("outputParameters", "channel")) {
        pconfig->outputParameters.channelCount = atoi(value);
    } else if (MATCH("outputParameters", "device")) {
        pconfig->outputParameters.device = (int) atoi(value);
    } else if (MATCH("outputParameters", "hostApiSpecificStreamInfo")) {
        pconfig->outputParameters.hostApiSpecificStreamInfo = NULL;
    } else if (MATCH("outputParameters", "sampleFormat")) {
        pconfig->outputParameters.sampleFormat = (PaSampleFormat) atol(value);
    } else if (MATCH("outputParameters", "suggestedLatency")) {
        pconfig->outputParameters.suggestedLatency = atof(value);
    } else if (MATCH("outputParameters", "hostApiSpecificStreamInfo")) {
        pconfig->outputParameters.hostApiSpecificStreamInfo = NULL;

    } else {

        return 0; /* unknown section/name, error */
    }




    return 1;
}


