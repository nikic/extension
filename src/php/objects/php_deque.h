#ifndef PHP_DS_DEQUE_H
#define PHP_DS_DEQUE_H

#include "../../ds/ds_deque.h"

#define Z_DS_DEQUE(z)   ((php_ds_deque_t*) Z_OBJ(z))->deque
#define Z_DS_DEQUE_P(z) Z_DS_DEQUE(*z)
#define THIS_DS_DEQUE() Z_DS_DEQUE_P(getThis())

#define ZVAL_DS_DEQUE(z, d)  ZVAL_OBJ(z, php_ds_deque_create_object_ex(d))

#define RETURN_DS_DEQUE(deque)              \
do {                                        \
    if (deque) {                            \
        ZVAL_DS_DEQUE(return_value, deque); \
    } else {                                \
        ZVAL_NULL(return_value);            \
    }                                       \
    return;                                 \
} while(0)


/**
 *
 */
typedef struct php_ds_deque {
    zend_object  std;
    ds_deque_t  *deque;
} php_ds_deque_t;

/**
 * Creates a new zend_object using an existing deque.
 */
zend_object *php_ds_deque_create_object_ex(ds_deque_t *deque);

/**
 * Creates a new deque zend_object.
 */
zend_object *php_ds_deque_create_object(zend_class_entry *ce);

/**
 * Creates an object clone of a deque.
 */
zend_object *php_ds_deque_create_clone(ds_deque_t *deque);

PHP_DS_SERIALIZE_FUNCIONS(php_ds_deque);

#endif
