/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-cha <mben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 23:11:24 by mohkhald          #+#    #+#             */
/*   Updated: 2026/01/07 21:06:43 by mben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static bool	ft_check_textu_dir(char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (true);
	if (ft_strncmp(line, "SO ", 3) == 0)
		return (true);
	if (ft_strncmp(line, "WE ", 3) == 0)
		return (true);
	if (ft_strncmp(line, "EA ", 3) == 0)
		return (true);
	return (false);
}

bool	ft_is_texture_line(char *line)
{
	char	*new_line;

	if (!line || ft_strlen(line) < 3)
		return (false);
	new_line = ft_skip_space(line);
	if (!new_line)
		return (false);
	return (ft_check_textu_dir(new_line));
}

char	*ft_extract_path(char *line)
{
	char	*new_line;

	if (!line || ft_strlen(line) < 3)
		return (NULL);
	line += 2;
	new_line = ft_strtrim(line, " \t\n");
	return (new_line);
}

bool	ft_is_valid_path(char *line)
{
	char	*exten;
	int		fd;

	if (!line)
		return (false);
	exten = ft_strrchr(line, '.');
	if (!exten || (ft_strcmp(exten, ".xpm") != 0 && ft_strcmp(exten,
				".png") != 0))
		return (false);
	fd = open(line, O_RDONLY);
	if (fd < 0)
		return (false);
	close(fd);
	return (true);
}
