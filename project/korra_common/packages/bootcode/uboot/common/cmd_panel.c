/*
 * This file is subject to the terms and conditions of the GNU General Public
 * License.  See the file "COPYING" in the main directory of this archive
 * for more details.
 *
 * Copyright (C) 2012 by Chuck Chen <ycchen@realtek.com>
 *
 * panel select command
*/
#include <common.h>
#include <command.h>
#include <malloc.h>
#include <asm/arch/system.h>
#include <tar.h>
#include <factorylib.h>

//#define PANEL_CONFIG_FROM_FACTORY_PANEL_HEADER	// from Darwin feature
//#define PANEL_CONFIG_FROM_FACTORY_PANEL_BIN	// from MacArthur feature

#define PANEL_BIN_FILENAME_IN_FACTORY	FACTORY_HEADER_FILE_NAME"bin_panel/panel.bin"
#define PANEL_SPEC_INFO_FILE_NAME		FACTORY_HEADER_FILE_NAME"panelspecindex/panelspec_info"
#define PANEL_BIN_FILE_PREFIX			FACTORY_HEADER_FILE_NAME"bin_panel/panel/"

#ifdef PANEL_CONFIG_FROM_FACTORY_PANEL_HEADER
extern char panel_file_name[100];
#endif

extern unsigned int tar_read_print_info;
extern unsigned char tar_read_print_prefix[32];

extern uint env_panel_change_panel_bin_in_factory(char *panel_bin_path);
extern uchar env_setup_env_panel(uchar *panel_filename);

#ifdef PANEL_CONFIG_FROM_FACTORY_PANEL_HEADER
int panelspec_parse_main(char* panelspec_file_name_full_path)
{
	char *dst_addr;
	unsigned int dst_length;

	if (panelspec_file_name_full_path == NULL)
	{
		return 0;
	}

	printf ("tar_read %s\n",panelspec_file_name_full_path);

	if (tar_read(panelspec_file_name_full_path, (char *)FACTORY_DATA_ADDR, CONFIG_FACTORY_SIZE/2, &dst_addr, &dst_length) > 0)
	{
		// parse header files
		if (parse_main((char *)dst_addr, dst_length) != 0)
		{
			printf("parseing error!!\n");
		}
		else
		{
			printf("setting panel config done\n");
		}
	}
	else
	{
		printf("not found your selected panel\n");
	}

	return 0;
}
#endif

void panel_dump_panel_bin_list(void)
{
	char *dst_addr;
	int dst_length;

	tar_read_print_info = 1;

	memset(tar_read_print_prefix, 0, sizeof(tar_read_print_prefix));

	if (strlen(PANEL_BIN_FILE_PREFIX) >= sizeof(tar_read_print_prefix))
	{
		printf("[WARN] size of tar_read_print_prefix is less than string length of %s\n", PANEL_BIN_FILE_PREFIX);
		strncpy((char *)tar_read_print_prefix, PANEL_BIN_FILE_PREFIX, sizeof(tar_read_print_prefix) - 1);
	}
	else
	{
		strcpy((char *)tar_read_print_prefix, PANEL_BIN_FILE_PREFIX);
	}

	tar_read("DUMMY_NAME_FOR_DUMP", (char *)FACTORY_DATA_ADDR, CONFIG_FACTORY_SIZE/2, &dst_addr, (uint *)&dst_length);

	tar_read_print_info = 0;
}

