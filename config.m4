dnl Tell PHP about the argument to enable the hello extension

PHP_ARG_ENABLE(hello, Whether to enable the hello world extension, [ --enable-hello   Enable hello world])

if test "$PHP_HELLO" != "no"; then  
    PHP_NEW_EXTENSION(hello, php_myext.c, $ext_shared)
fi  
