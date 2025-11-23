#include "cub.h"

static	ft_valid_char(t_config *config)
{
}

bool	ft_valid_map(t_config *config)
{
	if (!config || !config->map.grid)
		return (false);
	if (!ft_valid_char(&config->map))
		return (false);
}