void panel_get_panelspec(void)
{
//	char *dst_addr, *retAddr;
//	uint dst_length, rc, retVal;
	char* raw;
	int bPanelChanged = 0;

	if (!(raw = getenv("panelspec_set_done")))
	{
		raw = "no";
	}
	printf("------------panelspec_set_done = %s\n", raw);


#ifdef PANEL_CONFIG_FROM_FACTORY_PANEL_BIN
	if (env_setup_env_panel((uchar *)PANEL_BIN_FILENAME_IN_FACTORY))
	{
		env_panel_change_panel_bin_in_factory(PANEL_BIN_FILENAME_IN_FACTORY);
	}

	if (bPanelChanged == 0)
	{
		env_setup_env_panel((uchar *)PANEL_BIN_FILENAME_IN_FACTORY);
	}

#else
#if 0
	if (tar_read(PANEL_SPEC_INFO_FILE_NAME, (char *)FACTORY_DATA_ADDR, CONFIG_FACTORY_SIZE/2, &dst_addr, &dst_length) != NULL)
	{
		if(parse_h("FACTORY_IS_NEW", dst_addr, dst_length, &retVal, &retAddr) == 0)
		{
			if((strncmp(raw, "yes", 3) != 0) || retVal)
			{
				/* Create new panel Name and panel_parameter */
				char *delim = " ";
				char* pch;
				char tar_read_file[100];
				char tar_read_file_full_path[100];

				printf("getting panel config from 0x%08X , size = 0x%08X.\n", dst_addr, dst_length);
				printf("Splitting string\n\"%s\"\nlength=%d, into tokens:\n", dst_addr, dst_length);
				pch = strtok(dst_addr, delim);

				if (pch != NULL)
				{
					printf("%s\n", pch);
					sprintf(tar_read_file, "%s", pch);

#ifdef PANEL_CONFIG_FROM_FACTORY_PANEL_HEADER
					printf ("panel_file_name %s => %s\n", panel_file_name, tar_read_file);
					sprintf(panel_file_name, "%s", tar_read_file); // save panel_file_name
					sprintf(tar_read_file_full_path, "%s%s", PANEL_BIN_FILE_PREFIX, tar_read_file); // get file full path
					panelspec_parse_main(tar_read_file_full_path);
#endif
					bPanelChanged = 1;
				}

				printf("factory FACTORY_IS_NEW write 0... ... ...\n" );
				*(char *)retAddr = '0';
				setenv("panelspec_set_done", "yes");
				saveenv();
			}
			else
			{
				// panelspec_set_done is yes && FACTORY_IS_NEW is 0
				printf("Panel: panelspec_set_done is yes and FACTORY_IS_NEW is 0\n");
				bPanelChanged = 0;
			}
		}
		else
		{
			// FACTORY_IS_NEW not found
			printf("Panel: FACTORY_IS_NEW not found in %s\n", PANEL_SPEC_INFO_FILE_NAME);
			bPanelChanged = 0;
		}
	}
	else
	{
		// panelspec_info not found
		printf("Panel: %s not found\n", PANEL_SPEC_INFO_FILE_NAME);
		bPanelChanged = 0;
	}
#endif
#endif

}


#ifdef PANEL_CONFIG_FROM_FACTORY_PANEL_HEADER
int do_panelspec(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	if (argc != 2)
	{
		return CMD_RET_USAGE;
	}
	else
	{
		char tar_read_file_full_path[100];

		printf ("panel_file_name %s => %s\n", panel_file_name, argv[1]);

		sprintf(panel_file_name, "%s", argv[1]); // save panel_file_name
		sprintf(tar_read_file_full_path, "%s%s", PANEL_BIN_FILE_PREFIX, argv[1]); // get file full path

		panelspec_parse_main(argv[1]);
	}

	return 0;
}

U_BOOT_CMD(
	panelspec,	2,	1,	do_panelspec,
	"parse factory panelspec and set selected panel to env",
	"panel_header_file_name"
);
#endif /* PANEL_CONFIG_FROM_FACTORY_PANEL_HEADER */


#ifdef PANEL_CONFIG_FROM_FACTORY_PANEL_BIN
int do_panel(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	if (argc < 2)
	{
		return CMD_RET_USAGE;
	}
	else
	{
		if (argv[1][0] == '-')
		{
			if (argv[1][1] == 'a')
			{
				printf("\n  Configs:\n\n");
				panel_dump_panel_bin_list();
				printf("\n");

				return CMD_RET_SUCCESS;
			}
			else if (argv[1][1] == 's' && argc == 3)
			{
				char *tar_read_file_full_path = NULL;

				tar_read_file_full_path = malloc(100);

				memset(tar_read_file_full_path, 0, 100);

				sprintf(tar_read_file_full_path, "%s%s", PANEL_BIN_FILE_PREFIX, argv[2]); // get file full path

				if (env_setup_env_panel((uchar *)tar_read_file_full_path))
				{
					env_panel_change_panel_bin_in_factory(PANEL_BIN_FILENAME_IN_FACTORY);
				}

				free(tar_read_file_full_path);
			}
			else
			{
				printf("\n");
				printf("Unknown option \"-%c\"\n", argv[1][1]);
				return CMD_RET_USAGE;
			}
		}
		else
		{
			return CMD_RET_USAGE;
		}
	}

	return CMD_RET_SUCCESS;
}

U_BOOT_CMD(
	panel,	3,	1,	do_panel,
	"select the specific panel config from factory",
	"[option] [bin_file_name]\n"
	"panel -a       - list all supported panel configs\n"
	"panel -s fname - specific panel binary file as default config"
);
#endif

