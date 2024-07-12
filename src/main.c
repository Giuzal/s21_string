#include "includes/s21_tests.h"

int main(void) {
  run_tests();
  return 0;
}

void run_test_suite(Suite *test_suite) {
  static int number_of_test = 1;

  printf("\nRunning Test Suite: %d\n", number_of_test++);

  SRunner *sr = srunner_create(test_suite);
  if (sr != NULL) {
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);
    srunner_free(sr);
  } else {
    fprintf(stderr, "Failed to create test suite runner\n");
  }
}

void run_tests(void) {
  Suite *test_suite_array[] = {
      suite_memchr(),   suite_memcmp(),  suite_memcpy(),   suite_memset(),
      suite_strcat(),   suite_strncat(), suite_strchr(),   suite_strcmp(),
      suite_strncmp(),  suite_strcpy(),  suite_strncpy(),  suite_strcspn(),
      suite_strerror(), suite_strlen(),  suite_strpbrk(),  suite_strrchr(),
      suite_strspn(),   suite_insert(),  suite_to_lower(), suite_to_upper(),
      suite_trim(),     suite_strtok(),  suite_sprintf(),  NULL};

  if (test_suite_array[0] == NULL) {
    printf("Test suite array is empty\n");
    return;
  }

  for (int i = 0; test_suite_array[i] != NULL; i++) {
    run_test_suite(test_suite_array[i]);
  }
}