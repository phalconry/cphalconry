
extern zend_class_entry *phalconry_vartype_ce;

ZEPHIR_INIT_CLASS(Phalconry_VarType);

PHP_METHOD(Phalconry_VarType, toArray);
PHP_METHOD(Phalconry_VarType, toObject);
PHP_METHOD(Phalconry_VarType, toArrays);
PHP_METHOD(Phalconry_VarType, toObjects);
PHP_METHOD(Phalconry_VarType, toBool);
PHP_METHOD(Phalconry_VarType, toScalar);
PHP_METHOD(Phalconry_VarType, toNumber);
PHP_METHOD(Phalconry_VarType, getDecimalPoint);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_vartype_toarray, 0, 0, 1)
	ZEND_ARG_INFO(0, arg)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_vartype_toobject, 0, 0, 1)
	ZEND_ARG_INFO(0, arg)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_vartype_toarrays, 0, 0, 1)
	ZEND_ARG_INFO(0, arg)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_vartype_toobjects, 0, 0, 1)
	ZEND_ARG_INFO(0, arg)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_vartype_tobool, 0, 0, 1)
	ZEND_ARG_INFO(0, arg)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_vartype_toscalar, 0, 0, 1)
	ZEND_ARG_INFO(0, arg)
	ZEND_ARG_INFO(0, flags)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconry_vartype_tonumber, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconry_vartype_method_entry) {
	PHP_ME(Phalconry_VarType, toArray, arginfo_phalconry_vartype_toarray, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalconry_VarType, toObject, arginfo_phalconry_vartype_toobject, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalconry_VarType, toArrays, arginfo_phalconry_vartype_toarrays, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalconry_VarType, toObjects, arginfo_phalconry_vartype_toobjects, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalconry_VarType, toBool, arginfo_phalconry_vartype_tobool, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalconry_VarType, toScalar, arginfo_phalconry_vartype_toscalar, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalconry_VarType, toNumber, arginfo_phalconry_vartype_tonumber, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalconry_VarType, getDecimalPoint, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
