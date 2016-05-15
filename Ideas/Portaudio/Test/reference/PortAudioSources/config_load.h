typedef struct
{
    PaStreamParameters  inputParameters;
    PaStreamParameters  outputParameters;  
} inputConfig;

int handler(void* user, const char* section, const char* name,
                   const char* value);

