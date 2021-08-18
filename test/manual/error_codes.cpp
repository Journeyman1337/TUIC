/* Output all error code names and descriptions to console to verify they are correct. */

#include <TUIC/tuic.h>

#include <stdio.h>

int main()
{
	for (int error_code_i = TUI_ERROR_FIRST; error_code_i <= TUI_ERROR_LAST; error_code_i++)
	{
		TuiErrorCode cur_error_code = (TuiErrorCode)error_code_i;
		const char* cur_error_code_name = tuiErrorCodeToString(cur_error_code);
		const char* cur_error_code_description = tuiErrorCodeGetDescription(cur_error_code);

		printf("%s: %s\n", cur_error_code_name, cur_error_code_description);
	}

	return 0;
}