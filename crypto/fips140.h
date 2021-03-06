#ifndef _CRYPTO_FIPS140_H
#define _CRYPTO_FIPS140_H

#include <linux/kernel.h>
#include <linux/module.h>

#ifdef CONFIG_CRYPTO_FIPS_FUNC_TEST
#include "fips140_test.h"
#endif

#define SKC_VERSION_TEXT "SKC v2.2"
#define FIPS140_ERR 1
#define FIPS140_NO_ERR 0

#define FIPS_HMAC_SIZE         (32)
#define FIPS_CRYPTO_ADDRS_SIZE (4096)

struct first_last {
	aligned_u64 first;
	aligned_u64 last;
};

extern const __u64 crypto_buildtime_address;
extern const struct first_last integrity_crypto_addrs[FIPS_CRYPTO_ADDRS_SIZE];
extern const __s8 builtime_crypto_hmac[FIPS_HMAC_SIZE];

extern int do_integrity_check(void);

#ifdef CONFIG_CRYPTO_FIPS_FUNC_TEST
void reset_in_fips_err(void);
#endif /* CONFIG_CRYPTO_FIPS_FUNC_TEST */

#endif // _CRYPTO_FIPS140_H
