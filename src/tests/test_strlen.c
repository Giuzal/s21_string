#include "../includes/s21_tests.h"

START_TEST(empty) {
  char src[] = "";

  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(hello) {
  char src[] = "hello";

  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(num) {
  char src[] = "123456789";

  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(string) {
  char src[] = "123456789qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";

  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(hello_no_dal) {
  char src[] = "hello\0no_dal";

  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(three_two_one) {
  char src[] = "three_two_one(321321)...123...123";

  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(Hello_world) {
  char src[] = "Hello_world";

  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(some_Other_Text) {
  char src[] = "some_Other_Text";

  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(love_Love) {
  char src[] = "Kot_love_";

  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(end_of_test) {
  char src[] = "end_of_test";

  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

Suite *suite_strlen(void) {
  Suite *s = suite_create("suite_strlen");
  TCase *tc = tcase_create("strlen_tc");

  tcase_add_test(tc, empty);
  tcase_add_test(tc, hello);
  tcase_add_test(tc, num);
  tcase_add_test(tc, string);
  tcase_add_test(tc, hello_no_dal);
  tcase_add_test(tc, three_two_one);
  tcase_add_test(tc, Hello_world);
  tcase_add_test(tc, end_of_test);
  tcase_add_test(tc, love_Love);
  tcase_add_test(tc, some_Other_Text);

  suite_add_tcase(s, tc);
  return s;
}
