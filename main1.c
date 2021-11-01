/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 17:22:34 by fabet             #+#    #+#             */
/*   Updated: 2021/11/01 18:20:37 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

#define ANSI_COLOR_GREEN	"\x1b[32m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"

void	printresult(int libcresult, int myresult, int test)
{
	printf(ANSI_COLOR_YELLOW "Compare output!\n" ANSI_COLOR_RESET);
	if (libcresult == myresult)
	{
		printf(ANSI_COLOR_GREEN "Bytes output test %d: %s\n\n" ANSI_COLOR_RESET, test, "OK");
	}
	else
	{
		printf(ANSI_COLOR_RED "Bytes output test %d: %s (%d != %d)\n\n" ANSI_COLOR_RESET, test, "KO", libcresult, myresult);
	}
}

int	main()
{
	int	libcresult;
	int	myresult;
	int	test;

	test = 1;
	libcresult = printf("%c\n", 'a');
	myresult = ft_printf("%c\n", 'a');
	printresult(libcresult, myresult, test);

	test = 2;
	libcresult = printf("char is '%c'\n", 'a');
	myresult = ft_printf("char is '%c'\n", 'a');
	printresult(libcresult, myresult, test);

	test = 3;
	libcresult = printf("chars are '%c' and '%c'\n", 'a', 'b');
	myresult = ft_printf("chars are '%c' and '%c'\n", 'a', 'b');
	printresult(libcresult, myresult, test);

	test = 4;
	libcresult = printf("%s\n", "Hello world");
	myresult = ft_printf("%s\n", "Hello world");
	printresult(libcresult, myresult, test);

	test = 5;
	libcresult = printf("%s %s\n", "Bye", "world");
	myresult = ft_printf("%s %s\n", "Bye", "world");
	printresult(libcresult, myresult, test);


	test = 6;
	libcresult = printf("%s %s\n", "Empty", "");
	myresult = ft_printf("%s %s\n", "Empty", "");
	printresult(libcresult, myresult, test);

	test = 7;
	libcresult = printf("%s", "");
	myresult = ft_printf("%s", "");
	printresult(libcresult, myresult, test);

	test = 8;
	libcresult = printf("ltalia is%s, oops!\n", " cheater");
	myresult = ft_printf("ltalia is%s, oops!\n", " cheater");
	printresult(libcresult, myresult, test);

	test = 9;
	libcresult = printf("NULL test: %s\n", NULL);
	myresult = ft_printf("NULL test: %s\n", NULL);
	printresult(libcresult, myresult, test);

	test = 10;
	libcresult = printf("%p\n", &test);
	myresult = ft_printf("%p\n", &test);
	printresult(libcresult, myresult, test);

	test = 11;
	libcresult = printf("%p\n", NULL);
	myresult = ft_printf("%p\n", NULL);
	printresult(libcresult, myresult, test);

	test = 11;
	libcresult = printf("test: %p, libcresult: %p, myresult: %p\n", &test, &libcresult, &myresult);
	myresult = ft_printf("test: %p, libcresult: %p, myresult: %p\n", &test, &libcresult, &myresult);
	printresult(libcresult, myresult, test);

	test = 12;
	void	*ptr1 = malloc(10000);
	libcresult = printf("%p\n", ptr1);
	myresult = ft_printf("%p\n", ptr1);
	free(ptr1);
	printresult(libcresult, myresult, test);

	test = 13;
	char	********ptr2 = malloc(10000);
	libcresult = printf("%p\n", ptr2);
	myresult = ft_printf("%p\n", ptr2);
	free(ptr2);
	printresult(libcresult, myresult, test);

	test = 14;
	libcresult = printf("%d\n", 0);
	myresult = ft_printf("%d\n", 0);
	printresult(libcresult, myresult, test);

	test = 15;
	libcresult = printf("%d\n", 2147483647);
	myresult = ft_printf("%d\n", 2147483647);
	printresult(libcresult, myresult, test);

	test = 16;
	libcresult = printf("%d\n", -2147483648);
	myresult = ft_printf("%d\n", -2147483648);
	printresult(libcresult, myresult, test);

	test = 17;
	libcresult = printf("%d\n", 100);
	myresult = ft_printf("%d\n", 100);
	printresult(libcresult, myresult, test);

	test = 18;
	libcresult = printf("%d\n", -100);
	myresult = ft_printf("%d\n", -100);
	printresult(libcresult, myresult, test);

	test = 19;
	libcresult = printf("%d\n", -100100);
	myresult = ft_printf("%d\n", -100100);
	printresult(libcresult, myresult, test);

	test = 20;
	libcresult = printf("%u\n", 0);
	myresult = ft_printf("%u\n", 0);
	printresult(libcresult, myresult, test);

	test = 21;
	libcresult = printf("%u\n", 2147483647);
	myresult = ft_printf("%u\n", 2147483647);
	printresult(libcresult, myresult, test);

	test = 22;
	libcresult = printf("%u\n", -2147483648);
	myresult = ft_printf("%u\n", -2147483648);
	printresult(libcresult, myresult, test);

	test = 23;
	libcresult = printf("%u\n", 100);
	myresult = ft_printf("%u\n", 100);
	printresult(libcresult, myresult, test);

	test = 24;
	libcresult = printf("%u\n", -100);
	myresult = ft_printf("%u\n", -100);
	printresult(libcresult, myresult, test);

	test = 25;
	libcresult = printf("%u\n", -100100);
	myresult = ft_printf("%u\n", -100100);
	printresult(libcresult, myresult, test);

	test = 26;
	libcresult = printf("%u\n", 4294967295);
	myresult = ft_printf("%u\n", 4294967295);
	printresult(libcresult, myresult, test);

	test = 27;
	libcresult = printf("%x\n", 0);
	myresult = ft_printf("%x\n", 0);
	printresult(libcresult, myresult, test);

	test = 28;
	libcresult = printf("%x\n", 2147483647);
	myresult = ft_printf("%x\n", 2147483647);
	printresult(libcresult, myresult, test);

	test = 29;
	libcresult = printf("%x\n", -2147483648);
	myresult = ft_printf("%x\n", -2147483648);
	printresult(libcresult, myresult, test);

	test = 30;
	libcresult = printf("%x\n", 100);
	myresult = ft_printf("%x\n", 100);
	printresult(libcresult, myresult, test);

	test = 31;
	libcresult = printf("%x\n", -100);
	myresult = ft_printf("%x\n", -100);
	printresult(libcresult, myresult, test);

	test = 32;
	libcresult = printf("%x\n", -100100);
	myresult = ft_printf("%x\n", -100100);
	printresult(libcresult, myresult, test);

	test = 33;
	libcresult = printf("%X\n", 0);
	myresult = ft_printf("%X\n", 0);
	printresult(libcresult, myresult, test);

	test = 34;
	libcresult = printf("%X\n", 2147483647);
	myresult = ft_printf("%X\n", 2147483647);
	printresult(libcresult, myresult, test);

	test = 35;
	libcresult = printf("%X\n", -2147483648);
	myresult = ft_printf("%X\n", -2147483648);
	printresult(libcresult, myresult, test);

	test = 36;
	libcresult = printf("%X\n", 100);
	myresult = ft_printf("%X\n", 100);
	printresult(libcresult, myresult, test);

	test = 37;
	libcresult = printf("%X\n", -100);
	myresult = ft_printf("%X\n", -100);
	printresult(libcresult, myresult, test);

	test = 38;
	libcresult = printf("%X\n", -100100);
	myresult = ft_printf("%X\n", -100100);
	printresult(libcresult, myresult, test);

	test = 39;
	libcresult = printf("21 %%\n");
	myresult = ft_printf("21 %%\n");
	printresult(libcresult, myresult, test);

	test = 40;
	libcresult = printf("%%%%%%%%%%\n");
	myresult = ft_printf("%%%%%%%%%%\n");
	printresult(libcresult, myresult, test);

	test = 41;
	libcresult = printf("%% - %c - %s - %p - %d - %i - %u - %x - %X\n", 'c', "string", &test, 1234, 14535, 124534, 6343, 24368);
	myresult = ft_printf("%% - %c - %s - %p - %d - %i - %u - %x - %X\n", 'c', "string", &test, 1234, 14535, 124534, 6343, 24368);
	printresult(libcresult, myresult, test);

	test = 42;
	libcresult = printf("%%%c%s%p%d%i%u%x%X\n", 'c', "string", &test, 1234, 14535, 124534, 6343, 24368);
	myresult = ft_printf("%%%c%s%p%d%i%u%x%X\n", 'c', "string", &test, 1234, 14535, 124534, 6343, 24368);
	printresult(libcresult, myresult, test);

	test = 43;
	libcresult = printf("%%\n%c\n%s\n%p\n%d\n%i\n%u\n%x\n%X\n", 'c', "string", &test, 1234, 14535, 124534, 6343, 24368);
	myresult = ft_printf("%%\n%c\n%s\n%p\n%d\n%i\n%u\n%x\n%X\n", 'c', "string", &test, 1234, 14535, 124534, 6343, 24368);
	printresult(libcresult, myresult, test);

	test = 44;
	libcresult = printf("%p\n", (void *)-1);
	myresult = ft_printf("%p\n", (void *)-1);
	printresult(libcresult, myresult, test);

	test = 45;
	libcresult = printf("Hello, this char %c is null\n", 0);
	myresult = ft_printf("Hello, this char %c is null\n", 0);
	printresult(libcresult, myresult, test);

	test = 46;
	libcresult = printf("number: %d, char: %c, number %d\n", 42, 0, 42);
	myresult = ft_printf("number: %d, char: %c, number %d\n", 42, 0, 42);
	printresult(libcresult, myresult, test);

	test = 47;
	libcresult = printf("%c%c\n", 42, 41);
	myresult = ft_printf("%c%c\n", 42, 41);
	printresult(libcresult, myresult, test);

	test = 48;
	libcresult = printf("%%%cc\n", 42);
	myresult = ft_printf("%%%cc\n", 42);
	printresult(libcresult, myresult, test);

	// test = 48;
	// while(1)
	// {
	// 	libcresult = printf("char %c\n", 0);
	// 	myresult = ft_printf("char %c\n", 0);
	// 	printresult(libcresult, myresult, test);
	// }

	return (0);
}
