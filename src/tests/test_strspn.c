#include "../includes/s21_tests.h"

START_TEST(empty) {
  char src[] = "";
  char res[] = "";

  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(Hello_) {
  char src[] = "Hello";
  char res[] = "";

  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(_Hello) {
  char src[] = "";
  char res[] = "Hello";

  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(any_register) {
  char src[] = "Hello";
  char res[] = "Hello";

  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(num_num) {
  char src[] = "123";
  char res[] = "123";

  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(long_num_num) {
  char src[] = "12345";
  char res[] = "123";

  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(num_long_num) {
  char src[] = "123";
  char res[] = "12345";

  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(any_num) {
  char src[] = "1234567890";
  char res[] = "0987654321";

  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(num_and_letters) {
  char src[] = "1A2A3A4A5A";
  char res[] = "123";

  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(num_and_letters2) {
  char src[] = "H1e2l3l1o2";
  char res[] = "123";

  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(abc) {
  char src[] = "abcdefghijklmnop";
  char res[] = "aP";

  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(symbols) {
  char src[] = "123456!@#$%^&*qwerty";
  char res[] = "0987654321";

  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(upper_case) {
  char src[] = "HelloWorld1234";
  char res[] = "1234567890QWERTYUIOPASDFGHJKLZXCVBNM";

  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(lower_case) {
  char src[] = "hELLO_wORLD";
  char res[] = "1234567890qwertyuiopasdfghjklczxcvbnm";

  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(find_H) {
  char src[] = "HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH";
  char res[] = "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhH";

  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

Suite *suite_strspn(void) {
  Suite *s = suite_create("suite_strspn");
  TCase *tc = tcase_create("strspn_tc");

  tcase_add_test(tc, empty);
  tcase_add_test(tc, Hello_);
  tcase_add_test(tc, _Hello);
  tcase_add_test(tc, any_register);
  tcase_add_test(tc, num_num);
  tcase_add_test(tc, long_num_num);
  tcase_add_test(tc, num_long_num);
  tcase_add_test(tc, any_num);
  tcase_add_test(tc, num_and_letters);
  tcase_add_test(tc, num_and_letters2);
  tcase_add_test(tc, abc);
  tcase_add_test(tc, symbols);
  tcase_add_test(tc, upper_case);
  tcase_add_test(tc, lower_case);
  tcase_add_test(tc, find_H);

  suite_add_tcase(s, tc);
  return s;
}