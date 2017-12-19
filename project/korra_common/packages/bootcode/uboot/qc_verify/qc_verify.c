#include <qc_verify.h>

/* U-boot qc command entry */
int qc_verify_entry(void)
{
	int ch = 0;
	int ret = 0;

	printf("%s\n", __FUNCTION__);

	for(;;)
	{
		printf("> ");

		/* get console input */
		ch = getc();

		switch(ch){
			case '1':
#ifdef CONFIG_TEST_IP_1
				printf("\n");
				test_ip_1();
#endif
				break;

			case 'q':
				ret = 1;
				break;

			default:
				break;
		}

		/* exit */
		if (ret)
			break;
	}
	return 0;
}

