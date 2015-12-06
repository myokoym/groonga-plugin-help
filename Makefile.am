ACLOCAL_AMFLAGS = -I m4

SUBDIRS =					\
	help				\
	help_mruby			\
	test

if WITH_MRUBY
dist_plugins_DATA =				\
	$(ruby_scripts)
endif

include ruby_scripts.am
