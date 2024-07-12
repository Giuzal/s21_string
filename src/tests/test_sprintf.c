#include "../includes/s21_tests.h"

START_TEST(test_minus) {
  char buffer[50] = {0};
  char expected[50] = {0};
  int num = 42;

  s21_sprintf(buffer, "%-5d", num);
  sprintf(expected, "%-5d", num);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_zero) {
  char buffer[50] = {0};
  char expected[50] = {0};
  int num = 42;

  s21_sprintf(buffer, "%0d", num);
  sprintf(expected, "%0d", num);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_space) {
  char buffer[50] = {0};
  char expected[50] = {0};
  int num = 42;

  s21_sprintf(buffer, "% d", num);
  sprintf(expected, "% d", num);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_plus) {
  char buffer[50] = {0};
  char expected[50] = {0};
  int num = 42;

  s21_sprintf(buffer, "%+d", num);
  sprintf(expected, "%+d", num);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_hash) {
  char buffer[50] = {0};
  char expected[50] = {0};
  int num = 42;

  s21_sprintf(buffer, "%#x", num);
  sprintf(expected, "%#x", num);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_precision_integer) {
  char buffer[50] = {0};
  char expected[50] = {0};
  int num = 42;

  s21_sprintf(buffer, "%.5d", num);
  sprintf(expected, "%.5d", num);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_precision_integer_negative) {
  char buffer[50] = {0};
  char expected[50] = {0};
  int num = -42;

  s21_sprintf(buffer, "%.5d", num);
  sprintf(expected, "%.5d", num);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_precision_string) {
  char buffer[50] = {0};
  char expected[50] = {0};
  char str[] = "hello world";

  s21_sprintf(buffer, "%.5s", str);
  sprintf(expected, "%.5s", str);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_precision_float) {
  char buffer[50] = {0};
  char expected[50] = {0};
  double num = 3.141592653589793;

  s21_sprintf(buffer, "%.2f", num);
  sprintf(expected, "%.2f", num);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_precision_exponential) {
  char buffer[50] = {0};
  char expected[50] = {0};
  double num = 1234.56789;

  s21_sprintf(buffer, "%.3e", num);
  sprintf(expected, "%.3e", num);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_precision_unsigned) {
  char buffer[50] = {0};
  char expected[50] = {0};
  unsigned int num = 42;

  s21_sprintf(buffer, "%.5u", num);
  sprintf(expected, "%.5u", num);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_precision_hex) {
  char buffer[50] = {0};
  char expected[50] = {0};
  unsigned int num = 255;

  s21_sprintf(buffer, "%.5x", num);
  sprintf(expected, "%.5x", num);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_precision_octal) {
  char buffer[50] = {0};
  char expected[50] = {0};
  unsigned int num = 255;

  s21_sprintf(buffer, "%.5o", num);
  sprintf(expected, "%.5o", num);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_precision_integer_star) {
  char buffer[50] = {0};
  char expected[50] = {0};
  int num = 42;
  int precision = 5;

  s21_sprintf(buffer, "%.*d", precision, num);
  sprintf(expected, "%.*d", precision, num);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_precision_string_star) {
  char buffer[50] = {0};
  char expected[50] = {0};
  char str[] = "hello world";
  int precision = 5;

  s21_sprintf(buffer, "%.*s", precision, str);
  sprintf(expected, "%.*s", precision, str);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_precision_float_star) {
  char buffer[50] = {0};
  char expected[50] = {0};
  double num = 3.141592653589793;
  int precision = 2;

  s21_sprintf(buffer, "%.*f", precision, num);
  sprintf(expected, "%.*f", precision, num);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_precision_exponential_star) {
  char buffer[50] = {0};
  char expected[50] = {0};
  double num = 1234.56789;
  int precision = 3;

  s21_sprintf(buffer, "%.*e", precision, num);
  sprintf(expected, "%.*e", precision, num);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_precision_unsigned_star) {
  char buffer[50] = {0};
  char expected[50] = {0};
  unsigned int num = 42;
  int precision = 5;

  s21_sprintf(buffer, "%.*u", precision, num);
  sprintf(expected, "%.*u", precision, num);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_precision_hex_star) {
  char buffer[50] = {0};
  char expected[50] = {0};
  unsigned int num = 255;
  int precision = 5;

  s21_sprintf(buffer, "%.*x", precision, num);
  sprintf(expected, "%.*x", precision, num);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_precision_octal_star) {
  char buffer[50] = {0};
  char expected[50] = {0};
  unsigned int num = 255;
  int precision = 5;

  s21_sprintf(buffer, "%.*o", precision, num);
  sprintf(expected, "%.*o", precision, num);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

// 0.* precision

START_TEST(star_zero_i) {
  char buffer[50] = {0};
  char expected[50] = {0};

  char *format = "%0.*i";
  int num = 69;
  ck_assert_int_eq(s21_sprintf(buffer, format, 5, num),
                   sprintf(expected, format, 5, num));

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(zero_star_ld) {
  char buffer[50] = {0};
  char expected[50] = {0};

  char *format = "%0.*ld";
  long num = 8581385185;
  ck_assert_int_eq(s21_sprintf(buffer, format, 5, num),
                   sprintf(expected, format, 5, num));

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_c) {
  char buffer[50] = {0};
  char expected[50] = {0};
  char ch = 'A';

  s21_sprintf(buffer, "%c", ch);
  sprintf(expected, "%c", ch);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_d) {
  char buffer[50] = {0};
  char expected[50] = {0};
  int num = 42;
  s21_sprintf(buffer, "%d", num);
  sprintf(expected, "%d", num);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_i) {
  char buffer[50] = {0};
  char expected[50] = {0};
  int num = -42;

  s21_sprintf(buffer, "%i", num);
  sprintf(expected, "%i", num);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_e) {
  char buffer[100] = {0};
  char expected[100] = {0};
  double num = 1234.5678;

  s21_sprintf(buffer, "%.6e", num);
  sprintf(expected, "%.6e", num);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_E) {
  char buffer[100] = {0};
  char expected[100] = {0};
  double num = 1234.5678;

  s21_sprintf(buffer, "%.6E", num);
  sprintf(expected, "%.6E", num);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_u) {
  char buffer[50] = {0};
  char expected[50] = {0};
  unsigned int num = 42;
  s21_sprintf(buffer, "%u", num);
  sprintf(expected, "%u", num);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_f) {
  char buffer[50] = {0};
  char expected[50] = {0};
  double num = 3.14159;

  s21_sprintf(buffer, "%.2f", num);
  sprintf(expected, "%.2f", num);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_long_f) {
  char buffer[50] = {0};
  char expected[50] = {0};
  long double num = 523636326.1242;

  s21_sprintf(buffer, "%Lf", num);
  sprintf(expected, "%Lf", num);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_g_6) {
  char buffer[100] = {0};
  char expected[100] = {0};
  double num = 1234.5678;

  s21_sprintf(buffer, "%.6g", num);
  sprintf(expected, "%.6g", num);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_g_1) {
  char buffer[100] = {0};
  char expected[100] = {0};
  double num = 1234.5678;

  s21_sprintf(buffer, "%.1g", num);
  sprintf(expected, "%.1g", num);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_g_2) {
  char buffer[100] = {0};
  char expected[100] = {0};
  double num = 1234.5678;

  s21_sprintf(buffer, "%.2g", num);
  sprintf(expected, "%.2g", num);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_g_3) {
  char buffer[100] = {0};
  char expected[100] = {0};
  double num = 1234.5678;

  s21_sprintf(buffer, "%.3g", num);
  sprintf(expected, "%.3g", num);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_g_4) {
  char buffer[100] = {0};
  char expected[100] = {0};
  double num = 1234.5678;

  s21_sprintf(buffer, "%.4g", num);
  sprintf(expected, "%.4g", num);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_g_7) {
  char buffer[100] = {0};
  char expected[100] = {0};
  double num = 1234.5678;

  s21_sprintf(buffer, "%.7g", num);
  sprintf(expected, "%.7g", num);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_g_8) {
  char buffer[100] = {0};
  char expected[100] = {0};
  double num = 1234.5678;

  s21_sprintf(buffer, "%.8g", num);
  sprintf(expected, "%.8g", num);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_g_9) {
  char buffer[100] = {0};
  char expected[100] = {0};
  double num = 1234.56785678;

  s21_sprintf(buffer, "%.9g", num);
  sprintf(expected, "%.9g", num);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_G) {
  char buffer[100] = {0};
  char expected[100] = {0};
  double num = 1234.5678;

  s21_sprintf(buffer, "%.6G", num);
  sprintf(expected, "%.6G", num);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_x) {
  char buffer[50] = {0};
  char expected[50] = {0};
  unsigned int num = 255;

  s21_sprintf(buffer, "%x", num);
  sprintf(expected, "%x", num);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_X) {
  char buffer[50] = {0};
  char expected[50] = {0};
  unsigned int num = 255;

  s21_sprintf(buffer, "%X", num);
  sprintf(expected, "%X", num);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_o) {
  char buffer[50] = {0};
  char expected[50] = {0};
  unsigned int num = 255;

  s21_sprintf(buffer, "%o", num);
  sprintf(expected, "%o", num);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s) {
  char buffer[50] = {0};
  char expected[50] = {0};
  char str[] = "hello";

  s21_sprintf(buffer, "%s", str);
  sprintf(expected, "%s", str);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_p) {
  char buffer[100] = {0};
  char expected[100] = {0};
  void *ptr = (void *)0x12345678;

  s21_sprintf(buffer, "%p", ptr);
  sprintf(expected, "%p", ptr);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_n) {
  char buffer[100] = {0};
  int count = 0;
  s21_sprintf(buffer, "Test string%n", &count);
  ck_assert_int_eq(count, 11);
}
END_TEST

START_TEST(test_percent) {
  char buffer[50] = {0};
  char expected[50] = {0};

  s21_sprintf(buffer, "%%");
  sprintf(expected, "%%");

  ck_assert_str_eq(buffer, expected);
}
END_TEST

// width

START_TEST(test_width_integer) {
  char buffer[50] = {0};
  char expected[50] = {0};
  int num = 42;

  s21_sprintf(buffer, "%5d", num);
  sprintf(expected, "%5d", num);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_width_integer_negative) {
  char buffer[50] = {0};
  char expected[50] = {0};
  int num = -42;

  s21_sprintf(buffer, "%5d", num);
  sprintf(expected, "%5d", num);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_width_string) {
  char buffer[50] = {0};
  char expected[50] = {0};
  char str[] = "hello";

  s21_sprintf(buffer, "%10s", str);
  sprintf(expected, "%10s", str);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_width_char) {
  char buffer[50] = {0};
  char expected[50] = {0};
  char ch = 'A';

  s21_sprintf(buffer, "%5c", ch);
  sprintf(expected, "%5c", ch);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_width_float) {
  char buffer[50] = {0};
  char expected[50] = {0};
  double num = 3.14159;

  s21_sprintf(buffer, "%10.2f", num);
  sprintf(expected, "%10.2f", num);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_width_exponential) {
  char buffer[50] = {0};
  char expected[50] = {0};
  double num = 1234.5678;

  s21_sprintf(buffer, "%15.6e", num);
  sprintf(expected, "%15.6e", num);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_width_unsigned) {
  char buffer[50] = {0};
  char expected[50] = {0};
  unsigned int num = 42;

  s21_sprintf(buffer, "%10u", num);
  sprintf(expected, "%10u", num);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_width_hex) {
  char buffer[50] = {0};
  char expected[50] = {0};
  unsigned int num = 255;

  s21_sprintf(buffer, "%10x", num);
  sprintf(expected, "%10x", num);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_width_octal) {
  char buffer[50] = {0};
  char expected[50] = {0};
  unsigned int num = 255;

  s21_sprintf(buffer, "%10o", num);
  sprintf(expected, "%10o", num);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

// width_star

START_TEST(test_width_integer_star) {
  char buffer[50] = {0};
  char expected[50] = {0};

  char *format = "%0*d";
  int num = 69;
  ck_assert_int_eq(s21_sprintf(buffer, format, 5, num),
                   sprintf(expected, format, 5, num));

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(basic) {
  char buffer[50] = {0};
  char buffer1[50] = {0};
  int num = 10;
  sprintf(buffer1, "The number is: %d", num);
  s21_sprintf(buffer, "The number is: %d", num);
  ck_assert_str_eq(buffer, buffer1);
}
END_TEST

START_TEST(test_float) {
  char buffer[50] = {0};
  char buffer1[50] = {0};
  float num = 3.14;
  sprintf(buffer1, "The numue of pi is: %.2f", num);
  s21_sprintf(buffer, "The numue of pi is: %.2f", num);
  ck_assert_str_eq(buffer, buffer1);
}
END_TEST

START_TEST(test_string) {
  char buffer1[100] = {0};
  char buffer2[100] = {0};

  char *num = "JUST CHECKING IF it holds LONG strings";

  sprintf(buffer1, "%s", num);
  s21_sprintf(buffer2, "%s", num);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_string_question) {
  char buffer1[100] = {0};
  char buffer2[100] = {0};

  char *num = "John";

  sprintf(buffer1, "Hello, %s?!", num);
  s21_sprintf(buffer2, "Hello, %s?!", num);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_string_question_2) {
  char buffer1[100] = {0};
  char buffer2[100] = {0};

  char *num = "John";

  sprintf(buffer1, "Hello, %s?", num);
  s21_sprintf(buffer2, "Hello, %s?", num);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_string_question_multiple) {
  char buffer[50] = {0};
  char buffer1[50] = {0};
  char name[] = "John";
  char name_2[] = "Albert";
  sprintf(buffer1, "Hello, %s?! %s", name, name_2);
  s21_sprintf(buffer, "Hello, %s?! %s", name, name_2);
  ck_assert_str_eq(buffer, buffer1);
}
END_TEST

START_TEST(test_string_begin_multiple) {
  char buffer[50] = {0};
  char buffer1[50] = {0};
  char name[] = "Hello, John!&*";
  sprintf(buffer1, "%s", name);
  s21_sprintf(buffer, "%s", name);
  ck_assert_str_eq(buffer, buffer1);
}
END_TEST

START_TEST(test_string_and_num) {
  char buffer[50] = {0};
  char buffer1[50] = {0};
  char name[] = "John_12345*";
  sprintf(buffer1, "Hello, %s", name);
  s21_sprintf(buffer, "Hello, %s", name);
  ck_assert_str_eq(buffer, buffer1);
}
END_TEST

START_TEST(multiple_numues) {
  char buffer[100] = {0};
  char buffer1[100] = {0};

  sprintf(buffer1, "%% %d %c %s", 42, 'a', "test");

  s21_sprintf(buffer, "%% %d %c %s", 42, 'a', "test");

  ck_assert_str_eq(buffer, buffer1);
}
END_TEST

START_TEST(test_width_precision) {
  char buffer[50] = {0};
  char buffer1[50] = {0};
  float numue = 123.45678;
  sprintf(buffer1, "Formatted numue: %8.2f", numue);
  s21_sprintf(buffer, "Formatted numue: %8.2f", numue);
  ck_assert_str_eq(buffer, buffer1);
}
END_TEST

START_TEST(test_padding) {
  char buffer[50] = {0};
  char buffer1[50] = {0};
  int num = 42;
  sprintf(buffer1, "Padded number: %05d", num);
  s21_sprintf(buffer, "Padded number: %05d", num);
  ck_assert_str_eq(buffer, buffer1);
}
END_TEST

START_TEST(test_hexadecimal) {
  char buffer[50] = {0};
  char buffer1[50] = {0};
  int num = 255;
  sprintf(buffer1, "Hexadecimal representation: %X", num);
  s21_sprintf(buffer, "Hexadecimal representation: %X", num);
  ck_assert_str_eq(buffer, buffer1);
}
END_TEST

START_TEST(test_octal) {
  char buffer[50] = {0};
  char buffer1[50] = {0};
  int num = 63;
  sprintf(buffer1, "Octal representation: %o", num);
  s21_sprintf(buffer, "Octal representation: %o", num);
  ck_assert_str_eq(buffer, buffer1);
}
END_TEST

START_TEST(test_unsigned) {
  char buffer[50] = {0};
  char buffer1[50] = {0};
  unsigned int num = 4294967295;
  sprintf(buffer1, "Unsigned integer: %u", num);
  s21_sprintf(buffer, "Unsigned integer: %u", num);
  ck_assert_str_eq(buffer, buffer1);
}
END_TEST

// lenght

START_TEST(test_length_h) {
  char buffer[1024] = {0};
  char expected[1024] = {0};
  short num = 42;

  s21_sprintf(buffer, "%hd", num);
  sprintf(expected, "%hd", num);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

// START_TEST(test_length_hh) {
//     char buffer[1024] = {0};
//     char expected[1024] = {0};
//     signed char num = -42;

//     s21_sprintf(buffer, "%hhd", num);
//     sprintf(expected, "%hhd", num);

//     ck_assert_str_eq(buffer, expected);
// } END_TEST

START_TEST(test_length_l) {
  char buffer[1024] = {0};
  char expected[1024] = {0};
  long num = 1234567890L;

  s21_sprintf(buffer, "%ld", num);
  sprintf(expected, "%ld", num);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

// START_TEST(test_length_ll) {
//     char buffer[1024] = {0};
//     char expected[1024] = {0};
//     long long num = 1234567890123456789LL;

//     s21_sprintf(buffer, "%lld", num);
//     sprintf(expected, "%lld", num);

//     ck_assert_str_eq(buffer, expected);
// } END_TEST

START_TEST(test_length_l_float) {
  char buffer[1024] = {0};
  char expected[1024] = {0};
  long double num = 3.141592653589793238L;

  s21_sprintf(buffer, "%Lf", num);
  sprintf(expected, "%Lf", num);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

// hex

START_TEST(test_one_hex_lower) {
  char buffer[50] = {0};
  char expected[50] = {0};
  ck_assert_int_eq(s21_sprintf(buffer, "%x", (unsigned)INT32_MIN),
                   sprintf(expected, "%x", (unsigned)INT32_MIN));
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(s21_sprintf(buffer, "%x", 0), sprintf(expected, "%x", 0));
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(s21_sprintf(buffer, "%x", INT32_MAX),
                   sprintf(expected, "%x", INT32_MAX));
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_hex_upper) {
  char buffer[50] = {0};
  char expected[50] = {0};
  int result1 = s21_sprintf(buffer, "%X", (unsigned)INT32_MIN);
  int result2 = sprintf(expected, "%X", (unsigned)INT32_MIN);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer, expected);

  result1 = s21_sprintf(buffer, "%X", 0);
  result2 = sprintf(expected, "%X", 0);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer, expected);

  result1 = s21_sprintf(buffer, "%X", INT32_MAX);
  result2 = sprintf(expected, "%X", INT32_MAX);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_padding_hex) {
  char buffer[50] = {0};
  char expected[50] = {0};
  int result1 = s21_sprintf(buffer, "%08X", (unsigned)INT32_MIN);
  int result2 = sprintf(expected, "%08X", (unsigned)INT32_MIN);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer, expected);

  result1 = s21_sprintf(buffer, "%08X", 0);
  result2 = sprintf(expected, "%08X", 0);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer, expected);

  result1 = s21_sprintf(buffer, "%08X", INT32_MAX);
  result2 = sprintf(expected, "%08X", INT32_MAX);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_one_hex_lower_with_alignment_left) {
  char buffer[512] = {0};
  char expected[512] = {0};

  ck_assert_int_eq(s21_sprintf(buffer, "%-3x", (unsigned)INT32_MIN),
                   sprintf(expected, "%-3x", (unsigned)INT32_MIN));
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(s21_sprintf(buffer, "%-3x", 0),
                   sprintf(expected, "%-3x", 0));
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(s21_sprintf(buffer, "%-3x", INT32_MAX),
                   sprintf(expected, "%-3x", INT32_MAX));
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_one_hex_lower_with_alignment_right) {
  char buffer[512] = {0};
  char expected[512] = {0};

  ck_assert_int_eq(s21_sprintf(buffer, "%13x", (unsigned)INT32_MIN),
                   sprintf(expected, "%13x", (unsigned)INT32_MIN));
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(s21_sprintf(buffer, "%13x", 0),
                   sprintf(expected, "%13x", 0));
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(s21_sprintf(buffer, "%13x", INT32_MAX),
                   sprintf(expected, "%13x", INT32_MAX));
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(octal_width) {
  char str1[512];
  char str2[512];

  char *format = "%15o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal_flags) {
  char str1[512];
  char str2[512];

  char *format = "%-16o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal_precision) {
  char str1[512];
  char str2[512];

  char *format = "%.51o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(octal_many_flags) {
  char str1[512];
  char str2[512];

  char *format = "%-5.51o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal_zero) {
  char str1[512];
  char str2[512];

  char *format = "%o";
  ck_assert_int_eq(s21_sprintf(str1, format, 0), sprintf(str2, format, 0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal_hash) {
  char str1[512];
  char str2[512];

  char *format = "%#o";
  int val = 57175;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(octal_short) {
  char str1[512];
  char str2[512];

  char *format = "%hd";
  short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal_long) {
  char str1[512];
  char str2[512];

  char *format = "%lo";
  long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal_many) {
  char str1[512];
  char str2[512];

  char *format = "%lo, %o, %ho, %.5o, %5.o";
  long int val = 949149114140;
  ck_assert_int_eq(
      s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
      sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
              (unsigned)14414, (unsigned)9681));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal) {
  char str1[512];
  char str2[512];

  char *format = "%lo";
  long int val = 84518;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

// unsigned val
START_TEST(unsigned_val) {
  char str1[512];
  char str2[512];

  char *format = "%u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_width) {
  char str1[512];
  char str2[512];

  char *format = "%15u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

END_TEST

START_TEST(unsigned_val_precision) {
  char str1[512];
  char str2[512];

  char *format = "%.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_short) {
  char str1[512];
  char str2[512];

  char *format = "%hu";
  unsigned short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(hex_width) {
  char str1[512];
  char str2[512];

  char *format = "%5x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(hex_flags) {
  char str1[512];
  char str2[512];

  char *format = "%#-10x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_precision) {
  char str1[512];
  char str2[512];

  char *format = "%.15x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_many) {
  char str1[512];
  char str2[512];

  char *format = "%#-10x%x%X%#x%#X%5.5x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val, val, val, val, val),
                   sprintf(str2, format, val, val, val, val, val, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_many_flags) {
  char str1[512];
  char str2[512];

  char *format = "%#-5.10x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_zero) {
  char str1[512];
  char str2[512];

  char *format = "%#x";
  unsigned val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_huge) {
  char str1[512];
  char str2[512];

  char *format = "%#x";
  unsigned val = 18571;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_short) {
  char str1[512];
  char str2[512];

  char *format = "%#hx";
  unsigned short val = 12352;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(hex_one_longer_width) {
  char str1[512];
  char str2[512];

  char *format = "%#2x";
  unsigned val = 1;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(hex_two_longer_width) {
  char str1[512];
  char str2[512];

  char *format = "%#30x";
  unsigned val = 1;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_long_g_to_string_precision_greater) {
  specifier params = {0};
  params.precision = 3;
  long double arg = 12345.6789;
  char *expected = "1.23e+04";
  char *actual = long_g_to_string(&params, arg);
  ck_assert_str_eq(actual, expected);
  free(actual);
}
END_TEST

START_TEST(test_long_g_to_string_precision_less) {
  specifier params = {0};
  params.precision = 7;
  long double arg = 12.3456789;
  char *expected = "12.3457";
  char *actual = long_g_to_string(&params, arg);
  ck_assert_str_eq(actual, expected);
  free(actual);
}
END_TEST

START_TEST(test_long_g_to_string_precision_equal) {
  specifier params = {0};
  params.precision = 5;
  long double arg = 123.456;
  char *expected = "123.46";
  char *actual = long_g_to_string(&params, arg);
  ck_assert_str_eq(actual, expected);
  free(actual);
}
END_TEST

START_TEST(test_long_e_to_string) {
  specifier params = {0};
  params.precision = 3;
  long double arg = 12345.6789;
  char *expected = "1.235e+04";
  char *actual = long_e_to_string(&params, arg);
  ck_assert_str_eq(actual, expected);
  free(actual);
}
END_TEST

START_TEST(test_long_float_to_string) {
  specifier params = {0};
  params.precision = 3;
  long double arg = 12.3456789;
  char *expected = "12.346";
  char *actual = long_float_to_string(&params, arg);
  ck_assert_str_eq(actual, expected);
  free(actual);
}
END_TEST

Suite *suite_sprintf(void) {
  Suite *s = suite_create("suite_sprintf");
  TCase *tc = tcase_create("sprintf_tests");

  // flags

  tcase_add_test(tc, test_minus);
  tcase_add_test(tc, test_space);
  tcase_add_test(tc, test_plus);
  tcase_add_test(tc, test_hash);
  tcase_add_test(tc, test_zero);

  // precision
  tcase_add_test(tc, test_precision_integer);
  tcase_add_test(tc, test_precision_integer_negative);
  tcase_add_test(tc, test_precision_string);
  tcase_add_test(tc, test_precision_float);
  tcase_add_test(tc, test_precision_exponential);
  tcase_add_test(tc, test_precision_unsigned);
  tcase_add_test(tc, test_precision_hex);
  tcase_add_test(tc, test_precision_octal);

  // precision_star
  tcase_add_test(tc, test_precision_integer_star);
  tcase_add_test(tc, test_precision_string_star);
  tcase_add_test(tc, test_precision_float_star);
  tcase_add_test(tc, test_precision_exponential_star);
  tcase_add_test(tc, test_precision_unsigned_star);
  tcase_add_test(tc, test_precision_hex_star);
  tcase_add_test(tc, test_precision_octal_star);

  // precision_zero_star
  tcase_add_test(tc, star_zero_i);
  tcase_add_test(tc, zero_star_ld);

  // spets

  tcase_add_test(tc, test_c);
  tcase_add_test(tc, test_d);
  tcase_add_test(tc, test_i);
  tcase_add_test(tc, test_e);
  tcase_add_test(tc, test_E);
  tcase_add_test(tc, test_f);

  // g

  tcase_add_test(tc, test_g_6);
  tcase_add_test(tc, test_g_1);
  tcase_add_test(tc, test_g_2);
  tcase_add_test(tc, test_g_3);
  tcase_add_test(tc, test_g_4);
  tcase_add_test(tc, test_g_7);
  tcase_add_test(tc, test_g_8);
  tcase_add_test(tc, test_g_9);

  tcase_add_test(tc, test_G);
  tcase_add_test(tc, test_o);
  tcase_add_test(tc, test_x);
  tcase_add_test(tc, test_X);
  tcase_add_test(tc, test_s);
  tcase_add_test(tc, test_u);
  tcase_add_test(tc, test_p);
  tcase_add_test(tc, test_n);
  tcase_add_test(tc, test_percent);

  // width

  tcase_add_test(tc, test_width_integer);
  tcase_add_test(tc, test_width_integer_negative);
  tcase_add_test(tc, test_width_string);
  tcase_add_test(tc, test_width_char);
  tcase_add_test(tc, test_width_float);
  tcase_add_test(tc, test_width_exponential);
  tcase_add_test(tc, test_width_unsigned);
  tcase_add_test(tc, test_width_hex);
  tcase_add_test(tc, test_width_octal);

  // width_star

  tcase_add_test(tc, test_width_integer_star);

  tcase_add_test(tc, basic);
  tcase_add_test(tc, test_float);
  tcase_add_test(tc, test_long_f);

  // string
  tcase_add_test(tc, test_string);
  tcase_add_test(tc, test_string_and_num);
  tcase_add_test(tc, test_string_begin_multiple);
  tcase_add_test(tc, test_string_question);
  tcase_add_test(tc, test_string_question_2);
  tcase_add_test(tc, test_string_question_multiple);

  tcase_add_test(tc, multiple_numues);
  tcase_add_test(tc, test_width_precision);
  tcase_add_test(tc, test_padding);
  tcase_add_test(tc, test_hexadecimal);
  tcase_add_test(tc, test_octal);
  tcase_add_test(tc, test_unsigned);

  // lenght

  tcase_add_test(tc, test_length_h);
  // tcase_add_test(tc, test_length_hh);
  tcase_add_test(tc, test_length_l);
  // tcase_add_test(tc, test_length_ll);
  tcase_add_test(tc, test_length_l_float);

  // hex

  tcase_add_test(tc, test_one_hex_lower);
  tcase_add_test(tc, test_hex_upper);
  tcase_add_test(tc, test_padding_hex);
  tcase_add_test(tc, test_one_hex_lower_with_alignment_left);
  tcase_add_test(tc, test_one_hex_lower_with_alignment_right);

  // octal
  tcase_add_test(tc, octal);
  tcase_add_test(tc, octal_width);
  tcase_add_test(tc, octal_flags);
  tcase_add_test(tc, octal_precision);
  tcase_add_test(tc, octal_many_flags);
  tcase_add_test(tc, octal_short);
  tcase_add_test(tc, octal_long);
  tcase_add_test(tc, octal_many);
  tcase_add_test(tc, octal_zero);
  tcase_add_test(tc, octal_hash);

  // unsigned val
  tcase_add_test(tc, unsigned_val);
  tcase_add_test(tc, unsigned_val_width);
  tcase_add_test(tc, unsigned_val_precision);
  tcase_add_test(tc, unsigned_val_short);

  // hex
  tcase_add_test(tc, hex_width);
  tcase_add_test(tc, hex_flags);
  tcase_add_test(tc, hex_precision);
  tcase_add_test(tc, hex_many);
  tcase_add_test(tc, hex_many_flags);
  tcase_add_test(tc, hex_zero);
  tcase_add_test(tc, hex_huge);
  tcase_add_test(tc, hex_short);
  tcase_add_test(tc, hex_one_longer_width);
  tcase_add_test(tc, hex_two_longer_width);

  // e

  tcase_add_test(tc, test_long_g_to_string_precision_greater);
  tcase_add_test(tc, test_long_g_to_string_precision_less);
  tcase_add_test(tc, test_long_g_to_string_precision_equal);
  tcase_add_test(tc, test_long_e_to_string);
  tcase_add_test(tc, test_long_float_to_string);

  suite_add_tcase(s, tc);
  return s;
}