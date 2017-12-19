#ifndef __QC_VERIFY_H__
#define __QC_VERIFY_H__

#include "qc_verify_common.h"

extern int qc_verify_entry(void);

#ifdef CONFIG_TEST_IP_1
extern int test_ip_1(void);
#endif

#endif /* __QC_VERIFY_H__ */

