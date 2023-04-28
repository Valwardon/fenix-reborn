#include "recording.h"

void record_macro(int num_actions, Action actions[])
{
    FILE *fp;
    fp = fopen("macro.txt", "w");
    fprintf(fp, "%d\n", num_actions);
    for (int i = 0; i < num_actions; i++)
    {
        fprintf(fp, "%d %d %d %d %d\n", actions[i].type, actions[i].x, actions[i].y, actions[i].wait_time, actions[i].keycode);
    }
    fclose(fp);
}
