char* simplifyPath(char* path) 
{
    char* res = path;
    for (int pathPos = 1, resPos = 1; path[pathPos - 1] != '\0'; pathPos++) {
        if (res[resPos - 1] == '/') {
            /* skip extra '/' */
            if (path[pathPos] == '/') 
                continue;
            /* delete last '/' */
            if (path[pathPos] == '\0' && resPos > 1) 
                resPos--;
            /* skip '.' */
            if (path[pathPos] == '.' && (path[pathPos + 1] == '/' || path[pathPos + 1] == '\0')) 
                continue;
            /* '..' */
            if (path[pathPos] == '.' && path[pathPos + 1] == '.' && (path[pathPos + 2] == '/' || path[pathPos + 2] == '\0')) {
                pathPos++;
                if (resPos == 1) 
                    continue;
                resPos--;
                while (res[resPos - 1] != '/') {
                    resPos--;
                }
                continue;
            }
        }
        res[resPos] = path[pathPos];
        resPos++;
    }
    return res;
}