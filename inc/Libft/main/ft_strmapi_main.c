int main()
{
    char *str1 = "hello";
    char *str2 = "42";
    char *str3 = "";
    char *str4 = "uppercaseshouldnotchange";
    char *result;

    // Test 1: Normal case, applying to_upper to "hello"
    result = ft_strmapi(str1, to_upper);
    printf("Original: %s, Transformed: %s\n", str1, result);
    free(result);

    // Test 2: Edge case with numeric string, "42"
    result = ft_strmapi(str2, to_upper);
    printf("Original: %s, Transformed: %s\n", str2, result);
    free(result);

    // Test 3: Edge case with empty string
    result = ft_strmapi(str3, to_upper);
    printf("Original: %s, Transformed: %s\n", str3, result);
    free(result);

    // Test 4: Edge case with all lowercase letters, should convert them to uppercase
    result = ft_strmapi(str4, to_upper);
    printf("Original: %s, Transformed: %s\n", str4, result);
    free(result);

    return 0;
}
