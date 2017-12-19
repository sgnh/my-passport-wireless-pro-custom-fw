mod_xsendfile.la: mod_xsendfile.slo
	$(SH_LINK) -rpath $(libexecdir) -module -avoid-version  mod_xsendfile.lo $(MOD_DBD_LDADD)
DISTCLEAN_TARGETS = modules.mk
static = 
shared =  mod_xsendfile.la
