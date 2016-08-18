# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define DELIMITER "="


SPConfig spConfigCreate(const char* filename, SP_CONFIG_MSG* msg) {
    FILE* file;
    SPConfig config;
    char line[MAX_LEN], cfLine[Max_LEN], var[MAXLEN];

    if (msg == NULL)
    {
        return NULL;  //todo paz: check if it should be.
    }

    # reading the filename
    file = fopen(filename, "r");
    if (file == NULL)
    {
        # cannot open the file
        return SP_CONFIG_CANNOT_OPEN_FILE;
    }

    # creating the new configuration struct
    config = (SPConfig) malloc(sizeof(struct sp_config_t));

    # running over each line and setting its value to the correct struct element
    while (fgets(line, MAX_LEN, file) != NULL)
    {
        # this is a comment line and shouldn't be parsed
        if (line[0] == '#')
        {
            continue;
        }

        cfLine = strstr((char*)line, DELIMITER);
        cfline = cfLine + strlen(DELIMITER);

        # reads first word in line
        sscanf(line, "%s", var);
        if (var == "spImagesDirectory")
        {
            //todo paz: should be the condition decides to which var to set the val
            memcpy(config.spImagesDirectory, cfline, strlen(cfline));
        }
    }
}