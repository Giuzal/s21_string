#include "../includes/s21_tests.h"

START_TEST(zero) {
  char str[50] = "Hello, World!";
  void *res = s21_memset(str, 0, 5);
  void *expected = memset(str, 0, 5);

  ck_assert_mem_eq(str, expected, 5);
  ck_assert_ptr_eq(res, str);
}
END_TEST

START_TEST(one) {
  char str[50] = "Hello, World!";
  void *res = s21_memset(str, 1, 10);
  void *expected = memset(str, 1, 10);

  ck_assert_mem_eq(str, expected, 10);
  ck_assert_ptr_eq(res, str);
}
END_TEST

START_TEST(char_test) {
  char str[50] = "Hello, World!";
  void *res = s21_memset(str, 'A', 8);
  void *expected = memset(str, 'A', 8);

  ck_assert_mem_eq(str, expected, 8);
  ck_assert_ptr_eq(res, str);
}
END_TEST

START_TEST(struct_test) {
  typedef struct {
    int id;
    char name[20];
  } Person;
  Person p;
  void *res = s21_memset(&p, 0, sizeof(Person));
  void *expected = memset(&p, 0, sizeof(Person));

  ck_assert_mem_eq(&p, expected, sizeof(Person));
  ck_assert_ptr_eq(res, &p);
}
END_TEST

START_TEST(numbers) {
  char str[10];
  void *res = s21_memset(str, 7, sizeof(str));
  void *expected = memset(str, 7, sizeof(str));

  ck_assert_mem_eq(str, expected, sizeof(str));
  ck_assert_ptr_eq(res, str);
}
END_TEST

Suite *suite_memset(void) {
  Suite *s = suite_create("suite_memset");
  TCase *tc = tcase_create("memset_tc");

  tcase_add_test(tc, zero);
  tcase_add_test(tc, one);
  tcase_add_test(tc, char_test);
  tcase_add_test(tc, struct_test);
  tcase_add_test(tc, numbers);

  suite_add_tcase(s, tc);
  return s;
}