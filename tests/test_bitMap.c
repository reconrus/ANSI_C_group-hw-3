#include <check.h>
#include <stdio.h>
#include "bitMap.h"


START_TEST (test_setBitByNumber)
{
    char bitMap[]={0,1,0,1,1,0};
    setBitByNumber(bitMap,1,0);
    ck_assert(getBitByNumber(bitMap,0)==1);
}
END_TEST

START_TEST (test_getBitByNumber)
{
    char bitMap[]={0,1,0,1,1,0};
    ck_assert(getBitByNumber(bitMap,5)==0);
}
END_TEST

START_TEST (test_setBitByAddress)
{
    char bitMap[]={88,0}; // 01011000
    //int bitMap[]={0,1,0,1,1,0};
    setBitByAddress(bitMap,1);
    ck_assert(getBitByAddress(bitMap)==1);
}
END_TEST

START_TEST (test_getBitByAddress)
{
    char bitMap[]={0,1,0,1,1,0};
    ck_assert(getBitByAddress(bitMap+2)==0);
}
END_TEST

Suite *str_suite(void) {
    Suite *suite = suite_create("BitMap");
    TCase *tcase = tcase_create("case");
    tcase_add_test(tcase, test_setBitByNumber);
    tcase_add_test(tcase, test_getBitByNumber);
    tcase_add_test(tcase, test_setBitByAddress);
    tcase_add_test(tcase, test_getBitByAddress);
    suite_add_tcase(suite, tcase);
    return suite;
}

int main(int argc, char *argv[]) {
    int number_failed;
    Suite *suite = str_suite();
    SRunner *runner = srunner_create(suite);
    srunner_run_all(runner, CK_NORMAL);
    number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return number_failed;
}