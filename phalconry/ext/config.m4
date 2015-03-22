PHP_ARG_ENABLE(phalconry, whether to enable phalconry, [ --enable-phalconry   Enable Phalconry])

if test "$PHP_PHALCONRY" = "yes"; then

	

	if ! test "x" = "x"; then
		PHP_EVAL_LIBLINE(, PHALCONRY_SHARED_LIBADD)
	fi

	AC_DEFINE(HAVE_PHALCONRY, 1, [Whether you have Phalconry])
	phalconry_sources="phalconry.c kernel/main.c kernel/memory.c kernel/exception.c kernel/hash.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/extended/array.c kernel/string.c kernel/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/exit.c phalconry/arrayobject.zep.c
	phalconry/mvc/application.zep.c
	phalconry/mvc/dispatcher.zep.c
	phalconry/mvc/env.zep.c
	phalconry/mvc/module.zep.c
	phalconry/util.zep.c "
	PHP_NEW_EXTENSION(phalconry, $phalconry_sources, $ext_shared,, )
	PHP_SUBST(PHALCONRY_SHARED_LIBADD)

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([phalconry], [pcre])
					AC_DEFINE([ZEPHIR_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_JSON],
		[
			AC_CHECK_HEADERS(
				[ext/json/php_json.h],
				[
					PHP_ADD_EXTENSION_DEP([phalconry], [json])
					AC_DEFINE([ZEPHIR_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	CPPFLAGS=$old_CPPFLAGS

	PHP_INSTALL_HEADERS([ext/phalconry], [php_PHALCONRY.h])

fi
