#include "sprintf.h"


int main(){
    char* str = calloc(512, sizeof(char));
    char* str2 = calloc(512, sizeof(char));
    int a = 12;
    int* b = &a;
    int res = s21_sprintf(str, "hello, my age is: %o what's yours?", 372);
    // printf(": %p\n", b);
    printf("\nRESULT: %s\n", str);
    int res2 = sprintf(str2, "hello, my age is: %o what's yours?", 372);
    printf("\nRESULT: %s\n", str2);
    free(str);
    free(str2);
    return 0;
}

int s21_sprintf(char *str, const char *format, ...) {
    va_list args;
    va_start(args, format);
    int res = 0;
    size_t index = 0;
    int format_idx = 0;
    specifier params = {
        0,
        0,
        0,
        0,
        0
    };
    char* specifier_string;
    printf("len: %ld\n", strlen(format));
    while (format_idx != strlen(format) - 1) {
        reset_params(&params);
        
        if (format[format_idx] != '%') {
            str[index] = format[format_idx];
            index++;
            if (format_idx + 1 < strlen(format)) format_idx++;
        } else {
            if (format_idx + 1 < strlen(format)) format_idx++;
            // if (va_arg(args, void*) == NULL) {
            //     fprintf(stderr, "Not enough arguments given");
            //     res = 1;
            //     break;
            // }
            specifier_string = specifier_reader(format, &params, &args, &format_idx);
            strcat(str, specifier_string);
            index += strlen(specifier_string);
            if(NULL != specifier_string) free(specifier_string);
            // if (format_idx + 1 <= strlen(format)) format_idx++;
        }
    }
    va_end(args);
    if (!res) {
        res = strlen(str);
    }
    return res;
}

char* specifier_reader(const char *format, specifier* params, va_list *args, int* format_idx) {
    char* string = calloc(512, sizeof(char));
    params->flag = read_flags(format, format_idx);
    params->width = read_width(format, format_idx);
    params->precision = read_precision(format, format_idx);
    params->length = read_length(format, format_idx);
    params->type = read_type(format, format_idx);
    printf("Flag: %c\nprecision: %d\nwidth: %d\ntype: %c\nlength: %c\n", params->flag, params->precision, params->width, params->type, params->length);
    string = apply_params(params, args, string, *format_idx);
    return string;
}

char* apply_params(specifier *params, va_list *args, char* string, int index) {
    char *buff = calloc(512, sizeof(char));
    apply_width(params, string);
    switch(params->type){
        case 'c':
            char symbol = va_arg(*args, int);
            buff[0] = symbol;
            break;
        case 'd':
            int decimal = va_arg(*args, int);
            int_to_string(buff, decimal);
            break;
        case 'i':
            int decimal_i = va_arg(*args, int);
            int_to_string(buff, decimal_i);
            break;
        // case 'e':
        //     int decimal = va_arg(*args, int);
        //     int_to_string(buff, decimal);
        //     break;
        // case 'E':
        //     int decimal = va_arg(*args, int);
        //     int_to_string(buff, decimal);
        //     break;
        case 'f':
            float float_num = va_arg(*args, double);
            gcvt(float_num, 6, buff);
            break;
        case 'g':
            float float_num_g = va_arg(*args, double);
            gcvt(float_num_g, 6, buff);
            break;
        case 'G':
            float float_num_G = va_arg(*args, double);
            gcvt(float_num_G, 6, buff);
            break;
        case 'o':
            void* octal_str = va_arg(*args, void*);
            octal_to_str(buff, octal_str);
            break;
        case 's':
            char* str = va_arg(*args, char*);
            if (buff != NULL) strcpy(buff, str);
            break;
        case 'u':
            int decimal_u = (int)va_arg(*args, size_t);
            int_to_string(buff, decimal_u);
            break;
        // case 'x':
        //     void* hex_str = va_arg(*args, void*);
        //     hex_to_str(buff, hex_str);
        //     break;
        // case 'X':
        //     char* str = va_arg(*args, char*);
        //     if (buff != NULL) strcpy(buff, str);
        //     break;
        case 'p':
            void* hex_str = va_arg(*args, void*);
            hex_to_str(buff, hex_str);
            break;
        case 'n':
            int_to_string(buff, index+1);
            break;
        case '%':
            buff[0] = '%';
            break;
        // case 'ld':
        //     int i = va_arg(*args, size_t);
        //     int_to_string(buff, i);
        //     break;
    }
    // string = apply_flags;
    // string = apply_width;
    // string = apply_length;
    // string = apply_precision;
    strcat(string, buff);
    if (NULL != buff) free(buff);
    return string;
}

