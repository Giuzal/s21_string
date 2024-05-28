#include "includes/s21_tests.h"

int main(void) {
    run_tests();
    return 0;
}

void run_test_suite(Suite *test_suite) {
    static int counter = 1;

    if (counter > 1)
        putchar('\n');
    printf("%s%d%s", "CURRENT TEST SUITE: ", counter, "\n");
    counter++;

    SRunner *sr = srunner_create(test_suite);
    if (sr != NULL) {
        srunner_set_fork_status(sr, CK_NOFORK);
        srunner_run_all(sr, CK_NORMAL);
        srunner_free(sr);
    } else {
        fprintf(stderr, "Error creating SRunner\n");
    }
}

void run_tests(void) {
    Suite *list_test_suites[] = {
        //suite_memchr(),   suite_memcmp(),   suite_memcpy(),
       // suite_memmove(),  suite_memset(),   
        suite_strcat(), suite_strlen(), suite_strncat(),  
        // suite_strchr(),   suite_strcmp(),
        // suite_strncmp(),  suite_strcpy(),   suite_strncpy(),
        // suite_strcspn(),  suite_strerror(), 
        // suite_strpbrk(),  suite_strrchr(),  suite_strspn(),
        // suite_strstr(),   suite_insert(),   suite_to_lower(),
        // suite_to_upper(), suite_trim(),     suite_strtok(),
        // suite_sprintf(),  suite_atoi(),     suite_strntollu(),
        // suite_strtold(),  suite_sscanf(),   
        NULL};

    for (Suite **current_test_suite = list_test_suites; *current_test_suite != NULL;
         current_test_suite++) {
        run_test_suite(*current_test_suite);
    }
}
