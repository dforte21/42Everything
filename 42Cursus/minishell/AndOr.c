#include "minishell.h"

int	checkMltCmd(t_comms *comms, int i)
{
	int	end;

	end = i;
	comms->cmdflag = 0;
	while (comms->line[end])
	{
		end = ft_skip_quotes(comms->line, end, '\"');
		end = ft_skip_quotes(comms->line, end, '\'');
		if (comms->line[end] == '&' || ft_strncmp(&comms->line[end], "||", 2) == 0)
		{
			if (comms->line[end] == '&')
				comms->cmdflag = 1;
			if (comms->line[end] == '|')
				comms->cmdflag = 2;
			break ;
		}
		end++;
	}
	while (comms->line[end] && (comms->line[end] == '&' || comms->line[end] == '|'))
		end++;
	comms->cmd = ft_substr(comms->line, i, end - i);
	comms->cmd = ft_strtrim(comms->cmd, "&&");
	return (end);
}

int	checkFlag(t_comms *comms)
{
	if (comms->cmdflag == 1 && g_exit_status != 0)
		return (0);
	else if (comms->cmdflag == 2 && g_exit_status == 0)
		return (0);
	return (1);
}
