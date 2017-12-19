#include <common.h>
#include <command.h>
#include <qc_verify.h>

int do_qc(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	qc_verify_entry();

	return 0;
}

U_BOOT_CMD(
	qc,	CONFIG_SYS_MAXARGS,	0,	do_qc,
	"enter qc verify entry",
	"qc\n"
	"    - enter qc verify entry\n"
);
