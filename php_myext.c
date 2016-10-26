#include <php.h>
#include "php_myext.h"

zend_function_entry myext_functions[] = {  
        PHP_FE(myext_hello, NULL)
		PHP_FE(myext_print, NULL)
		PHP_FE(myext_print_integer, NULL)
		PHP_FE(myext_print_array, NULL)
        PHP_FE_END
};

zend_module_entry myext_module_entry = {  
        STANDARD_MODULE_HEADER,
        PHP_MYEXT_EXTNAME,
        myext_functions,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        PHP_MYEXT_VERSION,
        STANDARD_MODULE_PROPERTIES,
};

ZEND_GET_MODULE(myext);

PHP_FUNCTION(myext_hello) {  
        php_printf("Hello Manila!\n");
};

PHP_FUNCTION(myext_print)
{
	char *mystring;
	size_t mystring_len;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "s", &mystring, &mystring_len) == FAILURE) {
		return;
	}
	php_printf("Hello %s!! (%i)\n", mystring, mystring_len);
	return;
}

PHP_FUNCTION(myext_print_integer)
{
	zend_long lval;
	int i;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &lval) == FAILURE) {
		return;
	}
	
	if (lval > 0) {
		for (i=0; i < lval; i++) {
			php_printf("Hello %i\n",i);
		}
	}
	return;
}

PHP_FUNCTION(myext_print_array)
{
	zval *myarray = NULL;
	zend_string *key;
	zend_ulong num_key;
	zval *val;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "a",  &myarray) == FAILURE) {
		return;
	}

	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(myarray), num_key, key, val) {
		php_printf("Hello %s\n", Z_STRVAL_P(val));
	}
	ZEND_HASH_FOREACH_END();
	return;
}
