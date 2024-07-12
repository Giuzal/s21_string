#include "../includes/s21_tests.h"

START_TEST(correct_token_string) {
  char str1[] = "Hello++World_! love&&Peace";
  char str2[] = "Hello++World_! love&&Peace";
  const char delims[] = "+_!& ";

  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);

  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);

  while (got && expected) {
    got = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);

    ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));

    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(hard_token_string) {
  char str1[] = "++Hello++World_! love&&Peace+++ A +";
  char str2[] = "++Hello++World_! love&&Peace+++ A +";
  const char delims[] = "+_! =&";

  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);

  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);

  while (got && expected) {
    got = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);

    ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));

    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(unary_delimiters) {
  char str1[] = "Hello+World_World!love_Make";
  char str2[] = "Hello+World_World!love_Make";
  const char delims[] = "+_! =";

  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);

  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);

  while (got && expected) {
    got = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);

    ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));

    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(no_delims) {
  char str1[] = "HelloHasNoDelims";
  char str2[] = "HelloHasNoDelims";
  const char delims[] = "+_! =";

  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);

  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);

  while (got && expected) {
    got = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);

    ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));

    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(only_delims) {
  char str1[] = "!=+_!=+_";
  char str2[] = "!=+_!=+_";
  const char delims[] = "+_! =";

  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);

  ck_assert_ptr_null(got);
  ck_assert_ptr_null(expected);
}
END_TEST

START_TEST(one_down_delim) {
  char str1[] = "Hello_World_Linux";
  char str2[] = "Hello_World_Linux";
  const char delims[] = "+_! =";

  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);

  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);

  int i = 5;
  while (i) {
    got = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);
    i--;

    ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));

    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(even_n_of_delims) {
  char str1[] = "Linux++++Ubuntu++A++++B__V";
  char str2[] = "Linux++++Ubuntu++A++++B__V";
  const char delims[] = "+_! =";

  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);

  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);

  while (got && expected) {
    got = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);

    ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));

    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(odd_n_of_delims) {
  char str1[] = "Hello__+World__  Linux";
  char str2[] = "Hello__+World__ Linux";
  const char delims[] = "+_! =";

  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);

  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);

  while (got && expected) {
    got = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);

    ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));

    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(mixed_n_of_delims) {
  char str1[] = "Hello__World_+++Linux_Ubuntu";
  char str2[] = "Hello__World_+++Linux_Ubuntu";
  const char delims[] = "+_! =";

  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);

  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);

  while (got && expected) {
    got = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);

    ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));

    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(hard_mixed) {
  char str1[] = "     Hello__+ Mi!nt_   Linux+";
  char str2[] = "     Hello__+ Mi!nt_   Linux+";
  const char delims[] = "+_! =";

  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);

  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);

  while (got || expected) {
    got = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);

    ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));

    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(mixed_delims_2) {
  char str1[] = "!Macos__ !Gen!erati on____Devops+Lin!!!ux";
  char str2[] = "!Macos__ !Gen!erati on____Devops+Lin!!!ux";
  const char delims[] = "+_! =";

  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);

  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);

  while (got || expected) {
    got = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);

    ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));

    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(multiply_delims) {
  char str1[] = "!       A!B!C!D!E!!F!!G";
  char str2[] = "!       A!B!C!D!E!!F!!G";
  const char delims[] = "+_! =";

  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);

  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);

  while (got || expected) {
    got = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);

    if (got || expected) {
      ck_assert_str_eq(got, expected);
      ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

Suite *suite_strtok(void) {
  Suite *s = suite_create("suite_strtok");
  TCase *tc = tcase_create("strtok_tc");

  tcase_add_test(tc, correct_token_string);
  tcase_add_test(tc, hard_token_string);
  tcase_add_test(tc, only_delims);
  tcase_add_test(tc, even_n_of_delims);
  tcase_add_test(tc, odd_n_of_delims);
  tcase_add_test(tc, mixed_n_of_delims);
  tcase_add_test(tc, one_down_delim);
  tcase_add_test(tc, hard_mixed);
  tcase_add_test(tc, mixed_delims_2);
  tcase_add_test(tc, multiply_delims);
  tcase_add_test(tc, unary_delimiters);
  tcase_add_test(tc, no_delims);

  suite_add_tcase(s, tc);
  return s;
}