#include "../includes/s21_tests.h"

START_TEST(empty) {
    char src[] = "";
    char res[] = "";
    char expected[] = "";
    s21_size_t n_byte = 0;

    s21_strncat(res, src, n_byte);
    strncat(expected, src, n_byte);

    ck_assert_mem_ge(res, expected, n_byte);
} END_TEST

START_TEST(no_byte) {
    char src[] = "hello";
    char res[10] = "";
    char expected[10] = "";
    s21_size_t n_byte = 0;

    s21_strncat(res, src, n_byte);
    strncat(expected, src, n_byte);

    ck_assert_mem_ge(res, expected, n_byte);
} END_TEST

START_TEST(empty_src) {
    char src[] = "";
    char res[10] = "hello";
    char expected[10] = "hello";
    s21_size_t n_byte = 0;

    s21_strncat(res, src, n_byte);
    strncat(expected, src, n_byte);

    ck_assert_mem_ge(res, expected, n_byte);
} END_TEST


START_TEST(cd_world) {
    char src[] = "hello";
    char res[10] = "hello";
    char expected[10] = "hello";
    s21_size_t n_byte = 5;

    s21_strncat(res, src, n_byte);
    strncat(expected, src, n_byte);

    ck_assert_mem_ge(res, expected, n_byte);
} END_TEST

START_TEST(string) {
    char src[] = "hello";
    char res[25] = "love";
    char expected[25] = "love";
    s21_size_t n_byte = 6;

    s21_strncat(res, src, n_byte);
    strncat(expected, src, n_byte);

    ck_assert_mem_ge(res, expected, n_byte);
} END_TEST

START_TEST(TEST_STRING) {
    char src[] = "TEST_STRING";
    char res[25] = "TEST_STRING";
    char expected[25] = "TEST_STRING";
    s21_size_t n_byte = 5;

    s21_strncat(res, src, n_byte);
    strncat(expected, src, n_byte);

    ck_assert_mem_ge(res, expected, n_byte);
} END_TEST

START_TEST(TEST_STRING2) {
    char src[] = "TEST_STRING";
    char res[25] = "TEST_STRING";
    char expected[25] = "TEST_STRING";
    s21_size_t n_byte = 0;

    s21_strncat(res, src, n_byte);
    strncat(expected, src, n_byte);

    ck_assert_mem_ge(res, expected, n_byte);
} END_TEST

START_TEST(TEST_STRING3) {
    char src[] = "TEST_STRING";
    char res[25] = "TEST_STRING";
    char expected[25] = "TEST_STRING";
    s21_size_t n_byte = 1;

    s21_strncat(res, src, n_byte);
    strncat(expected, src, n_byte);

    ck_assert_mem_ge(res, expected, n_byte);
} END_TEST

START_TEST(TEST_STRING4) {
    char src[] = "TEST_STRING";
    char res[25] = "TEST_STRING";
    char expected[25] = "TEST_STRING";
    s21_size_t n_byte = 10;

    s21_strncat(res, src, n_byte);
    strncat(expected, src, n_byte);

    ck_assert_mem_ge(res, expected, n_byte);
} END_TEST

START_TEST(zero_char) {
    char src[] = "\0";
    char res[25] = "TEST_STRING";
    char expected[25] = "TEST_STRING";
    s21_size_t n_byte = 1;

    s21_strncat(res, src, n_byte);
    strncat(expected, src, n_byte);

    ck_assert_mem_ge(res, expected, n_byte);
} END_TEST


Suite *suite_strncat(void) {
    Suite *s = suite_create("suite_strncat");
    TCase *tc = tcase_create("strncat_tc");

    tcase_add_test(tc, empty);
    tcase_add_test(tc, no_byte);
    tcase_add_test(tc, empty_src);
    tcase_add_test(tc, cd_world);
    tcase_add_test(tc, string);
    tcase_add_test(tc, TEST_STRING);
    tcase_add_test(tc, TEST_STRING2);
    tcase_add_test(tc, TEST_STRING3);
    tcase_add_test(tc, TEST_STRING4);
    tcase_add_test(tc, zero_char);

    suite_add_tcase(s, tc);
    return s;
}