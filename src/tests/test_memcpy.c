#include "../includes/s21_tests.h"

START_TEST(Hello_World) {
  char src[] = "Hello, World!";
  char dest[50];
  void *res = s21_memcpy(dest, src, strlen(src) + 1);
  void *expected = memcpy(dest, src, strlen(src) + 1);

  ck_assert_str_eq(dest, expected);
  ck_assert_ptr_eq(res, dest);
}
END_TEST

START_TEST(part) {
  char src[] = "Hello, World!";
  char dest[50];
  void *res = s21_memcpy(dest, src, 5);
  void *expected = memcpy(dest, src, 5);

  ck_assert_mem_eq(dest, expected, 5);
  ck_assert_ptr_eq(res, dest);
}
END_TEST

START_TEST(numbers) {
  char src[] = {1, 2, 3, 4, 5};
  char dest[5];
  void *res = s21_memcpy(dest, src, 5);
  void *expected = memcpy(dest, src, 5);

  ck_assert_mem_eq(dest, expected, 5);
  ck_assert_ptr_eq(res, dest);
}
END_TEST

START_TEST(copy_struct) {
  struct {
    int id;
    char name[20];
  } src = {1, "John Doe"}, dest, expected = {1, "John Doe"};

  s21_memcpy(&dest, &src, sizeof(src));

  ck_assert_mem_eq(&dest, &expected, sizeof(expected));
}
END_TEST

START_TEST(check_register_and_num_and_sim) {
  char src[] = "H1@#421";
  char dest[50];
  void *res = s21_memcpy(dest, src, 5);
  void *expected = memcpy(dest, src, 5);

  ck_assert_mem_eq(dest, expected, 5);
  ck_assert_ptr_eq(res, dest);
}
END_TEST

Suite *suite_memcpy(void) {
  Suite *s = suite_create("suite_memcpy");
  TCase *tc = tcase_create("memcpy_tc");

  tcase_add_test(tc, Hello_World);
  tcase_add_test(tc, part);
  tcase_add_test(tc, numbers);
  tcase_add_test(tc, copy_struct);
  tcase_add_test(tc, check_register_and_num_and_sim);

  suite_add_tcase(s, tc);
  return s;
}