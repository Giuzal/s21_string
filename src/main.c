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
        suite_strcat(), suite_strlen(), suite_strncat(),  
        suite_strcpy(), suite_strncpy(), suite_strtok(),
        suite_strpbrk(), suite_strchr(), suite_strspn(),
        suite_to_upper(), suite_to_lower(),
        NULL
    };

    if (test_suite_array[0] == NULL) {
        printf("Test suite array is empty\n");
        return;
    }

    for (int i = 0; test_suite_array[i] != NULL; i++) {
        run_test_suite(test_suite_array[i]);
    }
}