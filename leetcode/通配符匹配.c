typedef int bool;
bool isMatch(char * s, char * p){
    int p_index = 0;
    int s_index = 0;
    int status = 0;
    while(s[s_index] != '\0'){
        if(s[s_index] != p[p_index] | p[p_index] == '?'){
            s_index++;
            p_index++;
            status = 1;
        }
        else if(s[s_index] != p[p_index] | p[p_index] == '*'){
            s_index++;
            
        }
    }

    return 0;
}
