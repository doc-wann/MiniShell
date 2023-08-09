/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:31:09 by hdaniele          #+#    #+#             */
/*   Updated: 2023/07/20 17:17:29 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_strcmp(const char *str1, const char *str2)
{
	size_t	i;

	i = 0;
	while ((str1[i]) && (str2[i]))
	{
		if (str1[i] != str2[i])
			break ;
		i++;
	}
	return ((const unsigned char)str1[i] - (const unsigned char)str2[i]);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 == *s2 && *s2 != '\0' && n > 0)
	{
		++s1;
		++s2;
		--n;
	}
	if (*s1 == *s2 || n == 0)
		return (0);
	if (*(unsigned char *)s1 < *(unsigned char *)s2)
		return (-1);
	return (1);
}

//int	main(void)
//{
//	char	var1[10] = {"test\201"};
//	char	var2[10] = {"test\0"};
//	printf("MEU STRNCMP: \n");
//	printf("%i", ft_strncmp(var1, var2, 6));
//	printf("\n STRNCMP ORIGINAL: \n");
//	printf("%i", strncmp(var1, var2, 6));
//	printf("\n");
//}
