#include "s21_test.h"

int main(void) {
    int number_failed;
    SRunner *sr;

    sr = srunner_create(NULL);
    srunner_add_suite(sr, sub_suite());
    srunner_add_suite(sr, sum_suite());
    srunner_add_suite(sr, mul_num_suite());
    srunner_add_suite(sr, mul_suite());

    srunner_add_suite(sr, det_suite());
    srunner_add_suite(sr, transp_suite());
    srunner_add_suite(sr, inverse_suite());

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? 0 : 1;
}