int read_width(const char *format, int* index) {
    int res = 0;
    char *string = calloc(512, sizeof(char));
    int idx = 0;
    while (format[*index] < 58 && format[*index] > 47) {
        string[idx] = format[*index];
        idx++;
        if (*index + 1 < strlen(format)) *index = *index + 1;
    }
    res = string_to_int(string);
    free(string);
    return res;
}

char read_length(const char *format, int* index) {
    char res = 0;
    if (is_length(format[*index])) {
        res = format[*index];
        if (*index + 1 < strlen(format)) *index = *index + 1;
    }
    return res;
}

int read_precision(const char *format, int* index) {
    int res = 0;
    int idx = 0;
    if (format[*index] == '.'){
        *index = *index + 1;
        while (format[*index] < 58 && format[*index] > 47) {
            if (idx != 0) res *= 10;
            res += format[*index] - 48;
            if (*index + 1 < strlen(format)) *index = *index + 1;
            idx++;
        }
    }
    return res;
}

char read_flags(const char *format, int* index) {
    char res = 0;
    if (is_flag(format[*index])) {
        res = format[*index];
        if (*index + 1 < strlen(format)) *index = *index + 1;
    }
    return res;
}

char read_type(const char *format, int *index) {
    char res = 0;
    for (int i = 0; i < specifier_amount; i++) {
        if (format[*index] == specifiers_list[i]) {
            res = specifiers_list[i];
            if (*index + 1 < strlen(format)) *index = *index + 1;
            break;
        }
    } 
    return res;
}

int string_to_int(char* string) {
    int index = 0;
    int res = 0;
    while (*string < 58 && *string > 47) {
        if (index != 0) res *= 10;
        res += *string - 48;
        string++;
        index++;
    }
    return res;
}

void int_to_string(char* buff, int arg){
    int len = floor(log10(arg));
    buff[len + 1] = '\0';
    while(len >= 0 || arg != 0) {
        buff[len] = (arg % 10) + '0';
        arg = arg / 10;
        len--;
    }
}

void hex_to_str(char* buff, void* num) {
    char* str = calloc(512, sizeof(char));
    unsigned long *hex_num = (unsigned long *)num;
    unsigned long value = (unsigned long) hex_num;
    const char *hex_chars = "0123456789abcdef";
    
    strcat(str, "0x");
    if (hex_num == 0) {
        strcat(str, "0");
        str[3] = '\0';
    } else {
        unsigned long temp = value;
        size_t index = 13;
        str[index+1] = '\0';
        while (temp != 0) {
            str[index] = hex_chars[temp % 16];
            temp /= 16;
            index--;
        }
    }
    strcpy(buff, str);
    free(str);
}

void octal_to_str(char* buff, void* num) {
    char* str = calloc(512, sizeof(char));
    int *hex_num = (int *)num;
    int value = (unsigned long) hex_num;
    const char *hex_chars = "0123456789abcdef";
    
    if (hex_num == 0) {
        strcat(str, "0");
        str[2] = '\0';
    } else {
        int temp = value;
        size_t index = get_octal_len(temp) - 1;
        str[index + 1] = '\0';
        while (temp != 0) {
            str[index] = hex_chars[temp % 8];
            temp /= 8;
            index--;
        }
    }
    strcpy(buff, str);
    free(str);
}

size_t get_octal_len(int value) {
    size_t res = 0;
    while (value != 0) {
        value /= 8;
        res++;
    }
    return res;
}

void float_to_string(char* buff, float arg){
    // buff[len + 1] = '\0';
    // while(1) {
    //     buff[len] = (arg % 10) + '0';
    //     arg = arg / 10;
    //     len--;
    //     if (arg == 0) break;
    // }
}

int char_to_int(char arg) {
    int res = 0 + arg;
    return res;
}

int is_flag(char letter) {
    return letter == '#' || letter == '-' || letter == '+' || letter == ' ' || letter == '0';
}

int is_length(char letter) {
    return letter == 'l' || letter == 'h' || letter == 'L';
}

void reset_params(specifier* params) {
    params->type = 0;
    params->flag = 0;
    params->width = 0;
    params->precision = 0;
    params->length = 0;
}

void apply_width(specifier* params, char* string) {
    char * width_buff = calloc(512, sizeof(char));
    if (params->width > 0) {
        for (int i = 0; i < params->width; i++) {
            strcat(string, " ");
            // width_buff[i] == ' ';
            // if (i == params->width - 1){
            //     width_buff[i + 1] = '\0';
            // }
        }
        // printf("Width buff: %s\n", width_buff);
        // strcat(string, width_buff);
    }
    free(width_buff);
}