/* Get information about all monitors currently active on the current device. */

#include <TUIC/tuic.h>

#include <stdio.h>
#include <string.h>

void message_callback(TuiErrorCode error_code, const char* msg)
{
    if (error_code == TUI_ERROR_GRAPHICS_BACKEND_SPECIFIC)
    {
        printf("%s : %s backend message: %s\n", tuiErrorCodeToString(error_code), tuiErrorCodeGetDescription(error_code), msg);
    }
    else
    {
        printf("%s : %s location: %s\n", tuiErrorCodeToString(error_code), tuiErrorCodeGetDescription(error_code), msg);
    }
}

int main()
{
    tuiSetDebugErrorCallback(message_callback);

    if (tuiInit() == TUI_FALSE)
    {
        printf("Failed to initialize TUIC.");
        return 1;
    }

    int monitor_count;
    TuiMonitor* monitors = tuiGetMonitors(&monitor_count);
    printf("There are %d monitor(s) attached to this device.\n", monitor_count);
    TuiMonitor primary_monitor = tuiGetPrimaryMonitor();
    printf("The name of the primary monitor is: \"%s\"\n", tuiMonitorGetName(primary_monitor));
    printf("All monitors:\n");
    for (int monitor_i = 0; monitor_i < monitor_count; monitor_i++)
    {
        TuiMonitor cur_monitor = monitors[(size_t)monitor_i];
        printf("Monitor %d:\n", monitor_i);
        printf("\t( name = \"%s\" )\n", tuiMonitorGetName(cur_monitor));
        printf("\t( width = %d pixels height = %d pixels )\n", tuiMonitorGetPixelWidth(cur_monitor), tuiMonitorGetPixelHeight(cur_monitor));
        printf("\t( physical_width = %d milimeters physical_height = %d milimeters )\n", tuiMonitorGetPhysicalWidth(cur_monitor), tuiMonitorGetPhysicalHeight(cur_monitor));
        printf("\t( content_scale_wide = %f content_scale_tall = %f )\n", tuiMonitorGetContentScaleWide(cur_monitor), tuiMonitorGetContentScaleTall(cur_monitor));
        printf("\t( refresh_rate = %d frames per second )\n", tuiMonitorGetRefreshRate(cur_monitor));
    }

    monitors = TUI_NULL;

    tuiTerminate();
    return 0;
}